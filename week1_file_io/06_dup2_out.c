#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fp;
	int fp2;

	if ((fp = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC)) == -1){
		perror("open error");
		exit(1);
	}

	if ((fp2 = dup2(fp, STDOUT_FILENO)) == -1){
		perror("dup2 error");
		exit(1);
	}

	printf("How are you?\n");
	printf("I am fine.\n");

	return 0;
}
