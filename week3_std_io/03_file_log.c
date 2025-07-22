#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		fprintf(stderr, "Usage:%s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *fp;
	if((fp = fopen(argv[1], "a")) == NULL){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	time_t now = time(NULL);
	struct tm *local = localtime(&now);
	char time_local[64];
    strftime(time_local, sizeof(time_local), "%Y-%m-%d %H:%M:%S", local);
	
	fprintf(fp, "[%s] INFO:%s\n", time_local, argv[2]);
	fclose(fp);

	return 0;
}
