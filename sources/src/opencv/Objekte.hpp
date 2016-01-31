#pragma once

// Opencv includes.
#include <opencv\cv.h>

#include <string>

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

        cv::Scalar getHSVmin();
        cv::Scalar getHSVmax();

        void setHSVmin(cv::Scalar min);
        void setHSVmax(cv::Scalar max);

        std::string getType() {
            return type;
        }

        void setType(std::string t){
            type = t;
        }

        cv::Scalar getColor() {
            return Color;
        }

        void setColor(cv::Scalar c) {
            this->Color = c;
        }

    private:

        int             xPos;
        int             yPos;
        std::string     type;
        cv::Scalar      HSVmin;
        cv::Scalar      HSVmax;
        cv::Scalar      Color;
};