/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main(){
    int pipe1[2]; // parent to child 
    int pipe2[2]; // child to parent
    int id;
    char buffer[BUFFER_SIZE];
    if(pipe(pipe1) == -1){
        perror("Failed\n");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipe2) == -1){
        perror("Failed\n");
        exit(EXIT_FAILURE);
    }

    id = fork();

    if(id<0){
        perror("Fork Failed\n");
        exit(EXIT_FAILURE);
    }
    if(id == 0){
        sleep(1);

        close(pipe1[1]);
        ssize_t numBytes = read(pipe1[0],buffer,sizeof(buffer));
        buffer[numBytes] = '\0';
        printf("Message Sent by Parent: %s\n",buffer);
        close(pipe1[0]);

        close(pipe2[0]);
        char* msg_Child = "Hi! I am the Child process\n";
        write(pipe2[1],msg_Child,strlen(msg_Child));
        close(pipe2[1]);

    }
    else{
        close(pipe1[0]);
        char* msg_Parent = "Hi! I am the Parent process\n";
        write(pipe1[1],msg_Parent,strlen(msg_Parent));
        close(pipe1[1]);
        
        sleep(3);

        close(pipe2[1]);
        ssize_t numBytes = read(pipe2[0],buffer,sizeof(buffer));
        buffer[numBytes] = '\0';
        printf("Message Sent by Child: %s\n",buffer);
        close(pipe2[0]);
    }

}