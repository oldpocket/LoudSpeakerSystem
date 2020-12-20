/* 
This class contains class types, declarations and definitions related with the
Loud Speaker Driver model being used in the current project.
*/

#pragma once

#include <string>

class TDriver {

    // [ToDo] find the meaning of this parameter
    float getRO();
    float getRF();
    
    float getQES(); 

public:
    // Friendly name of the Driver
    std::string driverName;
    // D.C. Resistance of Voice Coil
    float re;
    // Free-Air Resonance
    float fs;
    // Impedance at Free-Air Resonance
    float zmax;
    // Frequence Bellow Free Air Resonance
    float freqBellowFreeAir;
    // Frequence Above Free Air Resonance
    float freqAboveFreeAir;
    // Test Box Volume
    float tvb;
    // Driver Resonance in Test Box
    float tfs;
    // Driver's resonance magnification at Fs
    float getQTS(); 
    // Driver's compliance, stated in terms of the air volume that has an equivalent compliance for that driver
    float getVAS();
    float getQMS();

    TDriver();
    ~TDriver();
};
