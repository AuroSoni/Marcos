import ketai.sensors.*;
KetaiSensor sensor;
PVector magneticField, accelerometer, gyroscope;
float light, proximity;

void setup(){
  sensor = new KetaiSensor(this)
