#include <iostream>
#include "TClosedBox.hpp"
#include "TDriver.hpp"
#include "OPMacros.hpp"

int main() {

    TDriver driver = TDriver();
    driver.re = 5.7;
    driver.fs = 33;
    driver.zmax = 38;
    driver.freqBellowFreeAir = 23;
    driver.freqAboveFreeAir = 46;
    driver.tvb = 0.5;
    driver.tfs = 73;
    TClosedBox* closedBox = new TClosedBox(driver);
    closedBox->vb = 1;
    
    TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response = closedBox->getBoxResponse();
    for (int i = MIN_FREQUENCY; i <= MAX_FREQUENCY; i++) {
        std::cout << i << "\t" << response[i] << std::endl;
    }
    
}
