#ifndef __ALGO__ALGORITHM_H__
#define __ALGO__ALGORITHM_H__

#include <vector>
#include <memory>

#include "algo/Card.hpp"
#include "algo/State.hpp"
#include "algo/Draw.hpp"

namespace algo {

    typedef std::vector<std::shared_ptr<Card>> CardVec;

    class Algorithm {

        private:

            algo::State   state;
            algo::CardVec cards;

            algo::CardVec &min;
            algo::CardVec &max;

            unsigned int accumulate_cards(void);

        public:

            explicit Algorithm(const algo::Card &minCard,
                               const algo::Card &maxCard);
            ~Algorithm();

            State getState(void);

            State update(const std::shared_ptr<const Card> card);

            std::weak_ptr<CardVec> getCards(void);

            Draw doDraw(void);

    };

}

#endif
