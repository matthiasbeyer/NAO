/*
 * main.cpp
 *
 * Main file which contains the main routine. We do the high-level stuff here.
 *
 */

#include "opencv/colorDetection.hpp"
#include "interaction/Behavior.hpp"
#include "interaction/ImageLoader.hpp"
#include "interaction/Navigation.hpp"
#include "algo/Algorithm.hpp"

#include <alproxies/altexttospeechproxy.h>

int main(int /*argc*/, char** /*argv[]*/)
{
    ///////// INIT <-----
    std::string pathToFile("C:/naoqi/_workspace/_src/dice_red1.jpg");
    std::string robotIp("169.254.51.192");
    int counter = 0;
    float x, y;
    float angle;
    bool direction;
    
    algo::Card min = 1;
    algo::Card max = 6;
    algo::Algorithm algo(min, max);
    
    //behavior::Behavior behaviorProxy(robotIp);
    //navigation::Navigation navigationProxy(robotIp);
    //imgloader::ImageLoader imageLoaderProxy(robotIp, pathToFile);
    //AL::ALTextToSpeechProxy speakProxy(robotIp, 9559);

    //speakProxy.setLanguage("German");
    /////////-------->

    try {
        /*behaviorProxy.startBehavior(behavior::Stand_up);

        behaviorProxy.startBehavior(behavior::Pickup);
        navigationProxy.moveTo(0, 0, 3.14159);
        behaviorProxy.startBehavior(behavior::Register_Color);
        imageLoaderProxy.getImage();
        CircleDetection(pathToFile);*/
        //behaviorProxy.startBehavior(behavior::Stand_up);

        //behaviorProxy.startBehavior(behavior::Register_Color);

        std::cout << naocv::colorDetection(pathToFile, x, y, angle, true) << std::endl;
        int i; std::cin >> i;
        //std::cout << CircleDetection(pathToFile) << std::endl;

        //ShapeDetection(pathToFile, angle, x, y);
        //imageLoaderProxy.getImage();

        //behaviorProxy.startBehavior(behavior::Search_Dice);
        //navigationProxy.moveTo(0.2,0.2,1);
        //behaviorProxy.startBehavior(behavior::Register_Color);
        //imageLoaderProxy.getImage();
        //std::cout << "Wert: " << naocv::colorDetection(pathToFile, true) << std::endl;
        //naocv::getImageNao(robotIp,imagePath);
        //if(naocv::colorDetection(imagePath, false) == 4){
            //behaviorProxy.startBehavior(Stand_up, robotIp);
        
        //naocv::colorDetection(pathToFile, false); int i; std::cin >> i;
        //imageLoaderProxy.getImage();
        //bool a = ShapeDetection(pathToFile, angle, y ,x);
            //behaviorProxy.startBehavior(behavior::Stand_up);

        ///////////////////////////////////////////
        //--------PROGRAM CYCLE START-----------//
        /////////////////////////////////////////

//        do {
//            behaviorProxy.startBehavior(behavior::Pickup);
//int g; std::cin >> g;
//            behaviorProxy.startBehavior(behavior::Throw);
//            behaviorProxy.startBehavior(behavior::Stand_up);
//            behaviorProxy.startBehavior(behavior::Search_Position);
//            imageLoaderProxy.getImage();
//            for(int i = 0; naocv::colorDetection(pathToFile, x, y, angle) == 0; i++){
//                if(i == 0){ 
//                    navigationProxy.moveTo(0, 0, 0.95);
//                    behaviorProxy.startBehavior(behavior::Search_Position);
//                    imageLoaderProxy.getImage();
//                }
//                else if(i == 1){ 
//                    navigationProxy.moveTo(0, 0, -1.7472);
//                    behaviorProxy.startBehavior(behavior::Search_Position);
//                    imageLoaderProxy.getImage();
//                }
//                else throw std::runtime_error("Cube not Found");
//            }
//            x = x * 0.01; //cm in m
//            y = y * 0.01; //cm in m
//            y = y + -(x*0.010); //compensate slip
//            angle = (-(x * 0.00581776)*0.2);
//            navigationProxy.moveTo(0, y, 0);
//            navigationProxy.moveTo(x/2, 0, angle);
//            imageLoaderProxy.getImage();
//            for(int i = 0; naocv::colorDetection(pathToFile, x, y, angle) == 0; i++){
//                if(i == 0){ 
//                    navigationProxy.moveTo(0, 0, 0.95);
//                    behaviorProxy.startBehavior(behavior::Search_Position);
//                    imageLoaderProxy.getImage();
//                }
//                else if(i == 1){ 
//                    navigationProxy.moveTo(0, 0, -1.7472);
//                    behaviorProxy.startBehavior(behavior::Search_Position);
//                    imageLoaderProxy.getImage();
//                }
//                else throw std::runtime_error("Cube not Found");
//            }
//            x = x * 0.01; //cm in m
//            y = y * 0.01; //cm in m
//            x = x*1.05;
//            y = y*0.40; //+ -(x*0.020); //compensate slip
//            angle = (-(x * 0.00581776)*0.2);
//            navigationProxy.moveTo(0, y, 0);
//            navigationProxy.moveTo(x, 0, angle);
//            
//            std::cout << "WINKEL: " << angle << " X: " << x << " Y: " << y << "cm" << std::endl;
//
//            //Analyze cube-color
//            behaviorProxy.startBehavior(behavior::Register_Color);
//            imageLoaderProxy.getImage();
//            auto analyzed = naocv::colorDetection(pathToFile, x, y, angle, false);
//            std::cout << "WUERFEL ZAHL: " << analyzed << std::endl;
//
//            //Game step
//            algo.update(std::make_shared<algo::Card>(analyzed));
//            
//            //Interaction
//            speakProxy.say("Ich habe eine");
//            speakProxy.say(naocv::intTostring(analyzed));
//            if(counter > 0){
//                speakProxy.say(",Insgesamt habe ich");
//                speakProxy.say(naocv::intTostring(algo.get_current_sum()));
//            }
//            if(algo.doDraw()) speakProxy.say("Ich würfel noch einmal");
//            counter++;
//        }while(algo.doDraw());
//        
//        int state = algo.getState();
//        std::cout << "SUM: " << algo.get_current_sum() << std::endl;
//        std::cout << "STATE: " << state << std::endl;
//        speakProxy.say("ich bin fertig mit würfeln");
//        if(state == 3)
//            speakProxy.say("Ich habe gewonnen!");
//        else{
//            speakProxy.say("uh, ich habe leider verloren");
//        }
//int g;
//std::cin >> g;

        ///////////////////////////////////////////
        //---------PROGRAM CYCLE END------------//
        /////////////////////////////////////////

    }
    catch(cv::Exception& e){
        std::cout << "OpenCV Error: " << e.what() << std::endl;
    }catch(const AL::ALError& e){
        std::cerr << "Aldebaran Error: " << e.what() << std::endl;
    }catch(std::runtime_error& e){
        std::cout << "Runtime Error: " << e.what() << std::endl;
    }

     return 0;
}