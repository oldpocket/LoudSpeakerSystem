#include <cmath>
#include "TDriver.hpp"

TDriver::TDriver() {

}

TDriver::~TDriver() {

}

/* Calculate and returns VAS value on the fly, using current Driver parameters
  @returns(the calculate VAS in Liters or Cu.Ft.)}
*/
float TDriver::getVAS()
{
  return tvb * (1.149 * (pow(2, tfs / fs) - 1));
}

/* Calculate and returns QTS value on the fly, using current Driver parameters
  @returns(the calculate QTS value)
*/
float TDriver::getQTS()
{
    float qms = getQMS();
    float qes = getQES();
    return qms * qes / (qms + qes);
}

/* Calculate and returns QES value on the fly, using current Driver parameters
  @returns(the calculate QES value)}
*/
float TDriver::getQES()
{
  return getQMS() / (getRO() - 1);
}

/* Calculate and returns QMS value on the fly, using current Driver parameters
  @returns(the calculate QMS value)}
*/
float TDriver::getQMS()
{
  return fs * sqrt(getRO()) / (freqAboveFreeAir - freqBellowFreeAir);
}

/*Calculate and returns RO value on the fly, using current Driver parameters
  @returns(the calculate RO value)}
*/
float TDriver::getRO()
{
  return zmax / re;
}

/* Calculate and returns RF value on the fly, using current Driver parameters
  @returns(the calculate RF value)}
*/
float TDriver::getRF()
{
  return sqrt(getRO())* re;
}
