#include <stdio.h>

int main()
{
	FILE *pwm,*duty,*period,*run;

	pwm = fopen("/sys/devices/bone_capemgr.9/slots", "w");
	fseek(pwm,0,SEEK_SET);
	fprintf(pwm,"am33xx_pwm");
	fflush(pwm);
	
	fprintf(pwm,"bone_pwm_P8_13");
	fflush(pwm);

	period = fopen("/sys/devices/ocp.2/pwm_test_P8_13.14/period", "w");
	fseek(period,0,SEEK_SET);
	fprintf(period,"%d",200000000);
	fflush(period);

	duty = fopen("/sys/devices/ocp.2/pwm_test_P8_13.14/duty", "w");
	fseek(duty,0,SEEK_SET);
	fprintf(duty,"%d",100000000);
	fflush(duty);

	run = fopen("/sys/devices/ocp.2/pwm_test_P8_13.14/run", "w");
	fseek(run,0,SEEK_SET);
	fprintf(run,"%d",0);
	fflush(run);

	fseek(run,0,SEEK_SET);
	fprintf(run,"%d",1);
	fflush(run);
	while(1);

	fclose(pwm);
	fclose(duty);
	fclose(period);
	fclose(run);
	return 0;
}
