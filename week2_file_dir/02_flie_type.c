#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	struct stat buff;
	char *ptr;
	if((stat(argv[1], &buff)) == -1){
		perror("stat error");
		exit(1);
	}

	if(S_ISREG(buff.st_mode)){
		ptr = "regular";
	}
	else if(S_ISDIR(buff.st_mode)){
		ptr = "dir";
	}
	else if(S_ISLNK(buff.st_mode)){
		ptr = "link";
	}
	else if(S_ISCHR(buff.st_mode)){
		ptr = "chr";
	}
	else if(S_ISBLK(buff.st_mode)){
		ptr = "blk";
	}
	else{
		ptr = "** unknown mode **";
	}

	printf("%s is %s\n", argv[1], ptr);

	return 0;
}
