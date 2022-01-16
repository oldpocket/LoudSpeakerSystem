#include "TBox.hpp"


TBox::TBox(TDriver driver_) : driver(driver_) {
    
}

BoxDimension TBox::getBoxDimensions(BoxShapes boxShape_) {
    BoxDimension bd = { .0f, .0f, .0f };
    float vba = getVb();
    // metric system (vol in liters; dim, cm)
    vba = vba * 1000;
    // non-metric (vol in cu ft; dim, inches)
    // vba = vba * 1728
    
    if (boxShape_ == GOLDEN_RATIO) {    
        bd.d2 = pow(vba, .3333);
        bd.d1 = .62 * bd.d2;
        bd.d3 = 1.62 * bd.d2;
    }
    
    if (boxShape_ == FATBOX) {
        bd.d2 = pow(vba, .335);
        bd.d1 = .8 * bd.d2;
        bd.d3 = 1.2 * bd.d2;
    }
    
    if (boxShape_ == TALLBOX) {
        bd.d2 = pow(vba, .3267);
        bd.d1 = .67 * bd.d2;
        bd.d3 = 1.8 * bd.d2;    
        
    }
    
    return bd;
}


TBox::~TBox() {

}
