#include "Navigation.hpp"

Navigation::Navigation(std::string s){
    robotIp = s;
    initializeNavigationProxy(robotIp);
}

void Navigation::moveTo(const float x, const float y, const float rad){
    globalNavProxy->moveTo(x, y, rad);
}

void Navigation::initializeNavigationProxy(std::string &robotIp){
    globalNavProxy = std::make_shared<AL::ALNavigationProxy>(robotIp, 9559);
}

Navigation::~Navigation(void){
}