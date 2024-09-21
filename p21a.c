/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write two programs so that both can communicate by FIFO -Use two way communications
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
    const char *fifo1 = "fifo1";   // FIFO for sending messages
    const char *fifo2 = "fifo2"; // FIFO for receiving messages

    // Create FIFOs if they don't exist
    mkfifo(fifo1, 0666);
    // mkfifo(fifo_receive, 0666);

    char message[100];
    char response[100];

    while (1) {
        printf("Sender: Enter a message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        
        message[strcspn(message, "\n")] = 0;

        // Exit condition
        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Open the send FIFO for writing
        int fd_send = open(fifo1, O_WRONLY);
        write(fd_send, message, strlen(message) + 1);
        close(fd_send);

        // Open the receive FIFO for reading
        int fd_receive = open(fifo2, O_RDONLY);
        read(fd_receive, response, sizeof(response));
        printf("Receiver: %s\n", response);
        close(fd_receive);
    }

    // Clean up
    unlink(fifo1);
    return 0;
}
