#include <stdio.h>

int main()
{
	FILE *in,*indir,*inval,*outdir,*outval;
	int value;

	in = fopen("/sys/class/gpio/export", "w");
	fseek(in,0,SEEK_SET);
	fprintf(in,"%d",45);
	fflush(in);
	fseek(in,0,SEEK_SET);
	fprintf(in,"%d",47);
	fflush(in);

	indir = fopen("/sys/class/gpio/gpio47/direction", "w");
	fseek(indir,0,SEEK_SET);
	fprintf(indir,"in");
	fflush(indir);

	outdir = fopen("/sys/class/gpio/gpio45/direction", "w");
	fseek(outdir,0,SEEK_SET);
	fprintf(outdir,"out");
	fflush(outdir);

	inval = fopen("/sys/class/gpio/gpio47/value", "r");
	outval = fopen("/sys/class/gpio/gpio45/value", "w");

	while(1)
	{
		fseek(inval,0,SEEK_SET);
		fscanf(inval,"%d",&value);
		fflush(inval);
		fseek(outval,0,SEEK_SET);
		fprintf(outval,"%d",value);
		fflush(outval);
	}

	fclose(in);
	fclose(indir);
	fclose(inval);
	fclose(outdir);
	fclose(outval);

	return 0;
}
