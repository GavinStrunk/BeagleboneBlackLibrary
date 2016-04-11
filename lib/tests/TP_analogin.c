#include "libBBB.h"

int main()
{
	int value,value1,i;

	initADC(9);

	while(1)
	{
		value = readADC(14,AIN0);
		value1 = readADC(14,AIN1);
		printf("value: %d value1: %d\n", value,value1);
		for(i=0; i < 1000000; i++);
	}

	return 0;
}
