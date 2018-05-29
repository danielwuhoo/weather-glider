#include <Servo.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <PID.h>


Adafruit_BMP280 bmp;
Madgwick filter;
Servo leftServo, rightServo;
unsigned long time;

void setup() {
	delay(1000);
	leftServo.attach(12);
  	rightServo.attach(11);
  	if (!bmp.begin()) {  
    	Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    	while (1);
  	}
  CurieIMU.begin();
  CurieIMU.setGyroRate(200);
  CurieIMU.setAccelerometerRate(200);
  filter.begin(200);
  // Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);
  // Set the gyroscope range to 250 degrees/second
  CurieIMU.setGyroRange(250);
}

void loop() {

}

void manageSoftwareTimers(){
	time = millis();
}