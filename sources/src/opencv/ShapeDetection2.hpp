#pragma once
#define _USE_MATH_DEFINES

// Opencv includes.

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include <math.h>
#include <iostream>

cv::Point centerPoint;
int width, height;

bool findCircle(const cv::Mat& src_gray, const cv::Mat& src_display, int cannyThreshold, int accumulatorThreshold){
        // will hold the results of the detection
    std::vector<cv::Vec3f> circles;
    // runs the actual detection
    HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, cannyThreshold, accumulatorThreshold, 0, 0 );

    // clone the colour, input image for displaying purposes
    cv::Mat display = src_display.clone();
    for( size_t i = 0; i < circles.size(); i++ ){
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        centerPoint = center;
        int radius = cvRound(circles[i][2]);
        // circle center
        circle( display, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
        // circle outline
        circle( display, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
    }

    // shows the results
    //cv::imshow( "TEstWindow", display);

    if(circles.size() < 1)return false;
    
    return true;
}

double getAngle(cv::Point pt)
{
    cv::Point center(width/2, height);
    cv::Point zero(0, 0);
    
    const double Rad2Deg = 180.0 / M_PI;

    //TODO: Change when first real start
    //return atan2((double)center.x - (double)pt.x, (double)center.y - (double)pt.y) * Rad2Deg; //degree
    return atan2((double)center.x - (double)pt.x, (double)center.y - (double)pt.y); //rad
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

//TODO: remove parameters
bool ShapeDetection2(){
    cv::Mat src, src_gray;
    
    const int cannyThreshold = 27;
    const int accumulatorThreshold = 45;
    
    std::string path("C:/naoqi/_workspace/_src/imgg.jpg");

    // Read the image
    src = cv::imread( path, 1 );

    if( src.empty() )
    {
        std::cerr<<"Invalid input image\n";
        return false;
    }

    height = src.rows;
    width = src.cols;

    medianBlur(src, src, 9);

    // Convert it to gray
    cvtColor( src, src_gray, cv::COLOR_BGR2GRAY );


    // Reduce the noise so we avoid false circle detection
    GaussianBlur( src_gray, src_gray, cv::Size(9, 9), 2, 2 );

    bool b = findCircle(src_gray, src, cannyThreshold, accumulatorThreshold);

    showAngle(src);

    return b;
}