/*
	SensorKit - a small library for Arduino to handle SensorKit debouncing
	
	MIT licensed.
*/

#include "SensorKit.h"
#include <Arduino.h>

SensorKit::SensorKit(byte a_pin, byte d_pin)
:  _pin_A(a_pin)
,  _pin_D(d_pin)
{
}

// inline 
void SensorKit::begin()
{
	pinMode(_pin_A, INPUT);
	pinMode(_pin_D, INPUT);
	Serial.print( "Sensor: ");
	Serial.print( _pin_A );
	Serial.print( ", " );
	Serial.println( _pin_D );
}

// 
// public methods
// 

#ifndef TINY_SENSORKIT

int SensorKit::read()
{
	return (_pin_A>=0)?analogRead(_pin_A):-1;
}


bool SensorKit::status()
{
	return (_pin_D>=0)?digitalRead(_pin_D):LOW;
}

#endif
/* 

inline int SensorKit::read()
{
#ifdef TINY_SENSORKIT
	return analogRead(_pin_A);
#else
	return _pin_A?analogRead(_pin_A):-1;
#endif
}


inline bool SensorKit::status()
{
#ifdef TINY_SENSORKIT
	return digitalRead(_pin_D);
#else
	return _pin_D?digitalRead(_pin_D):LOW;
#endif
}
 */
