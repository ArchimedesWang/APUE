#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fp = open("hello.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(fp == -1){
    	perror("Open failed!\n");
	close(fp);
	return 0;
    }

    char buff[] = "Hello Unix!\n";
    ssize_t fw = write(fp, buff, sizeof(buff));
    if(fw == -1){
    	perror("Write failed!\n");
	close(fp);
	return 0;
    }

    close(fp);

    return 0;
}
