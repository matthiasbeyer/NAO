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
    /////////<----- INIT
    std::string pathToFile("C:/naoqi/_workspace/_src/Ziel2.jpg");
    std::string robotIp("169.254.51.192");
    int counter = 0;
    float x, y;
    float angle;
    bool cubeFound, draw;
    cubeFound = false;
    
    algo::Card min = 1;
    algo::Card max = 6;
    algo::Algorithm algo(min, max);
    /*
    behavior::Behavior behaviorProxy(robotIp);
    navigation::Navigation navigationProxy(robotIp);
    imgloader::ImageLoader imageLoaderProxy(robotIp, pathToFile);
    AL::ALTextToSpeechProxy speakProxy(robotIp, 9559);

    speakProxy.setLanguage("German");
    speakProxy.setVolume(0.7);*/
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

        //behaviorProxy.startBehavior(behavior::Stand_up);
        //behaviorProxy.startBehavior(behavior::Register_Color);
        /*imageLoaderProxy.getImage();
        std::cout << naocv::colorDetection(pathToFile, x, y, angle, false) << std::endl;
        int i; std::cin >> i;*/

        std::cout << naocv::colorDetection(pathToFile, x, y, angle, false) << std::endl;

        //ShapeDetection(pathToFile, angle, x, y);
        //behaviorProxy.startBehavior(behavior::Stand_up);
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
        /*
        behaviorProxy.startBehavior(behavior::Greetings);
        speakProxy.say("Lass uns beginnen, ich fange an");

        do {
            behaviorProxy.startBehavior(behavior::Pickup);
int g; std::cin >> g;
            behaviorProxy.startBehavior(behavior::Throw);
            behaviorProxy.startBehavior(behavior::Stand_up);
            behaviorProxy.startBehavior(behavior::Search_Position);
            speakProxy.say("Ich suche jetzt den Wuerfel");
            imageLoaderProxy.getImage();

            for(int i = 0; naocv::colorDetection(pathToFile, x, y, angle) == 0; i++){
                if(i == 0){ 
                    navigationProxy.moveTo(0, 0, 0.95);
                    behaviorProxy.startBehavior(behavior::Search_Position);
                    imageLoaderProxy.getImage();
                }
                else if(i == 1){ 
                    navigationProxy.moveTo(0, 0, -1.7472);
                    behaviorProxy.startBehavior(behavior::Search_Position);
                    imageLoaderProxy.getImage();
                }
                else if(i == 2){
                    navigationProxy.moveTo(0, 0, 0.95);
                    navigationProxy.moveTo(-0.2, 0, 0);
                    behaviorProxy.startBehavior(behavior::Search_Position);
                    imageLoaderProxy.getImage();
                    if(naocv::colorDetection(pathToFile, x, y, angle) != 0){
                        cubeFound = true;
                    }
                }
                else {
                    if(cubeFound)
                        break;
                    else{
                        speakProxy.say("Ich habe den Wuerfel nicht gefunden!");
                        throw std::runtime_error("Cube not Found");
                    }
                }
            }
            speakProxy.say("Ich habe den Wuerfel gefunden");
            x = x * 0.01; //cm in m
            y = y * 0.01; //cm in m
            y = y + -(x*0.005); //compensate slip
            angle = (-(x * 0.00581776)*0.2);
            navigationProxy.moveTo(0, y, 0);
            navigationProxy.moveTo(x/2, 0, angle);
            behaviorProxy.startBehavior(behavior::Search_Position);
            imageLoaderProxy.getImage();
            for(int i = 0; naocv::colorDetection(pathToFile, x, y, angle) == 0; i++){
                if(i == 0){ 
                    navigationProxy.moveTo(0, 0, 0.95);
                    behaviorProxy.startBehavior(behavior::Search_Position);
                    imageLoaderProxy.getImage();
                }
                else if(i == 1){ 
                    navigationProxy.moveTo(0, 0, -1.7472);
                    behaviorProxy.startBehavior(behavior::Search_Position);
                    imageLoaderProxy.getImage();
                }
                else if(i == 2){
                    navigationProxy.moveTo(0, 0, 0.95);
                    navigationProxy.moveTo(-0.2, 0, 0);
                    behaviorProxy.startBehavior(behavior::Search_Position);
                    imageLoaderProxy.getImage();
                    if(naocv::colorDetection(pathToFile, x, y, angle) != 0){
                        cubeFound = true;
                    }
                }
                else {
                    if(cubeFound)
                        break;
                    else{
                        speakProxy.say("Ich habe den Wuerfel nicht gefunden!");
                        throw std::runtime_error("Cube not Found");
                    }
                }
            }
            x = x * 0.01; //cm in m
            y = y * 0.01; //cm in m
            x = x*1.05;
            y = y*0.40; //+ -(x*0.020); //compensate slip
            angle = (-(x * 0.00581776)*0.2);
            navigationProxy.moveTo(0, y, 0);
            navigationProxy.moveTo(x, 0, angle);
            
            std::cout << "WINKEL: " << angle << " X: " << x << " Y: " << y << "cm" << std::endl;

            //Analyze cube-color
            speakProxy.say("Nun schaue ich welche Zahl ich habe");
            behaviorProxy.startBehavior(behavior::Register_Color);
            imageLoaderProxy.getImage();
            auto analyzed = naocv::colorDetection(pathToFile, x, y, angle, false);
            std::cout << "WUERFEL ZAHL: " << analyzed << std::endl;

            //Game step
            algo.update(std::make_shared<algo::Card>(analyzed));
            draw = algo.doDraw();
            std::cout << "State: " << draw << std::endl;
            
            //Interaction
            speakProxy.say("Ich habe eine");
            speakProxy.say(naocv::intTostring(analyzed));
            if(counter > 0){
                speakProxy.say(",Insgesamt habe ich");
                speakProxy.say(naocv::intTostring(algo.get_current_sum()));
            }
            if(draw){
                speakProxy.say("Ich wuerfel noch ein mal");
            }
            counter++;
        }while(draw);
        

        int state = algo.getState();
        std::cout << "SUM: " << algo.get_current_sum() << std::endl;
        std::cout << "STATE: " << state << std::endl;
        speakProxy.say("ich bin fertig mit wuerfeln");
        if(state == 4){
            speakProxy.say("Glueckwunsch, du hast gewonnen!");
            behaviorProxy.startBehavior(behavior::Lost);
        }
        else if(state == 3){
            if(algo.get_current_sum() == 21){
                behaviorProxy.startBehavior(behavior::Won);                
            }
            else{
               speakProxy.say("Jetzt darfst du wuerfeln!");
int z;
std::cin >> z;
               behaviorProxy.startBehavior(behavior::Search_Position);
                speakProxy.say("Ich suche jetzt den Wuerfel");
                imageLoaderProxy.getImage();
                for(int i = 0; naocv::colorDetection(pathToFile, x, y, angle) == 0; i++){
                    if(i == 0){ 
                        navigationProxy.moveTo(0, 0, 0.95);
                        behaviorProxy.startBehavior(behavior::Search_Position);
                        imageLoaderProxy.getImage();
                    }
                    else if(i == 1){ 
                        navigationProxy.moveTo(0, 0, -1.7472);
                        behaviorProxy.startBehavior(behavior::Search_Position);
                        imageLoaderProxy.getImage();
                    }
                    else{
                        speakProxy.say("Ich habe den Wuerfel nicht gefunden");
                        throw std::runtime_error("Cube not Found");
                    }
                }
                speakProxy.say("Ich habe den Wuerfel gefunden");
                x = x * 0.01; //cm in m
                y = y * 0.01; //cm in m
                y = y + -(x*0.010); //compensate slip
                angle = (-(x * 0.00581776)*0.2);
                navigationProxy.moveTo(0, y, 0);
                navigationProxy.moveTo(x/2, 0, angle);
                imageLoaderProxy.getImage();
                for(int i = 0; naocv::colorDetection(pathToFile, x, y, angle) == 0; i++){
                    if(i == 0){ 
                        navigationProxy.moveTo(0, 0, 0.95);
                        behaviorProxy.startBehavior(behavior::Search_Position);
                        imageLoaderProxy.getImage();
                    }
                    else if(i == 1){ 
                        navigationProxy.moveTo(0, 0, -1.7472);
                        behaviorProxy.startBehavior(behavior::Search_Position);
                        imageLoaderProxy.getImage();
                    }
                    else{
                     speakProxy.say("Ich habe den Wuerfel nicht gefunden");                
                     throw std::runtime_error("Cube not Found");
                    }
                }
                x = x * 0.01; //cm in m
                y = y * 0.01; //cm in m
                x = x*1.05;
                y = y*0.40; //+ -(x*0.020); //compensate slip
                angle = (-(x * 0.00581776)*0.2);
                navigationProxy.moveTo(0, y, 0);
                navigationProxy.moveTo(x, 0, angle);
            
                std::cout << "WINKEL: " << angle << " X: " << x << " Y: " << y << "cm" << std::endl;

                //Analyze cube-color
                speakProxy.say("Nun schaue ich welche Zahl du gewuerfelt hast");
                behaviorProxy.startBehavior(behavior::Register_Color);
                imageLoaderProxy.getImage();
                auto analyzed = naocv::colorDetection(pathToFile, x, y, angle, false);
                speakProxy.say("Du hast eine");
                speakProxy.say(naocv::intTostring(analyzed));

                int newSum = algo.get_current_sum() + analyzed;
                if(newSum <= 21){
                    speakProxy.say("Glueckwunsch, du hast gewonnen!");
                    behaviorProxy.startBehavior(behavior::Lost);                

                }
                else{
                    behaviorProxy.startBehavior(behavior::Won);                
                }
            }
        }
        else {
            throw std::runtime_error("State not found State:"+algo.getState());
        }
        */
        ///////////////////////////////////////////
        //---------PROGRAM CYCLE END------------//
        /////////////////////////////////////////
        
        //TESTCYCLE START
/*
        algo.update(std::make_shared<algo::Card>(19));
        bool b = algo.doDraw();
        std::cout << b << std::endl;
*/
        //TESTCYCLE END
    }
    catch(cv::Exception& e){
        std::cout << "OpenCV Error: " << e.what() << std::endl;
    }catch(const AL::ALError& e){
        std::cerr << "Aldebaran Error: " << e.what() << std::endl;
    }catch(std::runtime_error& e){
        std::cout << "Runtime Error: " << e.what() << std::endl;
    }
    int o;
std::cin >> o;

     return 0;
}