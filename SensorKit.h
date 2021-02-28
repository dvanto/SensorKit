/*
	SensorKit - a small library for Arduino to handle sensors
*/

#ifndef SensorKit_h
#define SensorKit_h
#include "Arduino.h"

// включить инлайн реализацию 
// #define INLINE_SENSORKIT

// простой вариант  - без проверок
// #define TINY_SENSORKIT

class SensorKit
{
	public:
		SensorKit(byte a_pin, byte d_pin);
		void begin();
		#ifdef INLINE_SENSORKIT
		inline int read() {
			#ifdef TINY_SENSORKIT
				return analogRead(_pin_A);
			#else
				return (_pin_A>0)?analogRead(_pin_A):-1;
			#endif
			};
		inline bool status() {
			#ifdef TINY_SENSORKIT
				return digitalRead(_pin_D);
			#else
				return (_pin_D>0)?digitalRead(_pin_D):LOW;
			#endif
			};
		#else
		int read();
		bool status();
		#endif
		
		// const static bool PRESSED = LOW;
		// const static bool RELEASED = HIGH;
	
	private:
		byte  _pin_A; // отрицательные значение - порт не исползуется
		byte  _pin_D; // отрицательные значение - порт не исползуется
};

#endif
