#ifndef MOTION_H
#define MOTION_H

#include <CurieIMU.h>
#include <MadgwickAHRS.h>

class Motion{
private:
	Madgwick filter;
	float aX, aY, aZ, gX, gY, gZ;
public:
	Motion();
	void readSensors(char &roll, char &pitch, char &heading);
};



