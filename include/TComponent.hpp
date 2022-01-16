/* 
This class contains basic class types, declarations and definitions related
with Box Design calculations. All kinds of Boxes must inheritage from this
*/


#pragma once

#include <TDriver.hpp>
#include <stdexcept>
#include <cmath>

class TComponent {
    protected:
        float value;
    public:
        TComponent();
        float getValue() { return value; }
        void setValue(float _value) { value = _value; }
        ~TComponent();
};

class TComponentResistor : TComponent
{
    
};

class TComponentCoil : TComponent
{
};

class TComponentCapacitor : TComponent
{
};
