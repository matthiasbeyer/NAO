#include "Draw.hpp"

using namespace algo;

Draw::Draw(signed short certainty) : __certainty(certainty) {
}

Draw::operator signed short() {
    return this->certainty();
}

Draw::operator bool() {
    return this->doDraw();
}

signed short
Draw::certainty() {
    return this->__certainty;
}

bool
Draw::doDraw() {
    return this->__certainty > 0;
}