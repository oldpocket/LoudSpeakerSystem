#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "TClosedBox.hpp"
#include "TDriver.hpp"

TClosedBox* setupClosedBox() {
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
    
    return closedBox;
}

float testQTC() {
    TClosedBox* closedBox = setupClosedBox();
    
    return std::fabs(closedBox->getQTC() - 1.0f);
}

float testFC() {
    TClosedBox* closedBox = setupClosedBox();
    
    return std::fabs(closedBox->getFC() - 59.0f);
}

float testF3() {
    TClosedBox* closedBox = setupClosedBox();
    
    return std::fabs(closedBox->getF3() - 46.4f);
}

TEST_CASE( "ClosedBox QTC calculated", "[closedbox]" ) {
    REQUIRE( testQTC() < 0.05 );
}

TEST_CASE( "ClosedBox FC calculated", "[closedbox]" ) {
    REQUIRE( testFC() < 1.1 );
}

TEST_CASE( "ClosedBox F3 calculated", "[closedbox]" ) {
    REQUIRE( testF3() < 0.5 );
}