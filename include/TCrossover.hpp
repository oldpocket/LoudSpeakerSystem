/* 
This class contains basic class types, declarations and definitions related
with Box Design calculations. All kinds of Boxes must inheritage from this
*/


#pragma once

#include <TDriver.hpp>
#include <stdexcept>
#include <cmath>

class TCrossover {
    protected:
    public:
        TCrossover();
        ~TCrossover();
        virtual void calculateParams() = 0;
        TDriver woofer;
        TDriver twetter;
};
