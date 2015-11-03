#include "algo/Draw.hpp"

using namespace algo;

Draw::Draw(signed short certainty) : __certainty(certainty) {
}

Draw::operator char() {
    return this->certainty();
}

Draw::operator bool() {
    return this->doDraw();
}

char
Draw::certainty() {
    return (char) ((this->__certainty > 100) ? 100 : this->__certainty);
}

bool
Draw::doDraw() {
    return this->__certainty > 0;
}


