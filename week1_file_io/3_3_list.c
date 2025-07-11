#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 4096


int main(void){
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		if (write(STDOUT_FILENO, buf, BUFFSIZE) != n){
			perror("werite error");
			exit(1);
		}
	}

	if (n < 0){
		perror("read error");
		exit(1);
	}

	return 0;
}
