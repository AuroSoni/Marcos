#include "MPU9250.h"

MPU9250 mpu;
void SendRPY()
{
    Serial.println(mpu.getRoll());        //4 bytes to TX buffer
    Serial.flush();
    Serial.println(mpu.getPitch());       //4 bytes to TX buffer
    Serial.flush();
    Serial.println(mpu.getYaw());         //4 bytes to TX buffer
    Serial.flush();
}

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
      prev_ms = millis();
    }
    
    while(Serial.available())
    {
      char command = (char)Serial.read();   //1 byte read
      if(command=='n')
      {
        SendRPY();
      }
    }
}
