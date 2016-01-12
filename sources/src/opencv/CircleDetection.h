#include <opencv\cv.h>
#include <opencv\highgui.h>

#include <iostream>

int HoughDetection(cv::Mat& src_gray, cv::Mat& src_display, int cannyThreshold, int accumulatorThreshold){
    // will hold the results of the detection
    std::vector<cv::Vec3f> circles;
    // runs the actual detection
    cv::HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, cannyThreshold, accumulatorThreshold, 25, 55);

    // clone the colour, input image for displaying purposes
    cv::Mat display = src_display.clone();
    for( size_t i = 0; i < circles.size(); i++ )
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        // circle center
        circle( display, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
        // circle outline
        circle( display, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
    }

    // shows the results
    imshow("Window", display);
    cv::waitKey(0);

    if(circles.size() < 1) return -1;
    return circles.size();
}


int CircleDetection(std::string& pathToFile){
    cv::Mat src, src_gray;

    // Read the image
    src = cv::imread(pathToFile, 1 );

    if( src.empty() )
    {
        return -1;
    }

    medianBlur(src, src, 9);

    // Convert it to gray
    cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);

    // Reduce the noise so we avoid false circle detection
    GaussianBlur(src_gray, src_gray, cv::Size(9, 9), 2, 2);

    return HoughDetection(src_gray, src, 35, 30);
}