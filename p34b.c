/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : . Write a program to create a concurrent server.
 a. use fork
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void handle_client(int client_sock) {
    char buffer[256];
    int n;

    bzero(buffer, 256);
    n = read(client_sock, buffer, 255);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("Client message: %s", buffer);

    n = write(client_sock, "Message received\n", 18);
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    close(client_sock);
}

int main() {
    int sockfd, newsockfd, portno = 5001;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int pid;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("Server listening on port %d...\n", portno);

    // Accept and handle connections in a loop
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accept");
            exit(1);
        }

        // Fork a new process to handle the client
        pid = fork();
        if (pid < 0) {
            perror("Error on fork");
            exit(1);
        }

        if (pid == 0) {  // Child process
            close(sockfd);  // Close the main server socket in the child
            handle_client(newsockfd);
            exit(0);
        } else {  // Parent process
            close(newsockfd);  // Close the client socket in the parent
        }
    }
}