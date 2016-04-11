#include "libBBB.h"

int main()
{

	//half a second pause
	long sec = 50000L;

	initPin(45);
	setPinDirection(45,OUT);

	while(1)
	{
		pauseNanoSec(sec);
		setPinValue(45,ON);
		pauseNanoSec(sec);
		setPinValue(45,OFF);
	}

	return 0;
}
