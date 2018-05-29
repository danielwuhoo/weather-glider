#include <Servo.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "PID.h"
#include "Motion.h"

#define SEA_LEVEL_PRESSURE 1013.25

Adafruit_BMP280 bmp;
Servo leftServo, rightServo;
PID controller;
unsigned long time;
float initialHeight;

void setup() {
	delay(1000);
	leftServo.attach(12);
  	rightServo.attach(11);
  	while (!bmp.begin());
  	initialHeight = bmp.readAltitude(SEA_LEVEL_PRESSURE);
  	initializeMotionSensor();
  
}

void loop() {

}

void manageSoftwareTimers(){
	time = millis();
}

void turnTry(float altitude){

}