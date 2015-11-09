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

        setHSVmin(Scalar(92,0,0));
        setHSVmax(Scalar(124,256,256));

        //BGR value for Green:
        setColor(Scalar(255,0,0));
    }

    if(name=="green"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        setHSVmin(Scalar(34,50,50));
        setHSVmax(Scalar(80,220,200));

        //BGR value for Yellow:
        setColor(Scalar(0,255,0));
    }

    if(name=="yellow"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        setHSVmin(Scalar(20,124,123));
        setHSVmax(Scalar(30,256,256));

        //BGR value for Red:
        setColor(Scalar(0,255,255));
    }

    if(name=="red"){
        //TODO: use "calibration mode" to find HSV min
        //and HSV max values

        setHSVmin(Scalar(0,200,0));
        setHSVmax(Scalar(19,255,255));

        //BGR value for Red:
        setColor(Scalar(0,0,255));
    }

}

Objekte::~Objekte(void)
{
}

int Objekte::getXPos(){
    return Objekte::xPos;
}

void Objekte::setXPos(int x){
    Objekte::xPos = x;
}

int Objekte::getYPos(){
    return Objekte::yPos;
}

void Objekte::setYPos(int y){
    Objekte::yPos = y;
}

Scalar Objekte::getHSVmin(){
    return Objekte::HSVmin;
}

Scalar Objekte::getHSVmax(){
    return Objekte::HSVmax;
}

void Objekte::setHSVmin(Scalar min){
    Objekte::HSVmin = min;
}

void Objekte::setHSVmax(Scalar max){
    Objekte::HSVmax = max;
}

