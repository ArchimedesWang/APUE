#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd == -1){
		perror("open error");
		exit(1);
	}

	char buff[] = "Hello!\n"; 
	write(fd, buff, sizeof(buff));
	fsync(fd);
	close(fd);

	return 0;
}
