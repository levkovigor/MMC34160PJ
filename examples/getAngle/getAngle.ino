#include <Wire.h>
#include <MMC34160PJ.h>

#define I2C_ADDRESS 0x30

/* There are several ways to create your MMC34160PJ object:
 * MMC34160PJ magnetometer = MMC34160PJ()              -> uses Wire / I2C Address = 0x30
 * MMC34160PJ magnetometer = MMC34160PJ(I2C_ADDRESS) -> uses Wire / I2C_ADDRESS
 * MMC34160PJ magnetometer = MMC34160PJ(&wire2)        -> uses the TwoWire object wire2 / I2C_ADDRESS
 * MMC34160PJ magnetometer = MMC34160PJ(&wire2, I2C_ADDRESS) -> all together
 * Successfully tested with two I2C busses on an ESP32
 */

MMC34160PJ magnetometer(I2C_ADDRESS);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if(!magnetometer.init()){
    Serial.println("MMC34160PJ not connected!");
  }

}

void loop() {
  float angle = 0;
  if(magnetometer.readData()){
    angle = magnetometer.getAngle();
    Serial.print("Angle: "); Serial.println(angle);
  } else {
    Serial.println("Failed to retrieve angle");
  }
}
