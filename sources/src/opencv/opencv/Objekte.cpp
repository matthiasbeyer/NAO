#include "Objekte.h"

Objekte::Objekte()
{
    //set values for default constructor
    setType("Objekte");
    setColor(Scalar(0,0,0));
}

Objekte::Objekte(string name){

    setType(name);

    if(name=="blue"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        setHSVmin(Scalar(105,90,120));
        setHSVmax(Scalar(130,255,255));

        //BGR value for Green:
        setColor(Scalar(255,0,0));
    }

    if(name=="green"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        setHSVmin(Scalar(35,70,100));
        setHSVmax(Scalar(85,255,255));

        //BGR value for Yellow:
        setColor(Scalar(0,255,0));
    }

    if(name=="yellow"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        setHSVmin(Scalar(1,124,123));
        setHSVmax(Scalar(35,255,255));

        //BGR value for Red:
        setColor(Scalar(0,255,255));
    }
	if(name=="red"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

		setHSVmin(Scalar(0,110,130));
		setHSVmax(Scalar(20,255,255));

        //BGR value for Red:
		setColor(Scalar(0,0,255));
	}
    if(name=="red2"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

	    setHSVmin(Scalar(170,120,170));
	    setHSVmax(Scalar(180,140,200));

        //BGR value for Red:
	    setColor(Scalar(0,0,255));
	}
    if(name=="cyan"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

		setHSVmin(Scalar(90,105,130));
		setHSVmax(Scalar(105,255,255));

        //BGR value for Cyan:
		setColor(Scalar(255,255,0));
    }
    if(name=="magenta"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

		setHSVmin(Scalar(135,85,150));
		setHSVmax(Scalar(150,256,256));

        //BGR value for Magenta:
		setColor(Scalar(255,0,255));
    }
}

Objekte::~Objekte(void)
{
}

int Objekte::getXPos(){
    return this->xPos;
}

void Objekte::setXPos(int x){
    this->xPos = x;
}

int Objekte::getYPos(){
    return this->yPos;
}

void Objekte::setYPos(int y){
    this->yPos = y;
}

Scalar Objekte::getHSVmin(){
    return this->HSVmin;
}

Scalar Objekte::getHSVmax(){
    return this->HSVmax;
}

void Objekte::setHSVmin(Scalar min){
    thix->HSVmin = min;
}

void Objekte::setHSVmax(Scalar max){
    this->HSVmax = max;
}

