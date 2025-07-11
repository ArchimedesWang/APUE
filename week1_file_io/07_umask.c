#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int fd;
	umask(0);
	
	if ((fd = open("test_umask.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1){
		perror("open error");
		exit(1);
	}

	write(fd, "hello umask\n", 13);
	close(fd);

	return 0;
}
