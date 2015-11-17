#pragma once

#include <string>

namespace naocv {

    int run(const std::string& pathToFile,
            bool calibrationMode = true,
            bool videoMode = false);

}
