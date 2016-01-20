#include "ImageLoader.hpp"

using namespace imgloader;

ImageLoader::ImageLoader(std::string robotIp, std::string path){
    pathToFile = path;
    initializeVideoProxy(robotIp);
}

void ImageLoader::initializeVideoProxy(std::string &robotIp) {
    globalVideoProxy = std::make_shared<AL::ALVideoDeviceProxy>(robotIp, 9559);
    globalVideoProxy->setActiveCamera(1);
}

void ImageLoader::getImage(){
    /** Subscribe a client image requiring 320*240 and BGR colorspace.
    AL::kQQQQVGA	8	Image of 40*30px
    AL::kQQQVGA	7	Image of 80*60px
    AL::kQQVGA	0	Image of 160*120px
    AL::kQVGA	1	Image of 320*240px
    AL::kVGA	2	Image of 640*480px
    AL::k4VGA	3	Image of 1280*960px  */
    const std::string clientName = globalVideoProxy->subscribe("imgloader", AL::k4VGA, AL::kBGRColorSpace, 5);

    /** Create an cv::Mat header to wrap into an opencv image.*/
    cv::Mat imgHeader = cv::Mat(cv::Size(1280, 960), CV_8UC3);

    //TODO: only show
    /** Create a OpenCV window to display the images. */
    //cv::namedWindow("images");

    /** Main loop. Exit when pressing ESC.*/

    /** Retrieve an image from the camera.
    * The image is returned in the form of a container object, with the
    * following fields:
    * 0 = width
    * 1 = height
    * 2 = number of layers
    * 3 = colors space index (see alvisiondefinitions.h)
    * 4 = time stamp (seconds)
    * 5 = time stamp (micro seconds)
    * 6 = image buffer (size of width * height * number of layers)
    */
    AL::ALValue img = globalVideoProxy->getImageRemote(clientName);

    /** Access the image buffer (6th field) and assign it to the opencv image
    * container. */
    imgHeader.data = (uchar*) img[6].GetBinary();

    /** Tells to ALVideoDevice that it can give back the image buffer to the
    * driver. Optional after a getImageRemote but MANDATORY after a getImageLocal.*/
    globalVideoProxy->releaseImage(clientName);

    /** Cleanup.*/
    globalVideoProxy->unsubscribe(clientName);
    
    cv::imwrite(pathToFile, imgHeader);
}

ImageLoader::~ImageLoader(void){
}