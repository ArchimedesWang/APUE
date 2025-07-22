#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <dest_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open %s for reading\n", argv[1]);
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    FILE *fpc = fopen(argv[2], "w");
    if (fpc == NULL) {
        fprintf(stderr, "Failed to open %s for writing\n", argv[2]);
        perror("fopen");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (fputc(c, fpc) == EOF) {
            perror("fputc error");
            fclose(fp);
            fclose(fpc);
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp);
    fclose(fpc);

    printf("File copied: %s -> %s\n", argv[1], argv[2]);
    return 0;
}


