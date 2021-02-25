/*
	SensorKit - a small library for Arduino to handle sensors
*/

#ifndef SensorKit_h
#define SensorKit_h
#include "Arduino.h"

// #define INLINE_SENSORKIT
// #define TINY_SENSORKIT

class SensorKit
{
	public:
		SensorKit(uint8_t a_pin, uint8_t d_pin);
		void begin();
		#ifdef INLINE_SENSORKIT
		inline int read() {
			#ifdef TINY_SENSORKIT
				return analogRead(_pin_A);
			#else
				return _pin_A?analogRead(_pin_A):-1;
			#endif
			};
		inline bool status() {
			#ifdef TINY_SENSORKIT
				return digitalRead(_pin_D);
			#else
				return _pin_D?digitalRead(_pin_D):LOW;
			#endif
			};
		#else
		int read();
		bool status();
		#endif
		
		// const static bool PRESSED = LOW;
		// const static bool RELEASED = HIGH;
	
	private:
		uint8_t  _pin_A;
		uint8_t  _pin_D;
};

#endif
