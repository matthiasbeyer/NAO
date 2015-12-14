#pragma once

#include <iostream>
#include <string>
#include <map>
#include <memory>

#include <alproxies\albehaviormanagerproxy.h>

namespace behavior {

    enum BehaviorID {
        Stand_up,
        Pickup,
        Throw,
        Register_Color,
        Walk_To,
        Search_Mark_X,
        Search_Mark_y,
        Won,
        Lost,
        Search_Dice
    };

    class Behavior {
        std::string robotIp;
        std::map<BehaviorID, std::string> BIDstring;
        std::shared_ptr<AL::ALBehaviorManagerProxy> globalBehaveProxy;
        void initializeBehaviorProxy(std::string &robotIp);

    public:
        Behavior(std::string robotIp);
        ~Behavior(void);
        void initializeMap();
        void startBehavior(BehaviorID BID,std::string &robotIp);
    };

}