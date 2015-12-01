#ifndef __MODULE_HPP__
#define __MODULE_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <opencv\cv.h>
#include <opencv\highgui.h>

#include "Objekte.h"
#include "FarbPos.hpp"

namespace naocv {
     
    int run(const std::string& pathToFile,
            bool calibrationMode = true,
            bool videoMode = false);

    std::string intTostring(int number);

    void CannyThreshold(int, void*);

    void on_trackbar(int, void*);

    void createTrackbars();

}

#endif //__MODULE_HPP__