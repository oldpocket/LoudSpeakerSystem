#include "TBandPassBox.hpp"
#include "OPExceptions.hpp"
#include "OPMacros.hpp"

TBandPassBox::TBandPassBox(TDriver driver_) : TBox(driver_) {

}

TBandPassBox::~TBandPassBox()
{

}

void TBandPassBox::setVb(float vb_)
{
    vb = vb_;
}

float TBandPassBox::getVb()
{
    return vb;
}

BandPassResponse getBoxDesign(
        float _vb, 
        float _qts, 
        float _vas,
        uint _numberOfWoofers,
        float _fs,
        float _portDiameter,
        float _qtc,
        float _dampingFactor) {
    BandPassResponse response = {};
    
    float vn = _vas * _numberOfWoofers;
    float vb = vn / (pow(_qtc / _qts, 2) - 1);
    float vf = pow(2 * _dampingFactor * _qts, 2) * vn;
    float a  = vn / vb;
    float fc = _fs * sqrt(a + 1);
    float fb = fc;
    float vt = vb +vf;
    float sv = pow(_portDiameter / 2, 2) * 3.1416;
    a = 0.00037 * pow(fb, 2);
    float lv = (sv / a) - (0.83 * sqrt(sv));
    float fl = (_fs / _qts) * (((-.4208 + (.6914 * _dampingFactor)) - (.4 * pow(_dampingFactor, 2))) + (((.4796 + (.1076 *         _dampingFactor)) + (.34 * pow(_dampingFactor, 2))) * _qtc) + ((.0133 + (.3863 * _dampingFactor)) - (.295 * pow(_dampingFactor,2))) * pow(_qtc, 2));
    float fh = (_fs / _qts) * (((4.0731 - (8.3403 * _dampingFactor)) + (4.8075 * pow(_dampingFactor, 2))) +
        (((.4796 + (.1076 * _dampingFactor)) + (.34 * pow(_dampingFactor, 2))) * _qtc) + ((-.0133 + (.3863 * _dampingFactor)) - (.295 * pow(_dampingFactor, 2))) * pow(_qtc, 2));
    float pa =  -26.13 + ((-.2202 + (68.53 * _dampingFactor)) * _qtc) + ((.4086 - 1.3448 * _dampingFactor) - (30.62 * pow(_dampingFactor, 2))) * pow(_qtc, 2);
    
    response.vt = vt;
    response.vb = vb;
    response.fb = fb;
    response.lv = lv;
    response.fl = fl;
    response.fh = fh;
    response.pa = pa;
    response.vf = vf;
    
    return response;
}

float TBandPassBox::getBoxResponseAtF(float f_) {
    return f_;
}

TBoxResponse< float, MIN_FREQUENCY, MAX_FREQUENCY > TBandPassBox::getBoxResponse()
{
    TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response;

    for (int f = 20; f <= MAX_FREQUENCY; f++) {
        response[f] = getBoxResponseAtF(f);
    } 

    return response;
}
