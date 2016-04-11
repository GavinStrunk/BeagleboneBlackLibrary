#include "libBBB.h"

int main()
{
	int value,i;
	initPin(47);
	setPinDirection(47,IN);

	while(1)
	{
		value = getPinValue(47);
		printf("value: %d\n",value);
		for(i=0; i < 100000; i++);
	}

	return 0;
}
