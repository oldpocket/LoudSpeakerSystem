/* 
This class contains basic class types, declarations and definitions related
with Box Design calculations. All kinds of Boxes must inheritage from this
*/


#pragma once

#include "TCrossover.hpp"
#include <TDriver.hpp>
#include <stdexcept>
#include <cmath>

enum CROSSOVER_3WAY_TYPES { PARALLEL, SERIES };

class TCrossover3Way : TCrossover {
    private:
        float crossover_low_frequency;
        float crossover_high_frequency;
    public:
        TCrossover3Way(float _crossover_low_frequency, float _crossover_high_frequency);
        ~TCrossover3Way();
        TDriver midranger;
};

