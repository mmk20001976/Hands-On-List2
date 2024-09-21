/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <errno.h>

int main() {
    const char *fifo_name = "my_fifo";
    int fd = open(fifo_name, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("Failed to open FIFO");
        exit(EXIT_FAILURE);
    }

    char message[100];
    fd_set read_fds;
    struct timeval timeout;

    while (1) {
        // Clear the set and add the FIFO file descriptor
        FD_ZERO(&read_fds);
        FD_SET(fd, &read_fds);

        // Set timeout to 10 seconds
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        // Wait for data to be written to the FIFO
        int ret = select(fd + 1, &read_fds, NULL, NULL, &timeout);

        if (ret == -1) {
            perror("select error");
            break;
        } else if (ret == 0) {
            printf("No data received within 10 seconds. Timing out...\n");
            break;
        } else {
            read(fd, message, sizeof(message));
            if (strlen(message) == 0) {
                break; // Exit loop if no message is received
            }
            printf("Received: %s\n", message); 
            exit(EXIT_SUCCESS);
        }
    }

    // Clean up
    close(fd);
    unlink(fifo_name); // Remove the FIFO
    return 0;
}
