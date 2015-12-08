#include "colorDetection.hpp"

int main(void) {
    std::string a = "C:/naoqi/_workspace/nao_repo/NAO/sources/src/opencv/Debug/shost.jpg";
    try{
    std::cout << "Wert: " << naocv::colorDetection(a, false) << std::endl;
    }catch(std::runtime_error& e){
        std::cout << e.what() << std::endl;
    }
    int i ;
    std::cin >> i;
    return 0;
}