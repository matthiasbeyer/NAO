#ifndef __ALGO__ALGORITHM_H__
#define __ALGO__ALGORITHM_H__

#include <vector>
#include <memory>

#include "algo/Card.hpp"

namespace algo {

    typedef std::vector<const std::shared_ptr<const Card>> CardVec;

    class Algorithm {

        private:

            State   state;
            CardVec cards;

            CardVec &min;
            CardVec &max;

            unsigned int accumulate_cards(void);

        public:

            Algorithm(const Card &minCard, const Card &maxCard) explicit;
            ~Algorithm();

            State getState(void);

            State update(const std::shared_ptr<const Card> card);

            std::weak_ptr<CardVec> getCards(void);

            Draw doDraw(void);

    }

}

#endif
