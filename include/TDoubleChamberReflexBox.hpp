/*
    This Unit contains class types, declarations and definitions related with the
    Closed Box Design calculations.
*/
#pragma once

#include <cmath>
#include "TBox.hpp"

struct DoubleChamberReflexResponse { 
    float upperFrequency; 
    float lowerFrequency; 
    float largeChamberVol;
    float smallChamberVol;
    float portDiameter;
    float lvdDumpedBox;
    
};

class TDoubleChamberReflexBox: public TBox {

public:
    TDoubleChamberReflexBox(TDriver driver_);
    ~TDoubleChamberReflexBox();
    virtual TBoxResponse<float, 20, 200> getBoxResponse() override;
    float getBoxResponseAtF(float f_);
    
    virtual void setVb(float vb_) override;
    virtual float getVb() override;

    DoubleChamberReflexResponse getBoxDesign(float _vb, float _lowerFrequency, float _portDiameter); 
    
    
private:
    
};
