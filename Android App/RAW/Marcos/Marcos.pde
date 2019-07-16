import ketai.sensors.*;
import ketai.camera.*;
KetaiSensor sensor;
KetaiCamera cam;
PVector magneticField, accelerometer, gyroscope, linearAcceleration, rotationVector;
float light, proximity;

void setup(){
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
  cam = new KetaiCamera(this, 1280, 768, 30);
  println(cam.list()); // 1
  // 0: back camera; 1: front camera
  cam.setCameraID(0); // 2
  imageMode(CENTER);
  stroke(255);

}

void draw()
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
       
       
        image(cam, width/2, height/2, width, height);
        drawUI(); // 4
       
}

void onAccelerometerEvent(float x, float y, float z, long time, int accuracy)
{
  accelerometer.set(x, y, z);
}

void onMagneticFieldEvent(float x, float y, float z, long time, int accuracy)
{
  magneticField.set(x, y, z);
}

void onGyroscopeEvent(float x, float y, float z, long time, int accuracy)
{
  gyroscope.set(x, y, z);
}

void onLinearAccelerationEvent(float x, float y, float z, long time, int accuracy)
{
  linearAcceleration.set(x, y, z);
}

void onRotationVectorEvent(float x, float y, float z, long time, int accuracy)
{
  rotationVector.set(x, y, z);
}

void onLightEvent(float v)
{
  light = v;
}

void onProximityEvent(float v)
{
  proximity = v;
}
  
public void mousePressed(){
  if (sensor.isStarted())
    sensor.stop();
  else
    sensor.start();
  println("Marcos isStarted: " + sensor.isStarted());
  
   if (mouseY <= 100) { // 4
    if (mouseX > 0 && mouseX < width/4) { // 5
      if (cam.isStarted())
        cam.stop();
      else {
        if (!cam.start())
          println("Failed to start camera.");
      }
    }
    else if (mouseX > width/4 && mouseX < 2*(width/4)) { // 6
      int cameraID = 0;
      if (cam.getCameraID() == 0)
        cameraID = 1;
      else
        cameraID = 0;
      cam.stop();
      cam.setCameraID(cameraID);
      cam.start();
    }
    else if (mouseX >2*(width/4) && mouseX < 3*(width/4)) { // 7
      if (cam.isFlashEnabled()) // 8
        cam.disableFlash();
      else
        cam.enableFlash();
    }
  }
}

void drawUI() { // 1
  fill(0, 128);
  rect(0, 0, width/4, 100);
  rect(width/4, 0, width/4, 100);
  rect(2*(width/4), 0, width/4, 100);
  rect(3*(width/4), 0, width/4, 100);
  fill(255);
  if (cam.isStarted())  // 2
    text("stop", 20, 70);
  else
    text("start", 20, 70);
  text("camera", (width/4)+20, 70);
  text("flash", 2*(width/4)+20, 70);
}

       
       void onCameraPreviewEvent() {
  cam.read();
}
void exit() {
  cam.stop();
}
