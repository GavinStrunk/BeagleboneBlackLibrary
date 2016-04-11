#include <stdio.h>
#include <time.h>

void pauseSec(int sec);

int main()
{
	FILE *io,*iodir,*ioval;

	io = fopen("/sys/class/gpio/export", "w");
	fseek(io,0,SEEK_SET);
	fprintf(io,"%d",45);
	fflush(io);

	iodir = fopen("/sys/class/gpio/gpio45/direction", "w");
	fseek(iodir,0,SEEK_SET);
	fprintf(iodir,"out");
	fflush(iodir);

	ioval = fopen("/sys/class/gpio/gpio45/value", "w");
	fseek(ioval,0,SEEK_SET);

	while(1)
	{
		fprintf(ioval,"%d",1);
		fflush(ioval);
		pauseSec(1);
		fprintf(ioval,"%d",0);
		fflush(ioval);
		pauseSec(1);
	}

	fclose(io);
	fclose(iodir);
	fclose(ioval);
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
