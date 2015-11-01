#include <iostream>
#include <random>

#include "algo/Algorithm.hpp"
#include "algo/State.hpp"
#include "algo/Card.hpp"
#include "algo/Draw.hpp"

#define NUM_MIN (1)
#define NUM_MAX (7)

bool step(algo::Algorithm &a, unsigned int next_draw) {
    switch (a.doDraw()) {
        case algo::Draw::NO_SURE:
        case algo::Draw::NO_UNUSURE:
        case algo::Draw::NO_NERVOUS:
            std::cout << "No more drawing..." << std::endl;
            return false;
            break;

        case algo::Draw::YES_SURE:
        case algo::Draw::YES_UNUSURE:
        case algo::Draw::YES_NERVOUS:
        {
            const auto c = std::make_shared<algo::Card>(next_draw);

            auto state = a.update(c);

            switch (state) {
                case algo::State::NOT_STARTED:
                case algo::State::PLAYING:
                    std::cout << "Game will continue" << std::endl;
                    return true;

                case algo::State::HALTED:
                    std::cout << "Game halted by algorithm" << std::endl;
                    return false;

                case algo::State::WON:
                    std::cout << "Game halted by algorithm: Won" << std::endl;
                    return false;

                case algo::State::LOST:
                    std::cout << "Game halted by algorithm: Lost" << std::endl;
                    return false;

            }

            break;
        }
    }

    return true;
}

int
main(void) {
    std::random_device rd;
    std::default_random_engine randengine(rd());
    std::uniform_int_distribution<int> uniform_dist(NUM_MIN, NUM_MAX);

    algo::Card min(NUM_MIN);
    algo::Card max(NUM_MAX);

    algo::Algorithm a(min, max);

    while (step(a, uniform_dist(randengine)));

    return 0;
}
