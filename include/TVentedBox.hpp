/*
    This Unit contains class types, declarations and definitions related with the
    Closed Box Design calculations.
*/
#pragma once

#include <cmath>
#include "TBox.hpp"

enum PortShapes { RECTANGULAR, TUBULAR };
struct PortDimension { float d1; float d2; float d3; };

class TVentedBox: public TBox {

public:
    TVentedBox(TDriver driver_);
    ~TVentedBox();
    virtual TBoxResponse<float, 20, 200> getBoxResponse() override;
    virtual float getVb() override;
    virtual void setVb(float vb_) override;

    float getBoxResponseAtF(float f_);
    PortDimension getPortDimension(PortShapes portShape_);

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
