#include <iostream>
#include "TVentedBox.hpp"
#include "OPExceptions.hpp"
#include "OPMacros.hpp"


TVentedBox::TVentedBox(TDriver driver_) : TBox(driver_) {
    vb = 0;
}

TVentedBox::~TVentedBox() {

}

/*
  Calculate Box Response in dB vs frequency (Hz)
  @returns(array with response in dB for each frequency in Hz. Array index equals frequency)
*/
TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> TVentedBox::getBoxResponse() {

    float a = pow(getFB(), 2) / pow(driver.fs, 2);
    float b = a / driver.getQTS() + ( getFB() / (7 * driver.fs) );
    float c = 1 + a + (getFB() / (7 * driver.fs * driver.getQTS())) + (driver.getVAS() / getVB());
    float d = 1 / driver.getQTS() + ( getFB() / (7 * driver.fs) );

    float f9, f5, f4, f3, f6, f7;
    TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response;

    for (int f = 20; f <= MAX_FREQUENCY; f++) {
        f9 = f / driver.fs;
        f3 = pow(f9, 3);
        f4 = pow(f9, 4);
        f5 = pow(f9, 2);
        f6 = pow(f4- c * f5 + a, 2);
        f7 = pow(b * f9 - d * f3, 2);
        response[f] = 20 * (log(pow(f4 / (f6+f7), .5)) / log(10));
    } 

    return response;
}

float TVentedBox::getF3() {
    
    if (vb == 0)
        return .26 * pow(driver.getQTS(), -1.4) * driver.fs;
    
    return driver.fs * sqrt( driver.getVAS() / vb);
}


float TVentedBox::getFB() {

    if (vb == 0)
        return .42 * pow(driver.getQTS(), -.9) * driver.fs;

    return driver.fs * pow( driver.getVAS() / vb, .32);
}

float TVentedBox::getH() {
    if (getVB() == 0) throw DivideByZeroException();
    
    return 20 * log( 2.6 * driver.getQTS() * pow(driver.getVAS() / getVB(), .35) ) / log(10);
}


float TVentedBox::getVB() {
    // if we have a user-defined vb, let's return it, otherwise 
    // let's calculate dinamically
    return vb == 0 ? 15 * pow(driver.getQTS(), 2.87) * driver.getVAS() : vb;
}

void TVentedBox::setVB(float vb_) {
    vb = vb_;
}
