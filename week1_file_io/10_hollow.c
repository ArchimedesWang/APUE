#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int fp = open("hollom.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if(fp == -1){
		perror("open error");
		exit(1);
	}

	char buff[] = " ";
	off_t fl = lseek(fp, 1024, SEEK_CUR);
	if(fl == -1){
		perror("lseek error");
		exit(1);
	}
	write(fp, buff, 1);
	close(fp);

	return 0;
}
