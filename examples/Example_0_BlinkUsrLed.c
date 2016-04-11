#include <stdio.h>
#include <time.h>

void pauseSec(int sec);

int main()
{
	FILE *led;

	led = fopen("/sys/class/leds/beaglebone:green:usr3/brightness", "w");

	while(1)
	{
		fprintf(led,"%d",1);
		fflush(led);
		pauseSec(1);
		fprintf(led,"%d",0);
		fflush(led);
		pauseSec(1);
	}

	fclose(led);
	return 0;
}

void pauseSec(int sec)
{
	time_t now,later;

	now = time(NULL);
	later = time(NULL);

	while((later - now) < (double)sec)
		later = time(NULL);
}
