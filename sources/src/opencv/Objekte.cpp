#include "Objekte.hpp"

Objekte::Objekte()
    : type("Objekte"),
      Color(cv::Scalar(0, 0, 0))
{
}

Objekte::Objekte(std::string name)
    : type(name)
{
    if (name=="blue") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        this->setHSVmin(cv::Scalar(105, 190, 120));
        this->setHSVmax(cv::Scalar(130, 240, 200));

        //BGR value for Blue:
        this->setColor(cv::Scalar(255, 0, 0));
    }

    if (name=="green") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        this->setHSVmin(cv::Scalar(35, 55, 100));
        this->setHSVmax(cv::Scalar(85, 255, 255));

        //BGR value for Green:
        this->setColor(cv::Scalar(0, 255, 0));
    }

     if (name=="greendark") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        this->setHSVmin(cv::Scalar(40, 90, 20));
        this->setHSVmax(cv::Scalar(140, 200, 100));

        //BGR value for Green:
        this->setColor(cv::Scalar(0, 255, 0));
    }

    if (name=="yellow") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        this->setHSVmin(cv::Scalar(1, 124, 123));
        this->setHSVmax(cv::Scalar(35, 255, 255));

        //BGR value for Yellow:
        this->setColor(cv::Scalar(0, 255, 255));
    }

	if (name=="red") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

		this->setHSVmin(cv::Scalar(0, 110, 130));
		this->setHSVmax(cv::Scalar(20, 255, 255));

        //BGR value for Red:
		this->setColor(cv::Scalar(0, 0, 255));
	}

    if (name=="red2") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

	    this->setHSVmin(cv::Scalar(0, 180, 170));
	    this->setHSVmax(cv::Scalar(200, 250, 240));

        //BGR value for Red:
	    this->setColor(cv::Scalar(0, 0, 255));
	}

    if (name=="cyan") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

		//his->setHSVmin(cv::Scalar(90, 80, 60));
        this->setHSVmin(cv::Scalar(100, 80, 60));
		this->setHSVmax(cv::Scalar(120, 230, 255));

        //BGR value for Cyan:
		this->setColor(cv::Scalar(255, 255, 0));
    }

    if (name=="magenta") {
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

		this->setHSVmin(cv::Scalar(135, 85, 50));
		this->setHSVmax(cv::Scalar(170, 255, 255));

        //BGR value for Magenta:
		this->setColor(cv::Scalar(255, 0, 255));
    }
}

Objekte::~Objekte(void)
{
}

int Objekte::getXPos() {
    return this->xPos;
}

void Objekte::setXPos(int x) {
    this->xPos = x;
}

int Objekte::getYPos() {
    return this->yPos;
}

void Objekte::setYPos(int y) {
    this->yPos = y;
}

cv::Scalar Objekte::getHSVmin() {
    return this->HSVmin;
}

cv::Scalar Objekte::getHSVmax() {
    return this->HSVmax;
}

void Objekte::setHSVmin(cv::Scalar min) {
    this->HSVmin = min;
}

void Objekte::setHSVmax(cv::Scalar max) {
    this->HSVmax = max;
}