#include "PID.h"

PID::PID(){
	iRollMem = 0;
	dRollError = 0;
	iPitchMem = 0;
	dPitchError = 0;
}

void PID::calculate(char rollError, char pitchError){
	iRollMem += P_ROLL_GAIN * rollError;
	if (iRollMem > MAX_ROLL){
		iRollMem = MAX_ROLL;
	}
	else if (iRollMem < MIN_ROLL){
		iRollMem = MIN_ROLL;
	}
}