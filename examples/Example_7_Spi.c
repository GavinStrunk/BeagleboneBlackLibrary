#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd;
	unsigned char buf = 0xA1;

	fd = open("/dev/spidev1.0", O_RDWR);
	if(fd < 0) printf("spi failed to open\n");

	while(1)
	{
		write(fd,&buf,1);
	}

	close(fd);

	return 0;
}
