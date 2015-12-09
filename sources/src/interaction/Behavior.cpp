#include "Behavior.hpp"


Behavior::Behavior(std::string s)
{
    robotIp = s;
    initializeMap();
    initializeBehaviorProxy(robotIp);
}

void Behavior::initializeMap(){
    #define insert_in_map(k,v) do {                                     \
            BIDstring.insert(std::pair<BehaviorID, std::string>(k,v));  \
        } while(0)

        insert_in_map(Stand_up, "Black_Standup");
        insert_in_map(Pickup, "Black_Pickup");
        insert_in_map(Throw, "Black_Throw");
        insert_in_map(Register_Color, "Black_Register_Color");
        insert_in_map(Walk_To, "Black_Walk_to");
        insert_in_map(Search_Mark_X, "Black_Search_Mark_X");
        insert_in_map(Search_Mark_y, "Black_Search_Mark_Y");
        insert_in_map(Won, "Black_Won");
        insert_in_map(Lost, "Black_Lost");
        insert_in_map(Search_Dice, "Black_Search_Dice");
       
    #undef insert_in_map
}

// TODO: edit Proxy if global works :: Edit constructor and remove behaveProxy
void Behavior::startBehavior(BehaviorID BID,std::string &robotIp){
        AL::ALBehaviorManagerProxy behaveProxy(robotIp, 9559);
        switch(BID) {
        case 0:
            behaveProxy.runBehavior(BIDstring[Stand_up]);
        }
        behaveProxy.runBehavior("sayPeter");
        int i2 = 0;
        std::cin >> i2;
}

void Behavior::initializeBehaviorProxy(std::string &robotIp){
        globalBehaveProxy = std::make_shared<AL::ALBehaviorManagerProxy>(robotIp, 9559);
}


Behavior::~Behavior(void)
{
}