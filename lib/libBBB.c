#include "libBBB.h"

int setUsrLedValue(char* led, int value)
{
	FILE *usr;
	char buf[20];
	char buf2[50] = "/sys/class/leds/beaglebone:green:";

	//build file path to usr led brightness
	sprintf(buf,"%s",led);
	strcat(buf2,strcat(buf,"/brightness"));

	usr = fopen(buf2, "w");
	if(usr == NULL) printf("USR Led failed to open\n");
	fseek(usr,0,SEEK_SET);
	fprintf(usr,"%d",value);
	fflush(usr);
	fclose(usr);

	return 0;
}

int initPin(int pinnum)
{
	FILE *io;

	io = fopen("/sys/class/gpio/export", "w");
	if(io == NULL) printf("Pin failed to initialize\n");
	fseek(io,0,SEEK_SET);
	fprintf(io,"%d",pinnum);
	fflush(io);
	fclose(io);

	return 0;
}

int setPinDirection(int pinnum, char* dir)
{
	FILE *pdir;
	char buf[10];
	char buf2[50] = "/sys/class/gpio/gpio";

	//build file path to the direction file
	sprintf(buf,"%i",pinnum);
	strcat(buf2,strcat(buf,"/direction"));

	pdir = fopen(buf2, "w");
	if(pdir == NULL) printf("Direction failed to open\n");
	fseek(pdir,0,SEEK_SET);
	fprintf(pdir,"%s",dir);
	fflush(pdir);
	fclose(pdir);

	return 0;
}

int setPinValue(int pinnum, int value)
{
	FILE *val;
	char buf[5];
	char buf2[50] = "/sys/class/gpio/gpio";

	//build path to value file
	sprintf(buf,"%i",pinnum);
	strcat(buf2,strcat(buf,"/value"));

	val = fopen(buf2, "w");
	if(val == NULL) printf("Value failed to open\n");
	fseek(val,0,SEEK_SET);
	fprintf(val,"%d",value);
	fflush(val);
	fclose(val);

	return 0;
}

int getPinValue(int pinnum)
{
	FILE *val;
	int value;
	char buf[5];
	char buf2[50] = "/sys/class/gpio/gpio";

	//build file path to value file
	sprintf(buf,"%i",pinnum);
	strcat(buf2,strcat(buf,"/value"));

	val = fopen(buf2, "r");
	if(val == NULL) printf("Input value failed to open\n");
	fseek(val,0,SEEK_SET);
	fscanf(val,"%d",&value);
	fclose(val);

	return value;
}

int initPWM(int mgrnum, char* pin)
{
	FILE *pwm;
	char buf[5];
	char buf2[50] = "/sys/devices/bone_capemgr.";
	char buf3[20] = "bone_pwm_";

	//build file paths
	sprintf(buf,"%i",mgrnum);
	strcat(buf2,strcat(buf,"/slots"));

	strcat(buf3,pin);

	pwm = fopen(buf2, "w");
	if(pwm == NULL) printf("PWM failed to initialize\n");
	fseek(pwm,0,SEEK_SET);
	fprintf(pwm,"am33xx_pwm");
	fflush(pwm);
	fprintf(pwm,"%s",buf3);
	fflush(pwm);
	fclose(pwm);

	return 0;
}

int setPWMPeriod(int helpnum, char* pin, int period)
{
	FILE *pwm;
	char buf[5];
	char buf2[60] = "/sys/devices/ocp.2/pwm_test_";

	//build file path
	sprintf(buf,"%i",helpnum);
	printf("%s\n",pin);
	strcat(buf2,pin);
	strcat(buf2,".");
	strcat(buf2,strcat(buf,"/period"));
	
	printf("%s\n",buf2);
	pwm = fopen(buf2, "w");
	if(pwm == NULL) printf("PWM Period failed to open\n");
	fseek(pwm,0,SEEK_SET);
	fprintf(pwm,"%d",period);
	fflush(pwm);
	fclose(pwm);

	return 0;
}

