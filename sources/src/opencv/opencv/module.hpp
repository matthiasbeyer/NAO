#pragma once

#include <string>

namespace naocv {

    extern int lowThreshold;
    extern Mat dst;
    extern Mat detected_edges;
    extern Mat src;
    extern Mat src_gray;

    int run(const std::string& pathToFile,
            bool calibrationMode = true,
            bool videoMode = false);

}
