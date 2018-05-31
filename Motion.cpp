#include "Motion.h"

Motion::Motion(){
	filter.begin(200);
	CurieIMU.begin();
  	CurieIMU.setGyroRate(200);
  	CurieIMU.setAccelerometerRate(200);
  	CurieIMU.setGyroRange(250);
 	CurieIMU.setAccelerometerRange(2);

}


void Motion::readSensors(char &roll, char &pitch, char &heading){
	CurieIMU.readMotionSensorScaled(aX, aY, aZ, gX, gY, gZ);
	filter.updateIMU(gX, gY, gZ, aX, aY, aZ);
	roll = (char) filter.getRoll();
	pitch = (char) filter.getPitch();
	heading = (char) filter.getYaw();
}