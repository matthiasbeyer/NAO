/*
 * main.cpp
 *
 * Main file which contains the main routine. We do the high-level stuff here.
 *
 */

#include "opencv/colorDetection.hpp"
#include "opencv/CircleDetection.h"
#include "interaction/Behavior.hpp"
#include "interaction/ImageLoader.hpp"
#include "interaction/Navigation.hpp"
#include "algo/Algorithm.hpp"

int main(int /*argc*/, char** /*argv[]*/)
{
    // INIT <-----
    std::string pathToFile("C:/naoqi/_workspace/_src/a.jpg");
    std::string robotIp("169.254.51.192");
    float x, y;
    float angle;
    bool direction;
    
    algo::Card min = 1;
    algo::Card max = 6;
    algo::Algorithm algo(min, max);

    behavior::Behavior behaviorProxy(robotIp);
    navigation::Navigation navigationProxy(robotIp);
    imgloader::ImageLoader imageLoaderProxy(robotIp, pathToFile);

    // ----->

    try {
        behaviorProxy.startBehavior(behavior::Stand_up);

        behaviorProxy.startBehavior(behavior::Pickup);
        navigationProxy.moveTo(0, 0, 3.14159);
        //CircleDetection(pathToFile);
        //behaviorProxy.startBehavior(behavior::Stand_up);
        //imageLoaderProxy.getImage();

        //behaviorProxy.startBehavior(behavior::Register_Color);

        //naocv::colorDetection(pathToFile, x, y, angle, false);
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

        //for(int g = 0; g < 4; g++){
        
        /*behaviorProxy.startBehavior(behavior::Pickup);
        behaviorProxy.startBehavior(behavior::Throw);*/
        
        //do {
        //    behaviorProxy.startBehavior(behavior::Stand_up);
        //    behaviorProxy.startBehavior(behavior::Search_Position);
        //    imageLoaderProxy.getImage();
        //    for(int i = 0; !naocv::colorDetection(pathToFile, x, y, angle); i++){
        //        if(i == 0){ 
        //            navigationProxy.moveTo(0, 0, 0.95);
        //            behaviorProxy.startBehavior(behavior::Search_Position);
        //            imageLoaderProxy.getImage();
        //        }
        //        else if(i == 1){ 
        //            navigationProxy.moveTo(0, 0, -1.7472);
        //            behaviorProxy.startBehavior(behavior::Search_Position);
        //            imageLoaderProxy.getImage();
        //        }
        //        else throw std::runtime_error("Cube not Found");
        //    }
        //    x = x * 0.01; //cm in m
        //    y = y * 0.01; //cm in m
        //    // x = x + (x * 0.02);
        //    //y = 0;
        //    //x = x - 0.03; //calibration value 
        //    y = y + -(x*0.010); //compensate slip
        //    angle = (-(x * 0.00581776)*0.2);
        //    //avigationProxy.moveTo(x, y, angle);
        //    navigationProxy.moveTo(0, y, 0);
        //    navigationProxy.moveTo(x/2, 0, 0);
        //     
        //    imageLoaderProxy.getImage();
        //    for(int i = 0; !naocv::colorDetection(pathToFile, x, y, angle); i++){
        //        if(i == 0){ 
        //            navigationProxy.moveTo(0, 0, 0.95);
        //            behaviorProxy.startBehavior(behavior::Search_Position);
        //            imageLoaderProxy.getImage();
        //        }
        //        else if(i == 1){ 
        //            navigationProxy.moveTo(0, 0, -1.7472);
        //            behaviorProxy.startBehavior(behavior::Search_Position);
        //            imageLoaderProxy.getImage();
        //        }
        //        else throw std::runtime_error("Cube not Found");
        //    }
        //    x = x * 0.01; //cm in m
        //    y = y * 0.01; //cm in m
        //    //x = x + (x * 0.4);
        //    //x = x + 18;
        //    x = x*1.05;
        //    y = y*0.40; //+ -(x*0.020); //compensate slip
        //    angle = (-(x * 0.00581776)*0.2);

        //    navigationProxy.moveTo(0, y, 0);
        //    navigationProxy.moveTo(x, 0, angle);
        //    
        //    std::cout << "WINKEL: " << angle << " X: " << x << " Y: " << y << "cm" << std::endl;

        //    //Analyze cube-color
        //    behaviorProxy.startBehavior(behavior::Register_Color);
        //    imageLoaderProxy.getImage();
        //    auto analyzed = CircleDetection(pathToFile);
        //    std::cout << "WUERFEL ZAHL: " << analyzed << std::endl;

        //    //Game step
        //    algo.update(std::make_shared<algo::Card>(analyzed));
        //    behaviorProxy.startBehavior(behavior::Search_Position);

        //    behaviorProxy.startBehavior(behavior::Pickup);
        //    int g;
        //    std::cin >> g;
        //    behaviorProxy.startBehavior(behavior::Throw);
        //}while(algo.doDraw());
        
        
        /*
        behaviorProxy.startBehavior(behavior::Register_Color);
        imageLoaderProxy.getImage();
        naocv::colorDetection(pathToFile);
        behaviorProxy.startBehavior(behavior::Pickup);
        behaviorProxy.startBehavior(behavior::Throw);
        /*
        
        /*
        //Main-Module Start <----
        behaviorProxy.startBehavior(behavior::Stand_up);
        behaviorProxy.startBehavior(behavior::Pickup);
        behaviorProxy.startBehavior(behavior::Throw);
        
        do {
            //Find cube
            for(int i = 0; !ShapeDetection(pathToFile, angle, x, y); i++){
                if(i == 0) navigationProxy.moveTo(0, 0, 1.0472);
                else if(i == 1) navigationProxy.moveTo(0, 0, -2.0944);
                else throw std::runtime_error("Cube not Found");
            }

            x = x * 0.01; //cm in m
            y = y * 0.01; //cm in m
            x = x - 0.03; //calibration value
            y = y - (x*0.174); //compensate slip

            //Goto cube
            navigationProxy.moveTo(x, y, angle);
         
            //Analyze cube-color
            behaviorProxy.startBehavior(behavior::Register_Color);
            auto analyzed = naocv::colorDetection(pathToFile);

            //Game step
            algo.update(std::make_shared<algo::Card>(analyzed));

            //Find throw-direction
            behaviorProxy.startBehavior(behavior::Pickup);

            if(direction){
                behaviorProxy.startBehavior(behavior::Search_Mark_X);
                direction = true;
            } else {
                behaviorProxy.startBehavior(behavior::Search_Mark_y);
                direction = false;
            }

            behaviorProxy.startBehavior(behavior::Throw);
            
        } while (algo.doDraw());
        //--->
        */
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