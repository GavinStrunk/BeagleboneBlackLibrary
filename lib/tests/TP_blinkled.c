#include "libBBB.h"

int main()
{
	initPin(45);
	setPinDirection(45,OUT);

	while(1)
	{
		setPinValue(45,1);
		pauseSec(1);
		setPinValue(45,0);
		pauseSec(1);
	}
	return 0;
}
