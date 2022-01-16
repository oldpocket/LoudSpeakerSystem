#include "catch.hpp"
#include "TDriver.hpp"

TDriver setupDriver() {
    TDriver driver = TDriver();
    driver.re = 5.7;
    driver.fs = 33;
    driver.zmax = 38;
    driver.freqBellowFreeAir = 23;
    driver.freqAboveFreeAir = 46;
    driver.tvb = 14;
    driver.tfs = 73;
    
    return driver;
}

float testQMS() {
    TDriver driver = setupDriver();

    return std::fabs(3.70 - driver.getQMS());
}

TEST_CASE( "Driver parameters calculated", "[driver]" ) {
    REQUIRE( testQMS() < 0.01f);
}