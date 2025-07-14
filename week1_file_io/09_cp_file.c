#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 512

int main(int argc, char *argv[]){
	int fp1 = open(argv[1], O_RDONLY);
	int fp2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fp1 == -1 || fp2 == -1){
		perror("open error");
		exit(1);
	}

	char buff[BUFFSIZE];
	ssize_t fr;
	while((fr = read(fp1, buff, BUFFSIZE)) != 0){
		if(fr == -1){
			perror("read error");
			close(fp1);
			close(fp2);
			exit(1);
		}
		ssize_t fw = write(fp2, buff, fr);
		if(fw == -1){
			perror("write error");
			close(fp1);
			close(fp2);
			exit(1);
		}
	}

	close(fp1);
	close(fp2);
	return 0;
}
