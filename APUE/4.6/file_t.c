#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 2048

#include "file_t.h"

ssize_t cpOmitHole(char *src, char *dst) {
    if (strcmp(src, dst) == 0)
        return 0;
    int f_src = open(src, O_RDONLY);
    if (f_src == -1)
        return -1;
    int f_dst = open(dst, O_CREAT | O_WRONLY | O_EXCL);
    if (f_dst == -1) {
        close(f_src);
        return -1;
    }

    char buf[BUF_SIZE];
    ssize_t cpsz = 0;
    while (1) {
        ssize_t n = read(f_src, buf, BUF_SIZE);
        if (n == 0) {
            break;
        } else if (n == -1) {
            close(f_dst);
            close(f_src);
            return -1;
        }
        char *p_left = buf;
        char *p_right = buf;
        ssize_t cur_read = 0;
        while (cur_read != n) {
            while (cur_read != n && *p_right != '\0') {
                ++p_right;
                ++cur_read;
            }
            if (write(f_dst, p_left, p_right - p_left) == -1) {
                close(f_dst);
                close(f_src);
                return -1;
            }
            cpsz += cur_read;
            while (cur_read != n && *p_right == '\0') {
                ++p_right;
                ++cur_read;
            }
            p_left = p_right;
        }
    }
    close(f_dst);
    close(f_src);
    return cpsz;
}

