#include "Motion.h"
#include <CurieIMU.h>
#include <MadgwickAHRS.h>

extern Madgwick filter;
float aX, aY, aZ, gX, gY, gZ;

void initializeMotionSensor(){
	CurieIMU.begin();
  	CurieIMU.setGyroRate(200);
  	CurieIMU.setAccelerometerRate(200);
  	CurieIMU.setGyroRange(250);
 	CurieIMU.setAccelerometerRange(2);
 	filter.begin(200);
 	
}

void readSensors(char &roll, char &pitch, char &heading){
	CurieIMU.readMotionSensorScaled(aX, aY, aZ, gX, gY, gZ);
	filter.updateIMU(gX, gY, gZ, aX, aY, aZ);
	roll = (char) filter.getRoll();
	pitch = (char) filter.getPitch();
	heading = (char) filter.getYaw();
}