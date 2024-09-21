/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "my_fifo";
    
    // Open the FIFO for reading
    char message[100];

    while (1) {
        // Open the FIFO for reading
        int fd = open(fifo_name, O_RDONLY);
        read(fd, message, sizeof(message));

        // Exit condition: check if the message is empty
        if (strlen(message) == 0) {
            break; // Exit loop if no message is received
        }

        printf("Received: %s\n", message);
        close(fd);
    }

    return 0;
}
