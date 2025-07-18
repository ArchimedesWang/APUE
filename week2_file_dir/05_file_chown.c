#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filename> <owner_uid> <group_gid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    uid_t owner = (uid_t)atoi(argv[2]);
    gid_t group = (gid_t)atoi(argv[3]);

    if (chown(filename, owner, group) == -1) {
        perror("chown error");
        exit(EXIT_FAILURE);
    }

    printf("chown success: %s -> uid:%d gid:%d\n", filename, owner, group);

    return 0;
}

