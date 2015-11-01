#ifndef __ALGO_CARD_H__
#define __ALGO_CARD_H__

namespace algo {

    class Card {
        private:

            unsigned int number;

        public:

            Card(unsigned int);
            ~Card();

            unsigned int getNum(void);

            friend bool operator != (Card &c1, Card &c2) {
                return c1.number != c2.number;
            }

            friend bool operator == (Card &c1, Card &c2) {
                return c1.number == c2.number;
            }

            friend bool operator < (Card &c1, Card &c2) {
                return c1.number < c2.number;
            }

            friend bool operator <=(Card &c1, Card &c2) {
                return c1.number <= c2.number;
            }

            friend bool operator > (Card &c1, Card &c2) {
                return c1.number > c2.number;
            }

            friend bool operator >=(Card &c1, Card &c2) {
                return c1.number >= c2.number;
            }

            operator unsigned int();

    };

}

#endif
