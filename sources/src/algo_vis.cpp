#include <iostream>
#include <random>

#include "algo/Algorithm.hpp"
#include "algo/State.hpp"
#include "algo/Card.hpp"
#include "algo/Draw.hpp"

#define NUM_MIN (1)
#define NUM_MAX (7)

bool step(algo::Algorithm &a, unsigned int next_draw) {
    if (a.doDraw()) {
        std::cout << "Drawing with certainty: "
                  << (signed short) a.doDraw()
                  << std::endl;

        const auto c = std::make_shared<algo::Card>(next_draw);

        std::cout << "Algorithm draws: " << next_draw << std::endl;
        auto state = a.update(c);
        std::cout << "Algorithm has: " << a.get_current_sum() << std::endl;

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
    } else {
        std::cout << "Game ends because Algorithm doesn't want to draw: "
                  << (signed short) a.doDraw() << std::endl;
    }

    return a.doDraw();
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
