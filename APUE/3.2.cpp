int isOpen(int fd) {
    int old_errno = errno;
    int test_f = dup(fd);
    errno = old_errno;
    if (test_f == -1) {
        return 0;
    }
    close(test_f);
    return 1;
}

int recursiveDup(int sf, int tf) {
    int nf = dup(sf);
    if (nf == -1)
        return -1;
    if (nf == tf)
        return nf;
    int rf = recursiveDup(sf, tf);
    if (rf != -1)
        close(nf);
    return rf;
}

int myDup2(int fd, int fd2) {
    if (fd < 0 || fd >= getdtablesize() || fd2 < 0 || fd2 >= getdtablesize() || !isOpen(fd)) {
        errno = EBADF;
        return -1;
    }
    if (fd == fd2)
        return fd;
    if (isOpen(fd2))
        close(fd2);
    if ((fd2 = recursiveDup(fd, fd2)) == -1)
        errno = EBADF;
    return fd2;
}

