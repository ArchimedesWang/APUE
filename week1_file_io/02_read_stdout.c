#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fp = open("hello.txt", O_RDONLY);
    if(fp == -1){
    	perror("Open failed!\n");
	return 0;
    }

    char buff[100];
    ssize_t fr = read(fp, buff, 20);
    if(fr == -1){
    	perror("Read failed\n");
	return 0;
    }

    write(STDOUT_FILENO, buff, fr);
    close(fp);

    return 0;
}
