#include "libBBB.h"

int main()
{
	while(1)
	{
		setUsrLedValue(USR3,1);
		pauseSec(1);
		setUsrLedValue(USR3,0);
		pauseSec(1);
	}

	return 0;
}
