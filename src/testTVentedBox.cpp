#include "catch.hpp"
#include "TVentedBox.hpp"
#include "TDriver.hpp"

TVentedBox* setupVentedBox() {
    TDriver driver = TDriver();
    driver.re = 5.7;
    driver.fs = 45;
    driver.zmax = 38;
    driver.freqBellowFreeAir = 23;
    driver.freqAboveFreeAir = 46;
    driver.tvb = 0.5;
    driver.tfs = 73;
    TVentedBox* ventedBox = new TVentedBox(driver);
    
    
    return ventedBox;
}

float testVB_ventedbox() {
    TVentedBox* ventedBox = setupVentedBox();
    
    return std::fabs(ventedBox->getVB() - 15.1f);
}

float testFb_ventedbox() {
    TVentedBox* ventedBox = setupVentedBox();
    
    return std::fabs(ventedBox->getFB() - 43.1f);
}

float testF3_ventedbox() {
    TVentedBox* ventedBox = setupVentedBox();
    
    return std::fabs(ventedBox->getF3() - 42.2f);
}

float testFb_custom_ventedbox() {
    TVentedBox* ventedBox = setupVentedBox();
    ventedBox->setVB(11.2);
    return std::fabs(ventedBox->getFB() - 48.3f);
}

float testF3_custom_ventedbox() {
    TVentedBox* ventedBox = setupVentedBox();
    ventedBox->setVB(11.2);
    return std::fabs(ventedBox->getF3() - 50.0f);
}

float testPeak_custom_ventedbox() {
    TVentedBox* ventedBox = setupVentedBox();
    ventedBox->setVB(11.2);
    return std::fabs(ventedBox->getH() - 1.02f);
}

TEST_CASE( "VentedBox VB calculated", "[ventedbox]" ) {
    REQUIRE( testVB_ventedbox() < 0.5 );
}

TEST_CASE( "VentedBox Fb calculated", "[ventedbox]" ) {
    REQUIRE( testFb_ventedbox() < 0.5 );
}

TEST_CASE( "VentedBox F3 calculated", "[ventedbox]" ) {
    REQUIRE( testF3_ventedbox() < 0.5 );
}

TEST_CASE( "VentedBox Fb custom calculated", "[ventedbox]" ) {
    REQUIRE( testFb_custom_ventedbox() < 0.5 );
}

TEST_CASE( "VentedBox F3 custom calculated", "[ventedbox]" ) {
    REQUIRE( testF3_custom_ventedbox() < 0.5 );
}

TEST_CASE( "VentedBox H custom calculated", "[ventedbox]" ) {
    REQUIRE( testPeak_custom_ventedbox() < 0.01 );
}
