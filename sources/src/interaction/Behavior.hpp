#pragma once


// Aldebaran includes.
#include <alproxies\albehaviormanagerproxy.h>

#include <iostream>
#include <string>
#include <map>
#include <memory>

namespace behavior {

    enum BehaviorID {
        Stand_up,
        Pickup,
        Throw,
        Register_Color,
        Walk_To, //make head -5°
        Search_Mark_X,
        Search_Mark_y,
        Won,
        Lost,
        Search_Dice,
        Search_Dice2,
        Search_Dice3,
        ALL
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
        void startBehavior(BehaviorID BID);
        void stopBehavior(BehaviorID BID);
    };

}