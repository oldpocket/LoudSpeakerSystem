#include <iostream>
#include "TClosedBox.hpp"
#include "TVentedBox.hpp"
#include "TDriver.hpp"
#include "OPMacros.hpp"

void closedBox() {
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

void ventedBox() {
    TDriver driver = TDriver();
    driver.re = 5.7;
    driver.fs = 45;
    driver.zmax = 38;
    driver.freqBellowFreeAir = 23;
    driver.freqAboveFreeAir = 46;
    driver.tvb = 0.5;
    driver.tfs = 73;
    TVentedBox* ventedBox = new TVentedBox(driver);
    ventedBox->setVB(11.2);
    std::cout << " Vas " << driver.getVAS() << std::endl;
    std::cout << " Vb " << ventedBox->getVB() << std::endl;
    std::cout << " FB " << ventedBox->getFB() << std::endl;
    std::cout << " F3 " << ventedBox->getF3() << std::endl;
    std::cout << " H " << ventedBox->getH() << std::endl;
    return;
    
    TBoxResponse<float, MIN_FREQUENCY, MAX_FREQUENCY> response = ventedBox->getBoxResponse();
    for (int i = MIN_FREQUENCY; i <= MAX_FREQUENCY; i++) {
        std::cout << i << "\t" << response[i] << std::endl;
    }
}

int main() {

    ventedBox();
    
}
