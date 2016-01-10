#define _USE_MATH_DEFINES

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "colorDetection.hpp"

#include <iostream>
#include <vector>
#include <math.h>



//GLOBAL VARIABLES
int height;
int width;
cv::Point centerPoint;
const std::string outSrc("C:/naoqi/_workspace/_src/_out/out.jpg");

double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

int getColorAtRectangle(){
    int i = 0;
    i = naocv::colorDetection(outSrc);
    std::cout << i << std::endl;
    return i;
    //TODO: Show-only
    //cv::imshow("Fenster2", cut);
}

bool find_squares(cv::Mat& image, std::vector<std::vector<cv::Point>>& squares)
{
    int i = 0;
    i++;
    bool looprequest(false);
    // blur will enhance edge detection
    cv::Mat blurred(image);
    medianBlur(image, blurred, 9);

    cv::Mat gray0(blurred.size(), CV_8U), gray;
    std::vector<std::vector<cv::Point> > contours;

    // find squares in every color plane of the image
    for (int c = 0; c < 3; c++)
    {
        if(looprequest)break;
        int ch[] = {c, 0};
        mixChannels(&blurred, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        const int threshold_level = 25;
        for (int l = 11; l < threshold_level; l++)
        {
            if(looprequest)break;
            // Use Canny instead of zero threshold level!
            // Canny helps to catch squares with gradient shading
            if (l == 0)
            {
                Canny(gray0, gray, 10, 20, 3); // 

                // Dilate helps to remove potential holes between edge segments
                dilate(gray, gray, cv::Mat(), cv::Point(-1,-1));
            }
            else
            {
                    gray = gray0 >= (l+1) * 255 / threshold_level;
            }

            // Find contours and store them in a list
            findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);

            // Test contours
            std::vector<cv::Point> approx;
            for (size_t i = 0; i < contours.size(); i++)
            {
                if(looprequest)break;
                // approximate contour with accuracy proportional
                // to the contour perimeter
                approxPolyDP(cv::Mat(contours[i]), approx, arcLength(cv::Mat(contours[i]), true)*0.02, true);

                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if (approx.size() == 4 &&
                        fabs(contourArea(cv::Mat(approx))) > 1000 &&
                        isContourConvex(cv::Mat(approx)))
                {
                    double maxCosine = 0;
           
                    for (int j = 2; j < 5; j++)
                    {
                            double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                            maxCosine = MAX(maxCosine, cosine);
                    }
                    //Ignore too big rectangle
                    if (maxCosine < 1.5  && (approx[2].x - approx[0].x) < 200  && (approx[2].y - approx[0].y) < 200/* && approx[0].x > 300 && approx[1].x > 300 && approx[2].x > 300 && approx[3].x > 300*/) {
                            /*squares.push_back(approx);

                            looprequest = false;*/
                        cv::Mat cut = image(cv::Rect(approx[0], approx[2]));
                        //Used to find very small rectangle-cuts
                        if(cut.cols < 20 || cut.rows < 20){
                            cv::Mat whitespace(cv::Size(cut.cols + 50, cut.rows + 50), CV_8UC3);
                            whitespace = cv::Scalar(0, 0 ,0);

                            cut.copyTo(whitespace(cv::Rect(10, 10, cut.cols, cut.rows)));
                            cut = whitespace;
                            //cv::imshow("2wd", whitespace);
                            //cv::waitKey(0);
                        }
                        cv::imwrite(outSrc, cut);
                        //cv::imshow("s", cut);
                        //cv::waitKey(0);
                        //If cut is inside colorspace
                        if(getColorAtRectangle() != 0){ 
                            squares.push_back(approx);
                            //looprequest = true;
                        }
                        else {
                            std::cout << "Falsches" << std::endl;
                        }
                    }
                }
            }
        }
    }
    if(squares.empty()) return 0;
    return 1;
}

void drawContours(cv::Mat& img, std::vector<std::vector<cv::Point>> squares)
{
    cv::Scalar s(255,0,0);
    for(int i = 0; i < squares.size(); i++){
        //if(i == 17) {s.val[0] = 0; s.val[2] = 255;} // draw 17. gefundenes Viereck
        //else {s.val[0] = 255; s.val[2] = 0;}
        for(int i2 = 0; i2 < squares.at(i).size(); i2++){
            int temp = i2;
            cv::circle(img,squares.at(i).at(i2),3,cv::Scalar(0,255,0),1);
            if(temp+1 == squares.at(i).size())temp = -1;
            cv::line(img, squares.at(i).at(i2), squares.at(i).at(temp+1), s, 1);
        }
    }
}

double getAngle(cv::Point pt)
{
    cv::Point center(width/2, height);
    cv::Point zero(0, 0);
    
    const double Rad2Deg = 180.0 / M_PI;

    //TODO: Change when first real start
    //return atan2((double)center.x - (double)pt.x, (double)center.y - (double)pt.y) * Rad2Deg; //degree
    return -atan2((double)center.x - (double)pt.x, (double)center.y - (double)pt.y); //rad
}

void showAngle(cv::Mat &image){ //Funktion um das Bild auszugeben
    cv::Point zeroPoint(width/2, height);
    cv::Point rightAngle(width/2, centerPoint.y);

    double angle = getAngle(centerPoint);

    std::stringstream angleText;
    angleText << "Winkel: " << angle;

    cv::circle(image, zeroPoint, 4, cv::Scalar(0, 0, 255), 2);
    cv::circle(image, rightAngle, 4, cv::Scalar(0, 0, 255), 2);
    cv::circle(image, centerPoint, 4, cv::Scalar(0, 0, 255), 2);
    cv::line(image, zeroPoint, rightAngle, cv::Scalar(0, 0, 255), 1);
    cv::line(image, zeroPoint, centerPoint, cv::Scalar(0, 0, 255), 1);
    cv::ellipse(image, zeroPoint, cv::Size((height-centerPoint.y)*0.4, (height-centerPoint.y)*0.4), 270-angle, 0, angle, cv::Scalar(0, 255, 0), 1);
    cv::putText(image, angleText.str(), cv::Point(0, height-5), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 1);

    cvNamedWindow("circles",1);
    cv::imshow("circles",image);
    cv::waitKey(0);
}

