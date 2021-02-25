#include <SensorKit.h>

SensorKit s(2, 10); // Connect your sensor to pin 2 ananlog and 10 digital


void setup() {
	s.begin();
	
	while (!Serial) { }; // for Leos
	Serial.begin(9600);
}

void loop() {
	
	Serial.print( s.status() ? "ON  " : "OFF " );
  Serial.println( s.read() );
  delay (300);
}
