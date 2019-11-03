/*
AUTHOR: David Bradshaw
DATE: 25 April 2019
*/

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 3);

void setup()
{
	pinMode(5, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
	digitalWrite(5, HIGH);
	Serial.begin(57600);

	//A simple prompt incase you forget 
	Serial.println("When you apply power to the Arduino ensure that the button is held down on the HC-05 ");
	Serial.println("to put it into AT command mode or insert the HC-05 after power is applied.");
	Serial.println("If this is done correctly the LED will flash once every 2 seonds, if this happens the ");
	Serial.println("HC-05 is in AT command mode.");
	Serial.println("Ensure that BOTH NL AND CR are selected on you serial program. If the module is ready to be ");
	Serial.println("programmed the LED (pin 13) will be illuminated and if you type AT then press enter the module should");
	Serial.println("return the string OK.");

	Serial.println("for a list of AT commands and more information visit: https://www.l33t.uk/arduino_projects/bluetooth-programmer/");

	Serial.println("Enter AT commands:");
	BTSerial.begin(38400);  // HC-05 default speed in AT command more FOR HC-05= 38400, HC-08=9600, not sure about other BT modules
}

void loop()
{
	// Keep reading from HC-05 and send to Arduino Serial Monitor
	if (BTSerial.available())
		Serial.write(BTSerial.read());

	// Keep reading from Arduino Serial Monitor and send to HC-05
	if (Serial.available())
		BTSerial.write(Serial.read());
}
