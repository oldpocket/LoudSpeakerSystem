/* 
This class contains basic class types, declarations and definitions related
with Box Design calculations. All kinds of Boxes must inheritage from this
*/


#pragma once

#include <TDriver.hpp>
#include <stdexcept>
#include <cmath>

enum BoxShapes { GOLDEN_RATIO, FATBOX, TALLBOX };
struct BoxDimension { float d1; float d2; float d3; };

template <class T, int lowerReponse, int upperReponse>
class TBoxResponse {
    T data[upperReponse-lowerReponse];
public:
    T &operator[](int index) { 
        if (index < lowerReponse || index > upperReponse)
            throw std::range_error("Frequency out of range");
        return data[index-lowerReponse]; 
    }
    T *begin() { return data; }
    T *end() { return data + (upperReponse-lowerReponse); }
};


class TBox {
    protected:
        float vb;
    public:
        TBox(TDriver driver_);
        ~TBox();
        TDriver driver;
        virtual TBoxResponse<float, 20, 200> getBoxResponse() = 0;
        virtual float getVb() = 0;
        virtual void setVb(float vb_) = 0;
        BoxDimension getBoxDimensions(BoxShapes boxShape_);
};
