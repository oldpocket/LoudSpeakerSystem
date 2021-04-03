#include "TBandPassBox.h"
#include "OPExceptions.hpp"
#include "OPMacros.hpp"

TBandPassBox::TBandPassBox(TDriver driver_) : TBox(driver_) {

}

TBandPassBox::~TBandPassBox()
{

}

void TBandPassBox::setVb(float vb_)
{
    vb = vb_;
}

float TBandPassBox::getVb()
{
    return vb;
}

float TBandPassBox::getBoxResponseAtF(float f_) {
    return f_;
}

TBoxResponse< float, MIN_FREQUENCY, MAX_FREQUENCY > TBandPassBox::getBoxResponse()
{
    TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response;

    for (int f = 20; f <= MAX_FREQUENCY; f++) {
        response[f] = getBoxResponseAtF(f);
    } 

    return response;
}
