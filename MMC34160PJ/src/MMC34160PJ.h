#ifndef MMC34160PJ_H_
#define MMC34160PJ_H_

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

/* registers */
#define MMC34160PJ_ADDRESS      0x30


class MMC34160PJ
{
    public: 
        MMC34160PJ(int addr);
        MMC34160PJ();
        MMC34160PJ(TwoWire *w, int addr);
        MMC34160PJ(TwoWire *w);
      
        bool init();
        void setDeclination(float _declination);
        float getDeclination();
        bool readData();
        float getAngle();
        uint8_t writeRegister(uint8_t reg, uint8_t val);
        
    private:
        TwoWire *_wire;
        int i2cAddress;
        uint16_t raw[3];
        float offset[3];
        float declination;
};

#endif

