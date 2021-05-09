/* 
This class contains basic class types, declarations and definitions related
with Box Design calculations. All kinds of Boxes must inheritage from this
*/


#pragma once

#include "TCrossover.hpp"
#include <TDriver.hpp>
#include <stdexcept>
#include <cmath>

enum CROSSOVER_2WAY_TYPES { DB6, DB12_BUTTERWORTH, DB12_LINKWITZ_RILEY, DB18_BUTTERWORTH, DB24_L_RILEY };

class TCrossover2Way : TCrossover {
    private:
        float crossover_frequency;
    public:
        TCrossover2Way(float _crossover_frequency);
        ~TCrossover2Way();
};

