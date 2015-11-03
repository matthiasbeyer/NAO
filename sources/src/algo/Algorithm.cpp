#include <numeric>
#include <algorithm>

#include "algo/Algorithm.hpp"

#include "algo/Card.hpp"
#include "algo/Draw.hpp"
#include "algo/State.hpp"

using namespace algo;

#define WINNERS_NUMBER (21)

Algorithm::Algorithm(Card &minCard, Card &maxCard)
    : state(NOT_STARTED)
    , cards()
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
Algorithm::update(std::shared_ptr<Card> card)
{
    this->cards.push_back(card);
    auto acc = this->get_current_sum();

    if (acc < WINNERS_NUMBER) {
        this->state = PLAYING;
    } else if (acc == WINNERS_NUMBER) {
        this->state = WON;
    } else if (acc > WINNERS_NUMBER) {
        this->state = LOST;
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
    unsigned int sum = this->get_current_sum();

    // naiive implementation
    if (sum < WINNERS_NUMBER) {
        return Draw(100);
    } else {
        return Draw(-100);
    }
}

unsigned int
Algorithm::get_current_sum(void)
{
    unsigned int init = 0;
    return std::accumulate(this->cards.begin(), this->cards.end(), init,
            [](unsigned int i, std::shared_ptr<Card> c) {
                return i + c->getNum();
            });
}

std::vector<Card>
Algorithm::calc_possible_next_draws(const std::vector<Card> &v, unsigned int sum)
{
    std::vector<Card> res = v;
    std::remove_if(res.begin(), res.end(),
            [sum](const Card &c) {
                return c < (WINNERS_NUMBER - sum);
            });
    return std::move(res);
}

std::vector<Card>
Algorithm::possible_draws() {
    auto vec = std::vector<Card>();
    for (unsigned int i = this->min; i < this->max; ++i) {
        vec.push_back(Card(i));
    }
    return vec;
}

