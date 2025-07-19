#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr, "Usage:%s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	struct stat buff;
	if((stat(argv[1], &buff)) == -1){
		fprintf(stderr, "fstat error");
		exit(EXIT_FAILURE);
	}

	char mode[11] = {0};
	if(S_ISREG(buff.st_mode)){
		mode[0] = '-';
	}
	else if(S_ISDIR(buff.st_mode)){
		mode[0] = 'd';
	}
	else if(S_ISLNK(buff.st_mode)){
		mode[0] = 'l';
	} 
	else{
		mode[0] = '?';
	}

	mode[1] = (buff.st_mode & S_IRUSR)?'r':'-';
	mode[2] = (buff.st_mode & S_IWUSR)?'w':'-';
	mode[3] = (buff.st_mode & S_IXUSR)?'x':'-';
	mode[4] = (buff.st_mode & S_IRGRP)?'r':'-';
	mode[5] = (buff.st_mode & S_IWGRP)?'w':'-';
	mode[6] = (buff.st_mode & S_IXGRP)?'x':'-';
	mode[7] = (buff.st_mode & S_IROTH)?'r':'-';
	mode[8] = (buff.st_mode & S_IWOTH)?'w':'-';
	mode[9] = (buff.st_mode & S_IXOTH)?'x':'-';

	off_t size = buff.st_size;

	char timebuf[20];
	struct tm *t = localtime(&(buff.st_mtime));
	strftime(timebuf, sizeof(timebuf), "%Y-%m-%d", t);
	
	printf("%s %ld %s %s\n", mode, size, timebuf, argv[1]);
	
	return 0;
}
