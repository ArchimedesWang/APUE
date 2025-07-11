#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fp = open("hello.txt", O_RDONLY);
	if(fp == -1){
		perror("Open failed!");
		exit(1);
	}
	
	off_t fl = lseek(fp, 0, SEEK_END);
	printf("File long is %d\n", (int)fl);
	close(fp);

	return 0;
}
