#ifndef TBANDPASSBOX_H
#define TBANDPASSBOX_H

#include <cmath>
#include <TBox.hpp>

struct BandPassResponse { 
    float vt;
    float vb;
    float vf;
    float fb; // Hz
    float lv;
    float fl; // Hz
    float fh; // Hz
    float pa; // dB
    
};

/**
 * @todo write docs
 */
class TBandPassBox :  TBox
{
public:
    TBandPassBox(TDriver driver_);
    ~TBandPassBox();
    virtual void setVb(float vb_) = 0;
    virtual float getVb() = 0;
    
    float getQTS();
    void setQTS(float QTS_);
    
    float getVAS();
    void setVAS(float VAS_);
    
    uint getNumberOfWoofers();
    void setNumberOfWoofers(uint numberOfWoofers_);
    
    float getFS();
    void setFS(float FS_);
    
    float getPortDiameter();
    void setPortDiamenter(float portDiameter_);
    
    float getQTC();
    void setQTC(float QTC_);
    
    float getDampingFactor();
    void setDampingFactor(float dampingFactor_);

    BandPassResponse getBoxDesign(
        float _vb, 
        float _qts, 
        float _vas,
        uint _numberOfWoofers,
        float _portDiameter,
        float _qtc,
        float _dampingFactor
    ); 
    
    float getBoxResponseAtF(float f_);
    virtual TBoxResponse< float, 20, 200 > getBoxResponse() = 0;
private:
    float qts;
    float vas;
    uint numberOfWoofers;
    float portDiameter;
    float qtc;
    float dampingFactor;
};

#endif // TBANDPASSBOX_H
