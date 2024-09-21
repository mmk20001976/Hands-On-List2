/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

int main() {
    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files within a process: %ld\n", max_files);

    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("Error creating pipe");
        return 1;
    }

    int pipe_size;
    if (ioctl(pipe_fds[0], FIONREAD, &pipe_size) == -1) {
        perror("Error getting the size of the pipe's buffer");
    } else {
        printf("Size of the pipe (circular buffer): %d bytes\n", pipe_size);
    }

    close(pipe_fds[0]);
    close(pipe_fds[1]);

    return 0;
}
