#include <Servo.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "PID.h"
#include "Motion.h"

Adafruit_BMP280 bmp;
Madgwick filter;
Servo leftServo, rightServo;
unsigned long time;

void setup() {
	delay(1000);
	leftServo.attach(12);
  	rightServo.attach(11);
  	if (!bmp.begin()) {  
    	while (1);
  	}
  
}

void loop() {

}

void manageSoftwareTimers(){
	time = millis();
}