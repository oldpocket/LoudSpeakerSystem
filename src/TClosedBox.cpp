#include <iostream>
#include "TClosedBox.hpp"
#include "OPExceptions.hpp"
#include "OPMacros.hpp"


TClosedBox::TClosedBox(TDriver driver_) : TBox(driver_) {

}

TClosedBox::~TClosedBox() {

}

/*
  Calculate Box Response in dB vs frequency (Hz)
  @returns(array with response in dB for each frequency in Hz. Array index equals frequency)
*/
TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> TClosedBox::getBoxResponse() {

  float fc = getFC();
  if (fc == 0) throw "FC cannot be zero";

  float qtc = getQTC();
  if (qtc == 0) throw "QTC cannot be zero";

  float fh, fq, mag;
  TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response;

  for (int f = 20; f <= MAX_FREQUENCY; f++) {
    fh = f / fc;
    fq = SQR(fh);
    mag = fq / (sqrt(SQR(fq - 1) + SQR(fh / qtc)));
    response[f] = 20 * (log(mag) / log(10));
  }

  return response;
}

float TClosedBox::getF3() {
         
  return getFC() * sqrt(((1 / SQR(getQTC()) - 2) + sqrt(SQR(1 / SQR(getQTC()) - 2) + 4)) / 2);
}

float TClosedBox::getQTC() {

  if (driver.fs == 0) throw DivideByZeroException();

  return (getFC() * driver.getQTS()) / driver.fs;
}

float TClosedBox::getFC() {
  return driver.fs * sqrt(getA() + 1);
}

float TClosedBox::getA() {

  if (vb == 0) throw DivideByZeroException();

  return driver.getVAS() / vb;
}