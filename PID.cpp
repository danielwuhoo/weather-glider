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
	constrain(rollOut, MAX_PITCH, MIN_PITCH);
	dPitchError = pitchError;

}

void PID::writeServos(Servo &left, Servo &right){

	if (rollOut + pitchOut + 90 >= 180){
		leftAngle = 180;
		rightAngle = 180;
	} else{
		leftAngle = pitchOut - rollOut + 110;
		rightAngle = abs(abs(180 - rollOut - pitchOut) - 110);
	}

	left.write(leftAngle-20);
	right.write(rightAngle+30);

}

void constrain(char &value, char max, char min){
	if (value > max){
		value = max;
	}
	else if (value < min){
		value = min;
	}
}