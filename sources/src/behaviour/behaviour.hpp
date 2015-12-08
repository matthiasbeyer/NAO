#include "behaviour/Cube.hpp"

namespace nao {

    namespace behaviour {

        void intro(void);
        void abort(std::string msg);

        nao::Cube find_cube(void);
        void throw_cube(nao::Cube& c);
        bool go_to(nao::Cube& c);

        nao::AnalyzedCube analyze_cube();

    }

}
