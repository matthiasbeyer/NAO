#include "colorDetection.hpp"

using namespace naocv;

int                 H_MIN                  = 0;
int                 H_MAX                  = 256;
int                 S_MIN                  = 0;
int                 S_MAX                  = 256;
int                 V_MIN                  = 0;
int                 V_MAX                  = 256;
const int           FRAME_WIDTH            = 640;
const int           FRAME_HEIGHT           = 480;
const int           MAX_NUM_OBJECTS        = 50;
const int           MIN_OBJECT_AREA        = 20 * 20;
const int           MAX_OBJECT_AREA        =  FRAME_HEIGHT *  FRAME_WIDTH / 1.5;
const std::string   windowName             = "Original Image";
const std::string   windowName1            = "HSV Image";
const std::string   windowName2            = "Thresholded Image";
const std::string   windowName3            = "After Morphological Operations";
const std::string   trackbarWindowName     = "Trackbars";
const int           const  max_lowThreshold = 100;
const int           ratio                  = 3;
const int           kernel_size            = 3;
const char*         window_name            = "Edge Map";
const int           edgeThresh             = 1;

int                                         lowThreshold;
cv::Mat                                     dst;
cv::Mat                                     detected_edges;
cv::Mat                                     src;
cv::Mat                                     src_gray;
      
std::vector<std::shared_ptr<FarbPos>>       farblist;

/*
 *
 * Methods
 *
 */

void saveColorPos(std::string s, int yPos, int size) {
    auto fp = std::make_shared<FarbPos>(s, yPos, size);
    farblist.push_back(fp);
}

FarbPos getTopColor() {
    FarbPos result;

    if(!farblist.empty()){
        result = *farblist.at(0);

        //Nach geringstem yPos-Wert 
        /*
        for (int i = 0; i < farblist.size(); i++) {
            if (farblist.at(i)->yPos < result.yPos) {
                result = *farblist.at(i);
            }
        }*/

        //Nach größter Fläche
        for (int i = 0; i < farblist.size(); i++) {
            if (farblist.at(i)->size > result.size) {
                result = *farblist.at(i);
            }
        }
    }


    // TODO : What if color is not found?
    return result;
}

void drawObject(std::vector<Objekte> theObjects,
                cv::Mat &frame,
                cv::Mat &temp,
                std::vector<std::vector<cv::Point>> contours,
                std::vector<cv::Vec4i> hierarchy)
{    
    for (int i = 0; i < theObjects.size(); i++) {
        
        int size = 0;
        for(int ic = 0; ic < contours.size(); ic++){
            if(size < contours.at(i).size()) size = contours.at(i).size();
        }
        auto type = theObjects.at(i).getType();
        auto ypos = theObjects.at(i).getYPos();
        saveColorPos(type, ypos, size);

        cv::drawContours(frame,
                         contours,
                         i,
                         theObjects.at(i).getColor(),
                         3,
                         8,
                         hierarchy);

        cv::circle(frame,
                   cv::Point(theObjects.at(i).getXPos(),
                   theObjects.at(i).getYPos()),
                   5,
                   theObjects.at(i).getColor());

        cv::putText(frame,
                    intTostring(theObjects.at(i).getXPos()) +
                    " , " +
                    intTostring(theObjects.at(i).getYPos()),
                    cv::Point(theObjects.at(i).getXPos(),
                              theObjects.at(i).getYPos() + 20),
                    1,
                    1,
                    theObjects.at(i).getColor());

        cv::putText(frame,
                    theObjects.at(i).getType(),
                    cv::Point(theObjects.at(i).getXPos(),
                              theObjects.at(i).getYPos()-20),
                              1,
                              2,
                              theObjects.at(i).getColor()
                    );
    }
}

void morphOps(cv::Mat &thresh) {
    //create structuring element that will be used to "dilate" and "erode" image.
    //the element chosen here is a 3px by 3px rectangle
    cv::Mat erodeElement = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    //dilate with larger element so make sure object is nicely visible
    cv::Mat dilateElement = getStructuringElement(cv::MORPH_RECT, cv::Size(8, 8));

    cv::erode(thresh, thresh, erodeElement);
    cv::erode(thresh, thresh, erodeElement);

    cv::dilate(thresh, thresh, dilateElement);
    cv::dilate(thresh, thresh, dilateElement);
}


