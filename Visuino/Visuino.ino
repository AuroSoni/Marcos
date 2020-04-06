#define VISUINO_ARDUINO_MEGA
#define _MITOV_MPU_ACCELEROMETER_
#define _MITOV_MPU_GYROSCOPE_
#define _MITOV_MPU9250_GYROSCOPE_
#define _MITOV_MPU_THERMOMETER_

#include <OpenWire.h>
#include <Mitov.h>
#include <Mitov_FormattedSerial.h>
#include <Wire.h>
#include <Mitov_Basic_I2C.h>
#include <Mitov_MPU9250.h>
#include <Mitov_Packet.h>

// Arduino Board Declarations

namespace BoardDeclarations
{
Mitov::TypedSerialPort<Mitov::SerialPort<SERIAL_TYPE, Serial>, SERIAL_TYPE, Serial> SerialPort0;
Mitov::ArduinoSerialBinaryInput<Mitov::TypedSerialPort<Mitov::SerialPort<SERIAL_TYPE, Serial>, SERIAL_TYPE, Serial>, SerialPort0> SerialPort0_Byte_1;
} // BoardDeclarations

// Declarations

namespace Declarations
{
Mitov::MPU9250I2C<104, TwoWire, Wire> AccelerometerGyroscopeCompass1;
Mitov::Packet Packet1;
} // Declarations

// Pin Call Declarations

namespace PinCalls
{
void PinCallerReceive1( void *_Data );
void PinCallerReceive2( void *_Data );
void PinCallerReceive3( void *_Data );
void PinCallerReceive4( void *_Data );
void PinCallerReceive5( void *_Data );
void PinCallerReceive6( void *_Data );
void PinCallerReceive7( void *_Data );
void PinCallerReceive8( void *_Data );
void PinCallerReceive9( void *_Data );
void PinCallerReceive10( void *_Data );
void PinCallerReceive11( void *_Data );
} // PinCalls

// Pin Call Implementations

namespace PinCalls
{
void PinCallerReceive1( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 3 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive2( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 4 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive3( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 5 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive4( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 7 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive5( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 6 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive6( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 8 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive7( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 0 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive8( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 1 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive9( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 2 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive10( void *_Data )
{
  ((Mitov::BasicTypedPacketSinkElement<float,float> *) Declarations::Packet1.Elements[ 9 ] )->InputPin_o_Receive( _Data );
}

void PinCallerReceive11( void *_Data )
{
  BoardDeclarations::SerialPort0_Byte_1.InputPin_o_Receive( _Data );
}

} // PinCalls

namespace ComponentsHardware
{
void SystemUpdateHardware()
{
}
} // ComponentsHardware

//The setup function is called once at startup of the sketch
void setup()
{
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  Declarations::Packet1.Elements.push_back( new Mitov::BasicTypedPacketSinkElement<float,float>( false ) );
  {
    static uint8_t _Bytes[] = { 85,85 };
    Declarations::Packet1.HeadMarker.Bytes._Bytes = _Bytes;
  }
  Declarations::Packet1.HeadMarker.Bytes._BytesSize = 2;

  Wire.begin();

  Declarations::AccelerometerGyroscopeCompass1.Accelerometer.OutputPins[ 0 ]().SetCallback( PinCalls::PinCallerReceive1 );
  Declarations::AccelerometerGyroscopeCompass1.Accelerometer.OutputPins[ 1 ]().SetCallback( PinCalls::PinCallerReceive2 );
  Declarations::AccelerometerGyroscopeCompass1.Accelerometer.OutputPins[ 2 ]().SetCallback( PinCalls::PinCallerReceive3 );
  Declarations::AccelerometerGyroscopeCompass1.Gyroscope.OutputPins[ 0 ]().SetCallback( PinCalls::PinCallerReceive4 );
  Declarations::AccelerometerGyroscopeCompass1.Gyroscope.OutputPins[ 1 ]().SetCallback( PinCalls::PinCallerReceive5 );
  Declarations::AccelerometerGyroscopeCompass1.Gyroscope.OutputPins[ 2 ]().SetCallback( PinCalls::PinCallerReceive6 );
  Declarations::AccelerometerGyroscopeCompass1.Compass.OutputPins[ 0 ]().SetCallback( PinCalls::PinCallerReceive7 );
  Declarations::AccelerometerGyroscopeCompass1.Compass.OutputPins[ 1 ]().SetCallback( PinCalls::PinCallerReceive8 );
  Declarations::AccelerometerGyroscopeCompass1.Compass.OutputPins[ 2 ]().SetCallback( PinCalls::PinCallerReceive9 );
  Declarations::AccelerometerGyroscopeCompass1.Thermometer.OutputPin().SetCallback( PinCalls::PinCallerReceive10 );
  Declarations::Packet1.OutputPin().SetCallback( PinCalls::PinCallerReceive11 );

  BoardDeclarations::SerialPort0.SystemInit();

  Declarations::AccelerometerGyroscopeCompass1.SystemStart();
  Declarations::Packet1.SystemStart();

  OpenWire::SystemStarted();
}

// The loop function is called in an endless loop
void loop()
{
  unsigned long A_Current_Microseconds = micros();

  BoardDeclarations::SerialPort0.SystemLoopBegin( A_Current_Microseconds );
  Declarations::AccelerometerGyroscopeCompass1.SystemLoopBegin( A_Current_Microseconds );
  Declarations::Packet1.SystemLoopBegin( A_Current_Microseconds );
}
