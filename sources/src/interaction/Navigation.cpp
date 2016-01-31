#include "Navigation.hpp"

using namespace navigation;

Navigation::Navigation(std::string s){
    initializeNavigationProxy(s);
}

void Navigation::moveTo(const float x, const float y, const float rad){
    globalNavProxy->moveTo(x, y, rad);
}

void Navigation::initializeNavigationProxy(std::string &robotIp){
    globalNavProxy = std::make_shared<AL::ALNavigationProxy>(robotIp, 9559);
}

Navigation::~Navigation(void){
}