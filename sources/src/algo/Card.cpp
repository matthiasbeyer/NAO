#include "algo/Card.hpp"

using namespace algo;

Card::Card(unsigned int i) : number(i) {
}

Card::~Card() {
}

unsigned int
Card::getNum(void) {
    return this->number;
}

bool operator != (Card &c1, Card &c2)
{
    return c1.number != c2.number;
}

bool operator == (Card &c1, Card &c2)
{
    return c1.number == c2.number;
}

bool operator < (Card &c1, Card &c2)
{
    return c1.number < c2.number;
}

bool operator <=(Card &c1, Card &c2)
{
    return c1.number <= c2.number;
}

bool operator > (Card &c1, Card &c2)
{
    return c1.number > c2.number;
}

bool operator >=(Card &c1, Card &c2)
{
    return c1.number >= c2.number;
}

Card::operator unsigned int() {
    return this->number;
}

