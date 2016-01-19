#pragma once

#include <string>

namespace naocv {

    enum Farbe {
        CYAN = 1,
        RED,
        YELLOW,
        GREEN,
        MAGENTA,
        BLUE,
    };

    struct FarbPos {

        std::string farbe;
        int         xPos;
        int         yPos;
        int         size;

        FarbPos(std::string c, int x, int y, int s): farbe(c), xPos(x), yPos(y), size(s) {
        }

        FarbPos(){}

        friend bool
        FarbPos::operator < (const FarbPos &self, const FarbPos &other) {
            return self.yPos < other.yPos;
        }

        friend bool
        FarbPos::operator > (const FarbPos &self, const FarbPos &other) {
            return self.yPos > other.yPos;
        }

        friend bool
        FarbPos::operator >= (const FarbPos &self, const FarbPos &other) {
            return self.yPos >= other.yPos;
        }

        friend bool
        FarbPos::operator <= (const FarbPos &self, const FarbPos &other) {
            return self.yPos <= other.yPos;
        }

        friend bool
        FarbPos::operator == (const FarbPos &self, const FarbPos &other) {
            return self.yPos == other.yPos;
        }

        friend bool
        FarbPos::operator != (const FarbPos &self, const FarbPos &other) {
            return self.yPos != other.yPos;
        }

        operator int() {
            return this->yPos;
        }

        operator std::string() {
            return this->farbe;
        }

        operator Farbe() {
            if (this->farbe == "cyan" || this->farbe == "cyandark"){
                return CYAN;
            }

            if (this->farbe == "red" || this->farbe == "reddark"){
                return RED;
            }

            if (this->farbe == "yellow" || this->farbe == "yellowdark" ||this->farbe == "yellowthree"){
                return YELLOW;
            }

            if (this->farbe == "green" || this->farbe == "greendark"){
                return GREEN;
            }

            if (this->farbe == "magenta"){
                return MAGENTA;
            }

            if (this->farbe == "blue" || this->farbe ==  "bluedark"){
                return BLUE;
            }
        }
    };

}