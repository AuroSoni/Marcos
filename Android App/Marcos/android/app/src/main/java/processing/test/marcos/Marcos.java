package processing.test.marcos;

import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import ketai.sensors.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Marcos extends PApplet {


KetaiSensor sensor;
PVector magneticField, accelerometer, gyroscope, linearAcceleration, rotationVector;
float light, proximity;

public void setup(){
  sensor = new KetaiSensor(this);
  sensor.start();
  sensor.list();
  accelerometer = new PVector();
  magneticField = new PVector();
  gyroscope = new PVector();
  linearAcceleration = new PVector();
  rotationVector = new PVector();
 // orientation(auto);
  textAlign(LEFT, CENTER);
  textSize(24);

}

public void draw()
{
  background(0, 0, 0);
  text("MARCOS" + "\n" + "\n" + "\n"
  
  
       + "Accelerometer :" + "\n"
       
       + "x: " + nfp(accelerometer.x, 1, 2) + " m/s2" + "\n"
       + "y: " + nfp(accelerometer.y, 1, 2) + " m/s2" + "\n"
       + "z: " + nfp(accelerometer.z, 1, 2) + " m/s2" + "\n" + "\n"
       
       
       + "MagneticField: " + "\n"
       
       + "x: " + nfp(magneticField.x, 1, 2) + " uT" + "\n"
       + "y: " + nfp(magneticField.y, 1, 2) + " uT" + "\n"
       + "z: " + nfp(magneticField.z, 1, 2) + " uT" + "\n" + "\n"
       
       
       + "Gyroscope :" + "\n"
       
       + "x: " + nfp(gyroscope.x, 1, 2) + " rads/sec" + "\n"
       + "y: " + nfp(gyroscope.y, 1, 2) + " rads/sec" + "\n"
       + "z: " + nfp(gyroscope.z, 1, 2) + " rads/sec" + "\n"+ "\n"
       
       
       + "Linear Acceleration :" + "\n"
       + "x: " + nfp(linearAcceleration.x, 1, 2) + " m/s2" + "\n"
       + "y: " + nfp(linearAcceleration.y, 1, 2) + " m/s2" + "\n"
       + "z: " + nfp(linearAcceleration.z, 1, 2) + " m/s2" + "\n" + "\n"
       
       
       + "Rotation Vector :" + "\n"
       
       + "x: " + nfp(rotationVector.x, 1, 2) + "\n"
       + "y: " + nfp(rotationVector.y, 1, 2) + "\n"
       + "z: " + nfp(rotationVector.z, 1, 2) + "\n" + "\n"
       
       + "Light Sensor :" + light + " lx" + "\n" + "\n"
       
       + "Proximity Sensor : " + proximity + "\n" + "\n"
       , 20, 0, width, height);
       
}

public void onAccelerometerEvent(float x, float y, float z, long time, int accuracy)
{
  accelerometer.set(x, y, z);
}

public void onMagneticFieldEvent(float x, float y, float z, long time, int accuracy)
{
  magneticField.set(x, y, z);
}

public void onGyroscopeEvent(float x, float y, float z, long time, int accuracy)
{
  gyroscope.set(x, y, z);
}

public void onLinearAccelerationEvent(float x, float y, float z, long time, int accuracy)
{
  linearAcceleration.set(x, y, z);
}

public void onRotationVectorEvent(float x, float y, float z, long time, int accuracy)
{
  rotationVector.set(x, y, z);
}

public void onLightEvent(float v)
{
  light = v;
}

public void onProximityEvent(float v)
{
  proximity = v;
}
  
public void mousePressed(){
  if (sensor.isStarted())
    sensor.stop();
  else
    sensor.start();
  println("Marcos isStarted: " + sensor.isStarted());
}
       
}
