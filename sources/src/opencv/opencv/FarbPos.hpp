#pragma once

#include <string>

namespace naocv {

    enum Farbe {
        CYAN = 1,
        RED = 2,
        YELLOW = 3,
        GREEN = 4,
        MAGENTA = 5,
        BLUE = 6,
    };

    struct FarbPos {

        std::string farbe;
        int         yPos;

        FarbPos(std::string s, int i): farbe(s), yPos(i) {
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
            if (this->farbe == "cyan"){
                return CYAN;
            }

            if (this->farbe == "red" || this->farbe == "red2"){
                return RED;
            }

            if (this->farbe == "yellow"){
                return YELLOW;
            }

            if (this->farbe == "green"){
                return GREEN;
            }

            if (this->farbe == "magenta"){
                return MAGENTA;
            }

            if (this->farbe == "blue"){
                return BLUE;
            }
        }
    };

}
