#ifndef TBANDPASSBOX_H
#define TBANDPASSBOX_H

#include <TBox.hpp>

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

    float getBoxResponseAtF(float f_);
    virtual TBoxResponse< float, 20, 200 > getBoxResponse() = 0;

};

#endif // TBANDPASSBOX_H
