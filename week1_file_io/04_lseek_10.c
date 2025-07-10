#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int fp = open("Hamlet.txt", O_RDONLY);
	if(fp == -1){
		perror("Open failed!");
		exit(1);
	}

	off_t fl = lseek(fp, 10, SEEK_CUR);
	if(fl == -1){
		perror("Lseek failed!");
		exit(1);
	}

	char buff[20];
	ssize_t fr = read(fp, buff, 10);
	if(fr == -1){
		perror("Read failed!");
		exit(1);
	}

	write(STDOUT_FILENO, buff, fr);

	return 0;
}
