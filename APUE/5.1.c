#include <stdio.h>
#include <sys/stat.h>

void mySetbuf(FILE *restrict fp, char *restrict buf) {
    int mode_flg;
    struct stat st;
    fstat(fileno(fp), &st);
    if (S_ISFIFO(st.st_mode) || S_ISSOCK(st.st_mode) ||
        S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
        mode_flg = _IOLBF;
    else
        mode_flg = _IOFBF;
    setvbuf(fp, buf, mode_flg, BUFSIZ);
}

