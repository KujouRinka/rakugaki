#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "file_t.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: cp <src> <dst>\n");
        exit(0);
    }
    ssize_t n = cpOmitHole(argv[1], argv[2]);
    if (n == -1) {
        printf("cp failed: %s\n", strerror(errno));
        exit(0);
    }

    printf("cp succeed, %ld bytes copied\n", n);
    return 0;
}
