#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr, "Usage:%s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	int n = 0;
	int c;
	while((c = fgetc(fp)) != EOF){
		if(c == '\n'){
			n++;
		}
	}
	
	if(c != '\n'){
		n++;
	}

	printf("%d %s\n", n, argv[1]);
	fclose(fp);

	return 0;
}
