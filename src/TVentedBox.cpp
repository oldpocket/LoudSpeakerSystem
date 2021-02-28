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
  
    TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response;

    for (int f = 20; f <= MAX_FREQUENCY; f++) {
        response[f] = getBoxResponseAtF(f);
    } 

    return response;
}

float TVentedBox::getBoxResponseAtF(float f_) {
    
    float a = pow(getFB(), 2) / pow(driver.fs, 2);
    float b = a / driver.getQTS() + ( getFB() / (7 * driver.fs) );
    float c = 1 + a + (getFB() / (7 * driver.fs * driver.getQTS())) + (driver.getVAS() / getVb());
    float d = 1 / driver.getQTS() + ( getFB() / (7 * driver.fs) );

    float f9, f5, f4, f3, f6, f7;
    
    f9 = f_ / driver.fs;
    f3 = pow(f9, 3);
    f4 = pow(f9, 4);
    f5 = pow(f9, 2);
    f6 = pow(f4- c * f5 + a, 2);
    f7 = pow(b * f9 - d * f3, 2);
    float response = 20 * (log(pow(f4 / (f6+f7), .5)) / log(10));
    
    return response;
}

PortDimension TVentedBox::getPortDimension(PortShapes portShape_, float lenght_) {
    PortDimension pd = { .0f, .0f, .0f };
    
    if (portShape_ == TUBULAR) {
        float Vb = getVb();
        float Fb = getFB();
        float D = lenght_;
        float SV = pow(D/2, 2) * 3.1416;
        float A = .0000332 * Vb * Fb * Fb;
        float L = (SV / A) - (.83 * SQR(SV));
        float LVD = ((29290 * SV) / (Fb * Fb * Vb)) - D;
        
    }
    
    if (portShape_ == RECTANGULAR) {
    }
    
    return pd;
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
    if (getVb() == 0) throw DivideByZeroException();
    
    return 20 * log( 2.6 * driver.getQTS() * pow(driver.getVAS() / getVb(), .35) ) / log(10);
}


float TVentedBox::getVb() {
    // if we have a user-defined vb, let's return it, otherwise 
    // let's calculate dinamically
    return vb == 0 ? 15 * pow(driver.getQTS(), 2.87) * driver.getVAS() : vb;
}

void TVentedBox::setVb(float vb_) {
    vb = vb_;
}
