/*
    This Unit contains class types, declarations and definitions related with the
    Closed Box Design calculations.
*/
#pragma once

#include <cmath>
#include "TBox.hpp"

class TVentedBox: public TBox {

public:
    TVentedBox(TDriver driver_);
    ~TVentedBox();
    virtual TBoxResponse<float, 20, 200> getBoxResponse() override;

    // Box Volume - dinamically calculated or last user-defined value
    float getVB();
    void setVB(float vb_);
    // Box Resonance frequency
    float getFB();
    // Box Cut-off frequency
    float getF3();
    // Peak or Dip in Response
    float getH();
private:
    // Store user-defined VB
    float vb;
};
