#ifndef __MODULE_HPP__
#define __MODULE_HPP__

#include <opencv\cv.h>

#include <string>

namespace naocv {

    extern int lowThreshold;
    extern cv::Mat dst;
    extern cv::Mat detected_edges;
    extern cv::Mat src;
    extern cv::Mat src_gray;

    int run(const std::string& pathToFile,
            bool calibrationMode = true,
            bool videoMode = false);

}

#endif //__MODULE_HPP__