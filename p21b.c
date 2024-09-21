/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :  Write two programs so that both can communicate by FIFO -Use two way communications.
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
    mkfifo(fifo2, 0666);
    // mkfifo(fifo_receive, 0666);

    char message[100];
    char response[100];

    while (1) {
        // Open the send FIFO for reading
        sleep(3);
        int fd_send = open(fifo1, O_RDONLY);
        read(fd_send, message, sizeof(message));
        
        // Exit condition
        if (strcmp(message, "exit") == 0) {
            break;
        }

        printf("Sender: %s\n", message);

        // Prepare a response
        printf("Receiver: Enter a response: ");
        fgets(response, sizeof(response), stdin);
        
        // Remove newline character from response
        response[strcspn(response, "\n")] = 0;

        // Open the receive FIFO for writing
        int fd_receive = open(fifo2, O_WRONLY);
        write(fd_receive, response, strlen(response) + 1);
        close(fd_receive);
        
        close(fd_send);
    }

    // Clean up
    unlink(fifo2);
    return 0;
}
