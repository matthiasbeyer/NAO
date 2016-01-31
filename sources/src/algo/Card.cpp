#include "Card.hpp"

using namespace algo;

Card::Card(unsigned int i) : number(i) {
}

Card::~Card() {
}

unsigned int
Card::getNum(void) {
    return this->number;
}

Card::operator unsigned int() {
    return this->number;
}