void trackFilteredObject(Objekte theObject,
                         cv::Mat threshold,
                         cv::Mat HSV,
                         cv::Mat &cameraFeed)
{
    std::vector <Objekte> objects;
    cv::Mat temp;
    threshold.copyTo(temp);

    //these two vectors needed for output of findContours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    //find contours of filtered image using openCV findContours function
    findContours(temp,  contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

    //use moments method to find our filtered object
    double refArea   = 0;
    bool objectFound = false;

    if (hierarchy.size() > 0) {
        int numObjects = hierarchy.size();

        //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
        if (numObjects < MAX_NUM_OBJECTS) {
            for (int index = 0; index >= 0; index = hierarchy[index][0]) {
                cv::Moments moment = moments((cv::Mat) contours[index]);
                double area = moment.m00;

                //if the area is less than 20 px by 20px then it is probably just noise
                //if the area is the same as the 3/2 of the image size, probably just a bad filter
                //we only want the object with the largest area so we safe a reference area each
                //iteration and compare it to the area in the next iteration.
                if (area > MIN_OBJECT_AREA) {
                    Objekte object;

                    object.setXPos(moment.m10 / area);
                    object.setYPos(moment.m01 / area);
                    object.setType(theObject.getType());
                    object.setColor(theObject.getColor());

                    objects.push_back(object);

                    objectFound = true;
                } else {
                    objectFound = false;
                }
            }

            //let user know you found an object
            if (objectFound == true) {
                //draw object location on screen
                drawObject(objects, cameraFeed, temp, contours, hierarchy);
            }

        } else {
            putText(cameraFeed,
                    "TOO MUCH NOISE! ADJUST FILTER",
                    cv::Point(0, 50),
                    1, 2, cv::Scalar(0, 0, 255), 2);
        }
    }
}

std::string naocv::intTostring(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void naocv::CannyThreshold(int, void*)
{
    /// Reduce noise with a kernel 3x3
    blur(src_gray, detected_edges, cv::Size(3,3));

    /// Canny detector
    cv::Canny(detected_edges, detected_edges, lowThreshold,
                lowThreshold *ratio, kernel_size);

    /// Using Canny's output as a mask, we display our result
    dst = cv::Scalar::all(0);

    src.copyTo(dst, detected_edges);
    imshow(window_name, dst);
}

void naocv::createTrackbars() {
    //create window for trackbars
    cv::namedWindow(trackbarWindowName, 0);

    //create memory to store trackbar name on window
    char TrackbarName[50];

    sprintf(TrackbarName, "H_MIN", H_MIN);
    sprintf(TrackbarName, "H_MAX", H_MAX);
    sprintf(TrackbarName, "S_MIN", S_MIN);
    sprintf(TrackbarName, "S_MAX", S_MAX);
    sprintf(TrackbarName, "V_MIN", V_MIN);
    sprintf(TrackbarName, "V_MAX", V_MAX);

    // create trackbars and insert them into window
    // 3 parameters are: the address of the variable that is changing when the
    // trackbar is moved(eg.H_LOW),
    // the max value the trackbar can move (eg. H_HIGH),
    // and the function that is called whenever the trackbar is
    // moved(eg. on_trackbar)
    //                                  ---->    ---->     ---->

    cv::createTrackbar("H_MIN", trackbarWindowName, &H_MIN, H_MAX);
    cv::createTrackbar("H_MAX", trackbarWindowName, &H_MAX, H_MAX);
    cv::createTrackbar("S_MIN", trackbarWindowName, &S_MIN, S_MAX);
    cv::createTrackbar("S_MAX", trackbarWindowName, &S_MAX, S_MAX);
    cv::createTrackbar("V_MIN", trackbarWindowName, &V_MIN, V_MAX);
    cv::createTrackbar("V_MAX", trackbarWindowName, &V_MAX, V_MAX);
}


Farbe naocv::colorDetection(const std::string& pathToFile,
        bool calibrationMode,
        bool videoMode)
{
    //Matrix to store each frame of the webcam feed
    cv::Mat         cameraFeed;
    cv::Mat         threshold;
    cv::Mat         HSV;
    int             value;
    int             fps = 1;

    cv::VideoCapture    capture; //video capture object to acquire webcam feed
    farblist.clear();

    if (calibrationMode){
        //create slider bars for HSV filtering
        createTrackbars();
    }

    if (videoMode){
        //open capture object at location zero (default location for webcam)
        capture.open(0);

        fps = 20;

        //set height and width of capture frame
        capture.set(CV_CAP_PROP_FRAME_WIDTH , FRAME_WIDTH);
        capture.set(CV_CAP_PROP_FRAME_HEIGHT, FRAME_HEIGHT);
    }

    //start an infinite loop where webcam feed is copied to cameraFeed matrix
    //all of our operations will be performed within this loop
    //cv::waitKey(1000);

    do {
        //store image to matrix (video)
        if (videoMode){
            capture.read(cameraFeed);
            src = cameraFeed;
        }

        //picture
        if(!videoMode){
            cameraFeed = cv::imread(pathToFile,1);
            src        = cameraFeed;
            if (!src.data) {
                throw std::runtime_error("Falscher Dateipfad");
            }
        }

        //convert frame from BGR to HSV colorspace
        cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);

        if (calibrationMode == true) {
            //set fps-rate
            fps = 30;

            // need to find the appropriate color range values
            // calibrationMode must be false

            // if in calibration mode, we track objects based on the HSV slider values.
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV,
                    cv::Scalar(H_MIN, S_MIN, V_MIN),
                    cv::Scalar(H_MAX, S_MAX, V_MAX),
                    threshold);

            morphOps(threshold);
            imshow(windowName2, threshold);
            imshow("bild1", src);

            //the folowing for canny edge detec
            /// Create a matrix of the same type and size as src (for dst)
            dst.create(src.size(), src.type());

            /// Convert the image to grayscale
            cvtColor(src, src_gray, CV_BGR2GRAY);

            /// Create a window
            cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);

            /// Create a Trackbar for user to enter threshold
            cv::createTrackbar("Min Threshold:",
                           window_name,
                           &lowThreshold,
                           max_lowThreshold,
                           CannyThreshold);

            /// Show the image
            //trackFilteredObject(threshold,HSV,cameraFeed);
        } else {
            //create some temp fruit objects so that
            //we can use their member functions/information
            //##### ADDING ONE COLOR in Objekte.cpp and FarbPos.hpp!
            Objekte blue("blue");
            Objekte yellow("yellow");
            Objekte red("red");
            Objekte red2("red2");
            Objekte green("green");
            Objekte greendark("greendark");
            Objekte cyan("cyan");
            Objekte magenta("magenta");

            //first find blue objects
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, blue.getHSVmin(), blue.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(blue, threshold, HSV, cameraFeed);

            //then yellows
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, yellow.getHSVmin(), yellow.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(yellow, threshold, HSV, cameraFeed);

            //then reds
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, red.getHSVmin(), red.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(red, threshold, HSV, cameraFeed);

            //then red2
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, red2.getHSVmin(), red2.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(red2, threshold, HSV, cameraFeed);

            //then greens
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, green.getHSVmin(), green.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(green, threshold, HSV, cameraFeed);

            //then dark greens
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, greendark.getHSVmin(), greendark.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(greendark, threshold, HSV, cameraFeed);

            //then cyan
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, cyan.getHSVmin(), cyan.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(cyan, threshold, HSV, cameraFeed);

            //then magenta
            cvtColor(cameraFeed, HSV, cv::COLOR_BGR2HSV);
            inRange(HSV, magenta.getHSVmin(), magenta.getHSVmax(), threshold);
            morphOps(threshold);
            trackFilteredObject(magenta, threshold, HSV, cameraFeed);

        }
        //show frames
        //imshow(windowName2, threshold);

        //TODO:Only for show!
        //imshow(windowName, cameraFeed);
        //cv::waitKey(0);

        //imshow(windowName1, HSV);

        //delay 30ms so that screen can refresh.
        //image will not appear without this waitKey() command

        if(!calibrationMode && farblist.size() != 0){
            //cout << "FARBE IST: " << getTopColor().yPos << endl;
            Farbe f = getTopColor();
            std::cout << "Wert: " << (int) f << std::endl;
        }
        else{
            std::cout << "CALI-MODE ON or EMPTY" << std::endl;
        }

        if(calibrationMode)cv::waitKey(fps);
    }while(calibrationMode);

    if(farblist.size() == 0)naocv::Farbe();

    return getTopColor();
}