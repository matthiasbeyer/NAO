#include "Behavior.hpp"

using namespace behavior;

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
        insert_in_map(Search_Position, "Black_Search_Position");
        insert_in_map(Register_Color, "Black_Register_Color");
        insert_in_map(Search_Position, "Black_Search_Position");
        insert_in_map(Won, "Black_Won");
        insert_in_map(Lost, "Black_Lost");
        insert_in_map(Turn_Around, "Turn_Around");
        insert_in_map(ALL, "");
       
    #undef insert_in_map
}

void Behavior::startBehavior(BehaviorID BID){
    switch(BID) {
        case 0: 
            std::cout << "STANDUP" << std::endl;
            globalBehaveProxy->runBehavior(BIDstring[Stand_up]);
            break;
        case 1:
            globalBehaveProxy->runBehavior(BIDstring[Pickup]);  
            break;
        case 2:
            globalBehaveProxy->runBehavior(BIDstring[Throw]);
            break;
        case 3: 
            globalBehaveProxy->runBehavior(BIDstring[Register_Color]);
            break;
        case 4:
            globalBehaveProxy->runBehavior(BIDstring[Search_Position]); 
            break;
        case 5:
            globalBehaveProxy->runBehavior(BIDstring[Won]);
            break;
        case 6:
            globalBehaveProxy->runBehavior(BIDstring[Lost]);
            break;
        case 7:
            globalBehaveProxy->runBehavior(BIDstring[Lost]);
            break;
    }
}

void Behavior::stopBehavior(BehaviorID BID){
    switch(BID) {
        case 0: 
            globalBehaveProxy->stopBehavior(BIDstring[Stand_up]);
            break;
        case 1:
            globalBehaveProxy->stopBehavior(BIDstring[Pickup]);  
            break;
        case 2:
            globalBehaveProxy->stopBehavior(BIDstring[Throw]);
            break;
        case 3: 
            globalBehaveProxy->stopBehavior(BIDstring[Register_Color]);
            break;
        case 4:
            globalBehaveProxy->stopBehavior(BIDstring[Search_Position]);  
            break;
        case 5:
            globalBehaveProxy->stopBehavior(BIDstring[Won]);  
            break;
        case 6:
            globalBehaveProxy->stopBehavior(BIDstring[Lost]);
            break;
        case 7:
            globalBehaveProxy->stopBehavior(BIDstring[Turn_Around]);
            break;
        case 8:
            globalBehaveProxy->stopAllBehaviors();
            break;
    }
}

void Behavior::initializeBehaviorProxy(std::string &robotIp){
        globalBehaveProxy = std::make_shared<AL::ALBehaviorManagerProxy>(robotIp, 9559);
}


Behavior::~Behavior(void)
{
}