#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

void print_permissions(mode_t mode) {
    char perms[10] = "---------";

    if (mode & S_IRUSR) perms[0] = 'r';
    if (mode & S_IWUSR) perms[1] = 'w';
    if (mode & S_IXUSR) perms[2] = 'x';
    if (mode & S_IRGRP) perms[3] = 'r';
    if (mode & S_IWGRP) perms[4] = 'w';
    if (mode & S_IXGRP) perms[5] = 'x';
    if (mode & S_IROTH) perms[6] = 'r';
    if (mode & S_IWOTH) perms[7] = 'w';
    if (mode & S_IXOTH) perms[8] = 'x';

    printf("Permissions: %s\n", perms);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open error");
        exit(1);
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat error");
        close(fd);
        exit(1);
    }

    printf("File: %s\n", argv[1]);
    printf("Size: %ld bytes\n", sb.st_size);
    printf("Mode: %o (octal)\n", sb.st_mode & 0777);  // 只保留权限位
    print_permissions(sb.st_mode);
    printf("Last access: %s", ctime(&sb.st_atime));

    close(fd);
    return 0;
}

