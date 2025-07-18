#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		perror("argc error");
		exit(1);
	}

	chmod(argv[1], 0666);
	return 0;
}
