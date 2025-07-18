#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	struct stat buff;
	if((lstat(argv[1], &buff)) == -1){
		perror("lstat error");
		exit(1);
	}

	printf("%s mode is %d\n", argv[1], buff.st_mode);
	return 0;
}