int setPWMDuty(int helpnum, char* pin, int duty)
{
	FILE *pwm;
	char buf[5];
	char buf2[50] = "/sys/devices/ocp.2/pwm_test_";

	//build file path
	sprintf(buf,"%i",helpnum);
	strcat(buf2,pin);
	strcat(buf2,".");
	strcat(buf2,strcat(buf,"/duty"));

	pwm = fopen(buf2, "w");
	if(pwm == NULL) printf("PWM Duty failed to open\n");
	fseek(pwm,0,SEEK_SET);
	fprintf(pwm,"%d",duty);
	fflush(pwm);
	fclose(pwm);

	return 0;
}

int setPWMOnOff(int helpnum, char* pin, int run)
{
	FILE *pwm;
	char buf[5];
	char buf2[50] = "/sys/devices/ocp.2/pwm_test_";

	//build file path
	sprintf(buf,"%i",helpnum);
	strcat(buf2,pin);
	strcat(buf2,".");
	strcat(buf2,strcat(buf,"/run"));

	pwm = fopen(buf2, "w");
	if(pwm == NULL) printf("PWM Run failed to open\n");
	fseek(pwm,0,SEEK_SET);
	fprintf(pwm,"%d",run);
	fflush(pwm);
	fclose(pwm);

	return 0;
}

int initUART(int mgrnum, char* uartnum)
{
	//This function loads the overlay
	FILE *uart;
	char buf[5];
	char buf2[50] = "/sys/devices/bone_capemgr.";

	sprintf(buf,"%i",mgrnum);
	strcat(buf2,strcat(buf,"/slots"));

	uart = fopen(buf2, "w");
	if(uart == NULL) printf("UART overlay failed to load\n");
	fseek(uart,0,SEEK_SET);
	fprintf(uart,uartnum);
	fflush(uart);
	fclose(uart);

	return 0;
}

int configUART(UART u, int property, char* value)
{

	return 0;
}

int txUART(int uart, unsigned char data)
{

	return 0;
}

unsigned char rxUART(int uart)
{

	return 0;
}

int strUART(int uart, char* buf)
{

	return 0;
}

int initADC(int mgrnum)
{
	FILE *ain;
	char buf[5];
	char buf2[50] = "/sys/devices/bone_capemgr.";

	//build path to setup ain
	sprintf(buf,"%i",mgrnum);
	strcat(buf2,strcat(buf,"/slots"));

	ain = fopen(buf2, "w");
	if(ain == NULL) printf("Analog failed load\n");
	fseek(ain,0,SEEK_SET);
	fprintf(ain,"cape-bone-iio");
	fflush(ain);
	fclose(ain);

	return 0;
}

int readADC(int helpnum, char* ach)
{
	FILE *aval;
	int value;
	char buf[5];
	char buf2[50] = "/sys/devices/ocp.2/helper.";

	//build file path to read adc
	sprintf(buf,"%i",helpnum);
	strcat(buf2,strcat(buf,ach));
	
	aval = fopen(buf2, "r");
	if(aval == NULL) printf("Analog failed to open\n");
	fseek(aval,0,SEEK_SET);
	fscanf(aval,"%d",&value);
	fflush(aval);
	fclose(aval);

	return value;
}

void pauseSec(int sec)
{
	time_t now,later;

	now = time(NULL);
	later = time(NULL);

	while((later - now) < (double)sec)
		later = time(NULL);
}

int pauseNanoSec(long nano)
{
	struct timespec tmr1,tmr2;

	//assume you are not trying to pause more than 1s
	tmr1.tv_sec = 0;
	tmr1.tv_nsec = nano;

	if(nanosleep(&tmr1, &tmr2) < 0)
	{
		printf("Nano second pause failed\n");
		return -1;
	}
	return 0;
}
