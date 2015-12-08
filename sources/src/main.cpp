/*
 * main.cpp
 *
 * Main file which contains the main routine. We do the high-level stuff here.
 *
 */

#include "algo/Algorithm.hpp"
#include "algo/Card.hpp"

int main(void)
{
    nao::algo::Card min = 1;
    nao::algo::Card max = 6;
    nao::algo::Algorithm algo(min, max);

    // Introduction
    nao::behaviour::intro();

    // Find Cube
    auto cube = nao::behaviour::find_cube();
    if (!cube) {
        nao::behaviour::abort("Cannot find cube");
        exit(1);
    }

    // Go to cube
    auto b = nao::behaviour::go_to(cube);
    if (!b) {
        nao::behaviour::abort("Cannot goto cube");
    }

    do {
        nao::behaviour::throw_cube(cube); // Throw cube

        cube = nao::behaviour::find_cube(); // find/goto cube
        if (!cube) {
            nao::behaviour::abort("Cannot find cube");
            break;
        }

        auto b = nao::behaviour::go_to(cube);
        if (!b) {
            nao::behaviour::abort("Cannot goto cube");
            break;
        }

        auto analyzed = nao::behaviour::analyze_cube(); // analyze cube-color
        algo.update(analyzed); // Game step
    } while (algo.doDraw()); // as long as game algo says yes

    // Outro
    nao::behaviour::outro();
}
