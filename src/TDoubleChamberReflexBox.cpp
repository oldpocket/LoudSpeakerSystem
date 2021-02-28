#include <iostream>
#include "TDoubleChamberReflexBox.hpp"
#include "OPExceptions.hpp"
#include "OPMacros.hpp"


TDoubleChamberReflexBox::TDoubleChamberReflexBox(TDriver driver_) : TBox(driver_)
{
}

/*
  Calculate Box Response in dB vs frequency (Hz)
  @returns(array with response in dB for each frequency in Hz. Array index equals frequency)
*/
TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> TDoubleChamberReflexBox::getBoxResponse() {
  
    TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response;

    for (int f = 20; f <= MAX_FREQUENCY; f++) {
        response[f] = getBoxResponseAtF(f);
    } 

    return response;
}

float TDoubleChamberReflexBox::getBoxResponseAtF(float f_) {
    return f_;
}

float TDoubleChamberReflexBox::getVb() {
    // if we have a user-defined vb, let's return it, otherwise 
    // let's calculate dinamically
    return vb;
}

void TDoubleChamberReflexBox::setVb(float vb_) {
    vb = vb_;
}

DoubleChamberReflexResponse getBoxDesign(float _vb, float _lowerFrequency, float _portDiameter) {
    DoubleChamberReflexResponse response = {};
    
    response.largeChamberVol = _vb / 1.5f;
    response.smallChamberVol = _vb / 3;
    response.lowerFrequency = _lowerFrequency;
    response.upperFrequency = 1.93f * _lowerFrequency;
    float sv = pow(_portDiameter / 2 , 2) * 3.1416f;
    float f = _lowerFrequency / 1.126f;
    response.lvdDumpedBox = ((29290 * sv) / (pow(f,2) * response.largeChamberVol)) - _portDiameter;
    
    return response;
}

TDoubleChamberReflexBox::~TDoubleChamberReflexBox() {

}
