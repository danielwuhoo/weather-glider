#include "PID.h"

PID::PID(){
	iRollMem = 0;
	dRollError = 0;
	iPitchMem = 0;
	dPitchError = 0;
}

void PID::calculate(char rollError, char pitchError){
	iRollMem += P_ROLL_GAIN * rollError;
	constrain(iRollMem, MAX_ROLL, MIN_ROLL);
	rollOut = (P_ROLL_GAIN * rollError) + iRollMem + (D_ROLL_GAIN * (rollError - dRollError));
	constrain(rollOut, MAX_ROLL, MIN_ROLL);
	dRollError = rollError;

	iPitchMem += P_PITCH_GAIN * pitchError;
	constrain(iPitchMem, MAX_PITCH, MIN_PITCH);
	pitchOut = (P_PITCH_GAIN * pitchError) + iPitchMem + (D_PITCH_GAIN * (pitchError - dPitchError));
	constrain(rollOut, MAX_ROLL, MIN_ROLL);
	dPitchError = pitchError;

}

void constrain(char &value, char max, char min){
	if (value > max){
		value = max;
	}
	else if (value < min){
		value = min;
	}
}