void readImage(cv::Mat& image, std::string& pathToFile)
{
    image = cv::imread(pathToFile, 1);
    if(image.empty()) throw std::runtime_error("Dateipfad falsch!");
    width = image.cols;
    height = image.rows;
}

void rotate(cv::Mat& src, double angle, cv::Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    cv::Point2f pt(len/2., len/2.);
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);

    cv::warpAffine(src, dst, r, cv::Size(len, len));
}

void getXY(float& x, float& y){
    //unit in cm
    int start = 20;
    if(centerPoint.y >= 752) {
        x = start + (centerPoint.y - 752) / 20.8;
    }else if(centerPoint.y >= 615) {
        x = start + 10 + (centerPoint.y - 615) / 13.7;
    }else if(centerPoint.y >= 512) {
        x = start + 20 + (centerPoint.y - 512) / 10.3;
    }else if(centerPoint.y >= 416) {
        x = start + 30 + (centerPoint.y - 416) / 9.6;
    }else if(centerPoint.y >= 345) {
        x = start + 40 + (centerPoint.y - 345) / 7.1;
    }else if(centerPoint.y >= 285) {
        x = start + 50 + (centerPoint.y - 285) / 6;
    }else if(centerPoint.y >= 232) {
        x = start + 60 + (centerPoint.y - 232) / 5.3;
    }else if(centerPoint.y >= 189) {
        x = start + 70 + (centerPoint.y - 189) / 4.3;
    }else if(centerPoint.y >= 150) {
        x = start + 80 + (centerPoint.y - 150) / 3.9;
    }else if(centerPoint.y >= 117) {
        x = start + 90 + (centerPoint.y - 117) / 3.3;
    }
    y = (640 - centerPoint.x) / 14;
}

void getMinYRec(std::vector<std::vector<cv::Point>>& squares, std::vector<std::vector<cv::Point>>& temp){
    int maxY = 960;
    for(int i = 0; i < squares.size(); i++){
        for(int i2 = 0; i2 < squares.at(i).size(); i2++){
            if(squares.at(i).at(i2).y < maxY){ 
                maxY = squares.at(i).at(i2).y;
                temp.at(0) = squares.at(i); 
            }
        }
    }
}

bool ShapeDetection(std::string& pathToFile, float& angle, float& x, float& y) 
{
    cv::Mat                             image;
    std::vector<std::vector<cv::Point>> squares, temp;
    bool                                video = false;
    bool                                squareFound;
    std::vector<cv::Point>              empty;
    temp.push_back(empty);
   
    if(video){
        cv::VideoCapture    capture;
        capture.open(0);

        capture.set(CV_CAP_PROP_FRAME_WIDTH , 640);
        capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    }

    try {
        readImage(image, pathToFile);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        return false;
    }

    squareFound = find_squares(image, squares);
    getMinYRec(squares, temp);
    squares = temp;


    if(squareFound) {
        //TODO: centerPoint festlegen
        //std::cout << squares.at(0).at(2).x << " X " << squares.at(0).at(0).x << std::endl;
        int xBase, yBase;
        if(squares.at(0).at(0).x < squares.at(0).at(2).x) xBase = squares.at(0).at(0).x;
        else xBase = squares.at(0).at(2).x;
        if(squares.at(0).at(0).y < squares.at(0).at(2).y) yBase = squares.at(0).at(0).y;
        else yBase = squares.at(0).at(2).y;
    
        int xCenter = xBase + (std::abs(squares.at(0).at(2).x - squares.at(0).at(0).x) * 0.5);
        int yCenter = yBase + (std::abs(squares.at(0).at(2).y - squares.at(0).at(0).y) * 0.5);
        std::cout << "xDiff: " << xCenter << " yDiff: " << yCenter << std::endl;
        //centerPoint = cv::Point(squares.at(0).at(2).x + (squares.at(0).at(0).x - squares.at(0).at(2).x) * 0.5, squares.at(0).at(0).y);
        centerPoint = cv::Point(xCenter, yCenter);

        //cv::circle(image, centerPoint, 5, cv::Scalar(0, 255,0), 1);

        //TODO: Show-only
        drawContours(image, squares);
        getXY(x, y);
        angle = getAngle(centerPoint);
        std::cout << "WINKEL: " << angle << " X: " << x << " Y: " << y << std::endl;
        showAngle(image);
    

        //ausgaben
        for(int i = 0;i < squares.size(); i++){
            std::cout << "Viereck " << i << std::endl;
            for(int i2 = 0;i2 <= 3; i2++){
                std::cout << "Punkt " << i2 << ":" << std::endl;
                std::cout << "X: " << squares.at(i).at(i2).x << std::endl;
                std::cout << "Y: " << squares.at(i).at(i2).y << std::endl;
            }
            std::cout << "----------------"  << std::endl;
        }

        std::cout << "Höhe: " << height << " Breite: " << width << std::endl;
    }
    else std::cout << "Kein Wuerfel gefunden" << std::endl;
    //cv::imshow("OutputPicture", image);
    //cv::waitKey(0);

    return squareFound;
}