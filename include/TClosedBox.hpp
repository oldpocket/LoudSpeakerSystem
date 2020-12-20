/*
    This Unit contains class types, declarations and definitions related with the
    Closed Box Design calculations.
*/
#pragma once

#include <cmath>
#include "TBox.hpp"

class TClosedBox: public TBox {

public:
    TClosedBox(TDriver driver_);
    ~TClosedBox();
    virtual TBoxResponse<float, 20, 200> getBoxResponse() override;

    // Box Volume
    float vb;
    // Alpha
    float getA();
    float getFC();
    float getQTC();
    // System cut-off frequency (f3)
    float getF3();
};
