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
        insert_in_map(Register_Color, "Black_Register_Color");
        insert_in_map(Walk_To, "Black_Walk_to");
        insert_in_map(Search_Mark_X, "Black_Search_Mark_X");
        insert_in_map(Search_Mark_y, "Black_Search_Mark_Y");
        insert_in_map(Won, "Black_Won");
        insert_in_map(Lost, "Black_Lost");
        insert_in_map(Search_Dice, "Black_Search_Dice");
        insert_in_map(Search_Dice2, "Black_Search_Dice2");
        insert_in_map(Search_Dice3, "Black_Search_Dice3");
        insert_in_map(ALL, "");
       
    #undef insert_in_map
}

// TODO: edit Proxy if global works :: Edit constructor and remove behaveProxy
void Behavior::startBehavior(BehaviorID BID){
        //AL::ALBehaviorManagerProxy behaveProxy(robotIp, 9559);
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
            globalBehaveProxy->runBehavior(BIDstring[Walk_To]); 
            break;
        case 5:
            globalBehaveProxy->runBehavior(BIDstring[Search_Mark_X]);
            break;
        case 6: 
            globalBehaveProxy->runBehavior(BIDstring[Search_Mark_y]);
            break;
        case 7:
            globalBehaveProxy->runBehavior(BIDstring[Won]);
            break;
        case 8:
            globalBehaveProxy->runBehavior(BIDstring[Lost]);
            break;
        case 9: 
            globalBehaveProxy->runBehavior(BIDstring[Search_Dice]);
            break;
        case 10:
            globalBehaveProxy->runBehavior(BIDstring[Search_Dice2]);  
            break;
        case 11:
            globalBehaveProxy->runBehavior(BIDstring[Search_Dice3]);
            break;
    }
        //globalBehaveProxy->runBehavior("sayPeter");
        /*int i2 = 0;
        std::cin >> i2;*/
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
            globalBehaveProxy->stopBehavior(BIDstring[Walk_To]);  
            break;
        case 5:
            globalBehaveProxy->stopBehavior(BIDstring[Search_Mark_X]);
            break;
        case 6: 
            globalBehaveProxy->stopBehavior(BIDstring[Search_Mark_y]);
            break;
        case 7:
            globalBehaveProxy->stopBehavior(BIDstring[Won]);  
            break;
        case 8:
            globalBehaveProxy->stopBehavior(BIDstring[Lost]);
            break;
        case 9: 
            globalBehaveProxy->stopBehavior(BIDstring[Search_Dice]);
            break;
        case 10:
            globalBehaveProxy->stopBehavior(BIDstring[Search_Dice2]);  
            break;
        case 11:
            globalBehaveProxy->stopBehavior(BIDstring[Search_Dice3]);
            break;
        case 12:
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