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
        Search_Position,
        Won,
        Lost,
        Turn_Around,
        Greetings,
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