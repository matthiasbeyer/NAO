#ifndef __ALGO__ALGORITHM_H__
#define __ALGO__ALGORITHM_H__

#include <vector>
#include <memory>

namespace algo {

    typedef std::vector<std::shared_ptr<Card>> CardVec;

    class Algorithm {
        private:

            State   state;
            CardVec cards;

        public:

            Algorithm() explicit;
            ~Algorithm();

            State getState(void);

            State update(const std::shared_ptr<const Card> card);

            std::weak_ptr<CardVec> getCards(void);

            Draw doDraw(void);
    }

}

#endif
