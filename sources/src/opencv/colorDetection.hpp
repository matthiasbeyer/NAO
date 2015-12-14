#ifndef __colorDetection_HPP__
#define __colorDetection_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <memory>
#include <opencv\cv.h>
#include <opencv\highgui.h>

#include "Objekte.hpp"
#include "FarbPos.hpp"

namespace naocv {
     
    Farbe colorDetection(const std::string& pathToFile,
            bool calibrationMode = false,
            bool videoMode = false);

    std::string intTostring(int number);

    void CannyThreshold(int, void*);

    void on_trackbar(int, void*);

    void createTrackbars();

}

#endif //__colorDetection_HPP__