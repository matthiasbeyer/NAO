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

            algo::CardVec min;
            algo::CardVec max;

            unsigned int accumulate_cards(void);

            std::vector<Card>
            calc_possible_next_draws(const std::vector<Card>&, unsigned int);

            std::vector<Card>
            possible_draws();

        public:

            explicit Algorithm(algo::Card &minCard,
                               algo::Card &maxCard);
            ~Algorithm();

            State getState(void);

            State update(std::shared_ptr<Card> card);

            std::weak_ptr<CardVec> getCards(void);

            Draw doDraw(void);

            unsigned int get_current_sum(void);

    };

}

#endif
