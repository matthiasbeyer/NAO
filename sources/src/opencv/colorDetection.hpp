#ifndef __colorDetection_HPP__
#define __colorDetection_HPP__
#define _USE_MATH_DEFINES

// Opencv includes.
#include <opencv\cv.h>
#include <opencv\highgui.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <memory>
#include <math.h>

#include "Objekte.hpp"
#include "FarbPos.hpp"

namespace naocv {
     
    int colorDetection(const std::string& pathToFile,
            float& x,
            float& y,
            float& angle,
            bool findCube = true,
            bool calibrationMode = false,
            bool videoMode = false);

    std::string intTostring(int number);

    void CannyThreshold(int, void*);

    void on_trackbar(int, void*);

    void createTrackbars();

}

#endif //__colorDetection_HPP__