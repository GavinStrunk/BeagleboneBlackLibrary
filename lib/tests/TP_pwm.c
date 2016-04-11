#include "libBBB.h"

int main()
{
	initPWM(9,P8_13);
	printf("initialized\n");
	setPWMPeriod(15,P8_13,200000000);
	printf("period set\n");
	setPWMDuty(15,P8_13,100000000);
	printf("duty set\n");
	setPWMOnOff(15,P8_13,0);
	printf("run turned off\n");

	pauseSec(5);
	setPWMOnOff(15,P8_13,1);
	printf("run turn on\n");

	while(1);

	return 0;
}
