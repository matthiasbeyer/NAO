/*
 * main.cpp
 *
 * Main file which contains the main routine. We do the high-level stuff here.
 *
 */

#include "opencv/colorDetection.hpp"
#include "opencv/ShapeDetection.hpp"
#include "interaction/Behavior.hpp"
#include "interaction/ImageLoader.hpp"
#include "interaction/Navigation.hpp"
#include "algo/Algorithm.hpp"

int main(int argc, char* argv[])
{
    // INIT <-----
    std::string imagePath ("C:/naoqi/_workspace/nao_repo/NAO/sources/src/build-naochain/sdk/bin/robotImage.jpg");
    std::string robotIp(argv[1]);
    //algo::Card min = 1;
    //algo::Card max = 6;
    //algo::Algorithm algo(min, max);
    int x, y;
    float angle;

    //behavior::Behavior behaviorProxy(robotIp);

    // ----->

    try {
        //std::cout << "Wert: " << naocv::colorDetection(imagePath, false) << std::endl;
        //naocv::getImageNao(robotIp,imagePath);
        //if(naocv::colorDetection(imagePath, false) == 4){
            //behaviorProxy.startBehavior(Stand_up, robotIp);
        //
        //naocv::colorDetection(imagePath, false);
        ShapeDetection(x, y, angle);
        std::cout <<"x: "<< x <<" y: "<< y <<" angle: "<< angle << std::endl;


        /*do {
            //Throw cube
            behaviorProxy.startBehavior(behavior::Throw);

            //Find cube
            do {
                behaviorProxy.startBehavior(behavior::Rotate);
            } while(!ShapeDetection(x, y, angle));

            //goto cube
            navigationProxy.moveTo(x, y, angle);

            //analyze color
            naocv::colorDetection(imagePath);


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
        } while (algo.doDraw());*/

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