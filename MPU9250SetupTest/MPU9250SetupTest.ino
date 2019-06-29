#include "MPU9250.h"

MPU9250 mpu;

void setup()
{
    Serial.begin(9600);

    Wire.begin();

    delay(2000);
    mpu.setup();
}

void loop()
{
    static uint32_t prev_ms = millis();
    if ((millis() - prev_ms) > 16)
    {
      mpu.update();
    }
    if ((millis() - prev_ms) > 5000)
    {
        
        //mpu.print();

        Serial.print("roll  (x-forward (north)) : ");
        Serial.println(mpu.getRoll());
        Serial.print("pitch (y-right (east))    : ");
        Serial.println(mpu.getPitch());
        Serial.print("yaw   (z-down (down))     : ");
        Serial.println(mpu.getYaw());
        Serial.println();
        Serial.println();
        Serial.println();

        prev_ms = millis();
    }
}
