/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write two programs so that both can communicate by FIFO -Use one way communication.
b. ITIMER_VIRTUAL
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
    
    // Create a FIFO if it doesn't exist
    mkfifo(fifo_name, 0666);

    char message[100];
    
    while (1) {
        printf("Enter a message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        
        // Remove newline character from message
        message[strcspn(message, "\n")] = 0;

        // Exit condition
        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Open the FIFO for writing
        int fd = open(fifo_name, O_WRONLY);
        write(fd, message, strlen(message) + 1); // Include null terminator
        close(fd);
    }

    // Clean up
    unlink(fifo_name); // Remove the FIFO
    return 0;
}
