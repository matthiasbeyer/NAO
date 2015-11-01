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

    };

}

#endif
