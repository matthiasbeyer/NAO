#pragma once

// Aldebaran includes.
#include <alproxies\alnavigationproxy.h>

#include <string>
#include <memory>

namespace navigation {

    class Navigation {
        std::string robotIp;
        std::shared_ptr<AL::ALNavigationProxy> globalNavProxy;
        void initializeNavigationProxy(std::string &robotIp);

    public:
        Navigation(std::string robotIp);
        ~Navigation(void);
        void moveTo(const float x, const float y, const float rad);
    };

}