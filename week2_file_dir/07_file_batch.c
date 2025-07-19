#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	struct stat buf;
	char *ptr;

	for(int i=1; i<argc; i++){
		if((stat(argv[i], &buf)) == -1){
			perror("stat error");
			exit(1);
		}
		if(S_ISREG(buf.st_mode)){
			ptr = "regular";
		}
		else if(S_ISDIR(buf.st_mode)){
			ptr = "directory";
		}
		else if(S_ISLNK(buf.st_mode)){
			ptr = "link";
		}
		else{
			ptr = "** unknown **";
		}
		printf("%s %s\n", argv[i], ptr);
	}

	return 0;
}
