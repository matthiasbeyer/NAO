#pragma once
#include <string>
#include <opencv\cv.h>
#include <opencv\highgui.h>

using namespace std;
using namespace cv;

class Objekte
{
    public:

        Objekte();
        ~Objekte(void);

        Objekte(string name);

        int getXPos();
        void setXPos(int x);

        int getYPos();
        void setYPos(int y);

        Scalar getHSVmin();
        Scalar getHSVmax();

        void setHSVmin(Scalar min);
        void setHSVmax(Scalar max);

        string getType() {
            return type;
        }

        void setType(string t){
            type = t;
        }

        Scalar getColor() {
            return Color;
        }

        void setColor(Scalar c) {
            this->Color = c;
        }

    private:

        int     xPos;
        int     yPos;
        string  type;
        Scalar  HSVmin;
        Scalar  HSVmax;
        Scalar  Color;
};
