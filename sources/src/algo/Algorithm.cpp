#include "algo/Algorithm.hpp"

#include "algo/Card.hpp"
#include "algo/Draw.hpp"
#include "algo/State.hpp"

using namespace algo;

#define WINNERS_NUMBER (21)

Algorithm::Algorithm(const Card &minCard, const Card &maxCard)
    : state(NOT_STARTED)
    , card_vec()
    , min(minCard)
    , max(maxCard)
{
}

Algorithm::~Algorithm()
{
}

State
Algorithm::getState(void)
{
    return this->state;
}

State
Algorithm::update(const std::shared_ptr<const Card> card)
{
    this->cards.push_back(card);
    auto acc = this->accumulate_cards();

    if (acc < WINNERS_NUMBER) {
        this->state = PLAYING;
    } else if (acc == WINNERS_NUMBER) {
        this->state = WON;
    } else if (acc > WINNERS_NUMBER) {
        this->state = PLAYING
    }

    return this->state;
}

std::weak_ptr<CardVec>
Algorithm::getCards(void)
{
    auto p = std::make_shared<CardVec>(this->cards);
    return p;
}

Draw
Algorithm::doDraw(void)
{
    unsigned int sum = this->accumulate_cards();

    // naiive implementation
    if (sum < WINNERS_NUMBER) {
        return YES_SURE;
    } else {
        return NO_SURE;
    }
}

unsigned int
Algorithm::accumulate_cards(void)
{
    unsigned int init = 0;
    return std::accumulate(this->cards.begin(), this->cards.end(), init,
            [](unsigned int i, std::shared_ptr<Card> c) {
                return i + c.getNum();
            });
}

