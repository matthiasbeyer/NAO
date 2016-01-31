#pragma once

// Aldebaran includes.
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>

// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>

namespace imgloader {

    class ImageLoader {
        std::string pathToFile;
        std::shared_ptr<AL::ALVideoDeviceProxy> globalVideoProxy;
        void initializeVideoProxy(std::string &robotIp);

    public:
        ImageLoader(std::string robotIp, std::string path);
        ~ImageLoader(void);
        void getImage();
    };

}