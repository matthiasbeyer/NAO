#pragma once

#include <string>
#include <sstream>
#include <opencv\cv.h>
#include <opencv\highgui.h>

#include "opencv/opencv/module.hpp"

namespace naocv {

    const int           H_MIN                  = 0;
    const int           H_MAX                  = 256;
    const int           S_MIN                  = 0;
    const int           S_MAX                  = 256;
    const int           V_MIN                  = 0;
    const int           V_MAX                  = 256;
    const int           FRAME_WIDTH            = 640;
    const int           FRAME_HEIGHT           = 480;
    const int           MAX_NUM_OBJECTS        = 50;
    const int           MIN_OBJECT_AREA        = 20 * 20;
    const int           MAX_OBJECT_AREA        = FRAME_HEIGHT * FRAME_WIDTH / 1.5;
    const std::string   windowName             = "Original Image";
    const std::string   windowName1            = "HSV Image";
    const std::string   windowName2            = "Thresholded Image";
    const std::string   windowName3            = "After Morphological Operations";
    const std::string   trackbarWindowName     = "Trackbars";
    const int           const max_lowThreshold = 100;
    const int           ratio                  = 3;
    const int           kernel_size            = 3;
    const char*         window_name            = "Edge Map";
    const int           edgeThresh             = 1;

    std::string intTostring(int number) {
        std::stringstream ss;
        ss << number;
        return ss.str();
    }

    void CannyThreshold(int, void*)
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

    void on_trackbar(int, void*)
    {
        // This function gets called whenever a
        // trackbar position is changed
    }

    void createTrackbars() {
        //create window for trackbars
        namedWindow(trackbarWindowName, 0);

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

        createTrackbar("H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar);
        createTrackbar("H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar);
        createTrackbar("S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar);
        createTrackbar("S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar);
        createTrackbar("V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar);
        createTrackbar("V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar);
    }

}
