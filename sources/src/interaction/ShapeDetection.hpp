#define _USE_MATH_DEFINES

#include <math.h>

#include "opencv\cv.h"
#include "opencv\highgui.h"

int height, width;
cv::Mat image;
cv::Point centerPoint;

cv::Point findCircle(){
    IplImage* img = NULL;
    char* c = "C:/naoqi/_workspace/ShapeDetection/Debug/cube3.jpg";
    if ((img = cvLoadImage(c))== 0)
    {
        printf("cvLoadImage failed\n");
    }
    height = img->height;
    width = img->width;

    IplImage* gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    CvMemStorage* storage = cvCreateMemStorage(0);

    cvCvtColor(img, gray, CV_BGR2GRAY);

    // This is done so as to prevent a lot of false circles from being detected
    cvSmooth(gray, gray, CV_GAUSSIAN, 7, 9);

    IplImage* canny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    IplImage* rgbcanny = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    cvCanny(gray, canny, 170, 250, 3);

    CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, 2, gray->height/8, 120, 150, 20, 600);
    cvCvtColor(canny, rgbcanny, CV_GRAY2BGR);
  
    for (size_t i = 0; i < circles->total; i++)
    {
         // round the floats to an int
         float* p = (float*)cvGetSeqElem(circles, i);
         cv::Point center(cvRound(p[0]), cvRound(p[1]));
         centerPoint = center;
         int radius = cvRound(p[2]);

         // draw the circle center
         cvCircle(rgbcanny, center, 3, CV_RGB(0,255,0), -1, 8, 0 );

         // draw the circle outline
         cvCircle(rgbcanny, center, radius+1, CV_RGB(0,0,255), 2, 8, 0 );

         printf("x: %d y: %d r: %d\n",center.x,center.y, radius);
    }

    cvNamedWindow("circles", 1);
    cvShowImage("circles", rgbcanny);

    //cvSaveImage("out.png", rgbcanny);
    cvWaitKey(0);
    image = cv::Mat(img);
    return centerPoint;
}

double getAngle(cv::Point pt)
{
    cv::Point center(width/2, height);
    cv::Point zero(0, 0);
    const double Rad2Deg = 180.0 / M_PI;
    return atan2((double)center.x - (double)pt.x, (double)center.y - (double)pt.y) * Rad2Deg;
}

void getAngleCenter(){ //Funktion um das Bild auszugeben
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

//TODO: edit rückgabewert
bool ShapeDetection(){ //.hpp Name
    findCircle();
    double angle = getAngle(centerPoint);
    cv::waitKey(0);

    return false;
}