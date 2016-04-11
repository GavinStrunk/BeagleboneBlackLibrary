#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int pauseNanoSec(long nano);
void pauseSec(int sec);

int main()
{
	//load the overlay for UART5
	FILE *uart;

	uart = fopen("/sys/devices/bone_capemgr.9/slots", "w");
	if(uart == NULL) printf("slots didn't open\n");
	fseek(uart,0,SEEK_SET);
	fprintf(uart,"uart5");
	fflush(uart);
	fclose(uart);

	//UART config using termios
	struct termios uart1,old;
	int fd;
	unsigned char buf = 0xAA;

	//open uart1 for tx/rx
	fd = open("/dev/ttyO4", O_RDWR | O_NOCTTY);
	if(fd < 0) printf("port failed to open\n");

	//save current attributes
	tcgetattr(fd,&old);
	bzero(&uart1,sizeof(uart1)); /*clear struct for new set*/

	uart1.c_cflag = B38400 | CS8 | CLOCAL | CREAD;
//	uart1.c_cflag = 0;
	uart1.c_iflag = IGNPAR | ICRNL;
	uart1.c_oflag = 0;
	uart1.c_lflag = 0;

	uart1.c_cc[VTIME] = 0;
	uart1.c_cc[VMIN]  = 1;

	//clean the line and set the attributes
	tcflush(fd,TCIFLUSH);
	tcsetattr(fd,TCSANOW,&uart1);

	while(1)
	{
		write(fd,&buf,1);
//		tcdrain(fd);
		pauseNanoSec(5000000);
	}

//	tcsetattr(fd,TCSANOW,&old);
	close(fd);

	return 0;
}

int pauseNanoSec(long nano)
{
	struct timespec tmr1,tmr2;

	tmr1.tv_sec = 0;
	tmr1.tv_nsec = nano;

	if(nanosleep(&tmr1,&tmr2) < 0)
	{
		printf("Nano second pause failed\n");
		return -1;
	}
}

void pauseSec(int sec)
{
	time_t now,later;

	now = time(NULL);
	later = time(NULL);

	while((later - now) < (double)sec)
		later = time(NULL);
}
