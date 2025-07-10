#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fp = open("Hamlet.txt", O_RDONLY);
    if(fp == -1){
    	perror("Open failed!");
	return 1;
    }

    char buff[128]; 
    ssize_t fr; 
    while((fr = read(fp, buff, 128))>0){
    	write(STDOUT_FILENO, buff, fr);
    }

    close(fp);

    return 0;
}
