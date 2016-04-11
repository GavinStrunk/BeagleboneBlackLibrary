#include <stdio.h>
#include <time.h>

void pauseSec(int sec);

int main()
{
	FILE *ain,*aval,*aval1;
	int value,value1,i;

	ain = fopen("/sys/devices/bone_capemgr.9/slots", "w");
	fseek(ain,0,SEEK_SET);
	fprintf(ain,"cape-bone-iio");
	fflush(ain);

	while(1)
	{
		aval = fopen("/sys/devices/ocp.2/helper.14/AIN0", "r");
		fseek(aval,0,SEEK_SET);
		fscanf(aval,"%d",&value);
		fclose(aval);

		for(i = 0; i<1000000;i++);
		
		aval1 = fopen("/sys/devices/ocp.2/helper.14/AIN1","r");
		fseek(aval1,0,SEEK_SET);
		fscanf(aval1,"%d",&value1);
		fclose(aval1);
		printf("value: %d  value1: %d\n",value,value1);
		for(i = 0; i<1000000;i++);
	}

	fclose(ain);
	return 0;
}

void pauseSec(int sec)
{
	time_t now,later;

	now = time(NULL);
	later = time(NULL);

	while((later - now) < (double) sec)
		later = time(NULL);
}
