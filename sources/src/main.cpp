/*
 * main.cpp
 *
 * Main file which contains the main routine. We do the high-level stuff here.
 *
 */

#include "opencv/colorDetection.hpp"
#include "opencv/ShapeDetection.hpp"
//#include "opencv/ShapeDetection2.hpp"
#include "interaction/Behavior.hpp"
#include "interaction/ImageLoader.hpp"
#include "interaction/Navigation.hpp"
#include "algo/Algorithm.hpp"

int main(int /*argc*/, char** /*argv[]*/)
{
    // INIT <-----
    std::string pathToFile("C:/naoqi/_workspace/_src/imgg_magenta.jpg");
    std::string robotIp("169.254.216.239");
    algo::Card min = 1;
    algo::Card max = 6;
    algo::Algorithm algo(min, max);
    int x, y;
    float angle;
    bool direction;

    //behavior::Behavior behaviorProxy(robotIp);
    //navigation::Navigation navigationProxy(robotIp);
    //imgloader::ImageLoader imageLoaderProxy(robotIp, pathToFile);
    //imageLoaderProxy.getImage();
    // ----->

    try {
        //behaviorProxy.startBehavior(behavior::Search_Dice);
        //navigationProxy.moveTo(0.2,0.2,1);
        //std::cout << "Wert: " << naocv::colorDetection(imagePath, false) << std::endl;
        //naocv::getImageNao(robotIp,imagePath);
        //if(naocv::colorDetection(imagePath, false) == 4){
            //behaviorProxy.startBehavior(Stand_up, robotIp);
        
        //naocv::colorDetection(pathToFile, true); int i; std::cin >> i;
        bool a = ShapeDetection(pathToFile);
        //if(a) std::cout << "gefunden" << std::endl;
        
        
        //Main-Module Start <----
        //Throw cube
        //behaviorProxy.startBehavior(behavior::Pickup);
        //behaviorProxy.startBehavior(behavior::Throw);
        /*
        do {
            //Find cube
            do {
                behaviorProxy.startBehavior(behavior::Rotate);
            } while(!ShapeDetection(x, y, angle));

            //goto cube
            navigationProxy.moveTo(x, y, angle);
         
            // Game step
            auto analyzed = naocv::colorDetection(pathToFile);
            algo.update(std::make_shared<algo::Card>(analyzed));
            
        } while (algo.doDraw());*/
        //--->

    }
    catch(cv::Exception& e){
        std::cout << "OpenCV Error: " << e.what() << std::endl;
    }catch(const AL::ALError& e){
        std::cerr << "Aldebaran Error: " << e.what() << std::endl;
    }catch(std::runtime_error& e){
        std::cout << "Runtime Error: " << e.what() << std::endl;
    }
     
    return 0;

    /* PSEUDOCODE
    algo::Card min = 1;
    algo::Card max = 6;
    algo::Algorithm algo(min, max);

    // Introduction
    behaviour::intro();

    // Find Cube
    auto cube = nao::behaviour::find_cube();
    if (!cube) {
        nao::behaviour::abort("Cannot find cube");
        exit(1);
    }

    // Go to cube
    auto b = nao::behaviour::go_to(cube);
    if (!b) {
        nao::behaviour::abort("Cannot goto cube");
    }

    do {
        nao::behaviour::throw_cube(cube); // Throw cube

        cube = nao::behaviour::find_cube(); // find/goto cube
        if (!cube) {
            nao::behaviour::abort("Cannot find cube");
            break;
        }

        auto b = nao::behaviour::go_to(cube);
        if (!b) {
            nao::behaviour::abort("Cannot goto cube");
            break;
        }

        auto analyzed = nao::behaviour::analyze_cube(); // analyze cube-color
        algo.update(analyzed); // Game step
    } while (algo.doDraw()); // as long as game algo says yes

    // Outro
    nao::behaviour::outro();
*/
}