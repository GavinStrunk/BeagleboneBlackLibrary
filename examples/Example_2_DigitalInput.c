#include <stdio.h>

int main()
{
	FILE *in,*indir,*inval;
	int value,i;

	in = fopen("/sys/class/gpio/export", "w");
	fseek(in,0,SEEK_SET);
	fprintf(in,"%d",47);
	fflush(in);

	indir = fopen("/sys/class/gpio/gpio47/direction", "w");
	fseek(indir,0,SEEK_SET);
	fprintf(indir,"in");
	fflush(indir);

	while(1)
	{
		inval = fopen("/sys/class/gpio/gpio47/value", "r");
		fseek(inval,0,SEEK_SET);
		fscanf(inval,"%d",&value);
		fclose(inval);

		printf("value: %d\n",value);
		for(i=0; i < 100000; i++);
	}

	fclose(in);
	fclose(indir);
	return 0;
}
