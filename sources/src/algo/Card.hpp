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

            friend bool operator != (const Card &c1, const Card &c2) {
                return c1.number != c2.number;
            }

            friend bool operator == (const Card &c1, const Card &c2) {
                return c1.number == c2.number;
            }


            friend bool operator < (const Card &c1, const Card &c2) {
                return c1.number < c2.number;
            }

            friend bool operator < (const Card &c1, unsigned int n) {
                return c1.number < n;
            }

            friend bool operator < (unsigned int n, const Card &c1) {
                return c1 < n;
            }


            friend bool operator <=(const Card &c1, const Card &c2) {
                return c1.number <= c2.number;
            }


            friend bool operator > (const Card &c1, const Card &c2) {
                return c1.number > c2.number;
            }

            friend bool operator > (const Card &c1, unsigned int n) {
                return c1.number > n;
            }

            friend bool operator > (unsigned int n, const Card &c1) {
                return c1 > n;
            }


            friend bool operator >=(const Card &c1, const Card &c2) {
                return c1.number >= c2.number;
            }

            operator unsigned int();

    };

}

#endif