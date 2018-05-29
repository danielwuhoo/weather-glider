#ifndef PID_H
#define PID_H

#define P_ROLL_GAIN 2
#define I_ROLL_GAIN 0
#define D_ROLL_GAIN 1
#define MAX_ROLL 90
#define MIN_ROLL -90
#define P_PITCH_GAIN 1
#define I_PITCH_GAIN 0
#define D_PITCH_GAIN 1
#define MAX_PITCH 90
#define MIN_PITCH -90


class PID{
private:
	char iRollMem, dRollError;
	char iPitchMem, dPitchError;
	char rollOut, pitchOut;

public:
	PID();
	void calculate(char rollError, char pitchError);
};

void constrain(char &value, char max, char min);