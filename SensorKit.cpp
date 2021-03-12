/*
	SensorKit - a small library for Arduino to handle SensorKit debouncing
	
	MIT licensed.
*/

#include "SensorKit.h"

SensorKit::SensorKit(byte a_pin, byte d_pin)
:  _pin_A(a_pin)
,  _pin_D(d_pin)
{
}

void SensorKit::begin()
{
	pinMode(_pin_A, INPUT);
	pinMode(_pin_D, INPUT);
#ifndef DISABLE_DEBUG
	Serial.print( "Sensor: ");
	Serial.print( _pin_A );
	Serial.print( ", " );
	Serial.println( _pin_D );
#endif

}

// 
// public methods
// 

#ifndef INLINE_SENSORKIT

int SensorKit::read()
{
	return (_pin_A>=0)?analogRead(_pin_A):NODATA;
}


bool SensorKit::status()
{
	return (_pin_D>=0)?digitalRead(_pin_D):LOW;
}

#endif



