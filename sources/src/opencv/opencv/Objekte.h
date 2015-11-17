#pragma once
#include <string>
#include <opencv\cv.h>
#include <opencv\highgui.h>

using namespace cv;

class Objekte
{
    public:

        Objekte();
        ~Objekte(void);

        Objekte(std::string name);

        int getXPos();
        void setXPos(int x);

        int getYPos();
        void setYPos(int y);

        Scalar getHSVmin();
        Scalar getHSVmax();

        void setHSVmin(Scalar min);
        void setHSVmax(Scalar max);

        std::string getType() {
            return type;
        }

        void setType(std::string t){
            type = t;
        }

        Scalar getColor() {
            return Color;
        }

        void setColor(Scalar c) {
            this->Color = c;
        }

    private:

        int             xPos;
        int             yPos;
        std::string     type;
        Scalar          HSVmin;
        Scalar          HSVmax;
        Scalar          Color;
};
