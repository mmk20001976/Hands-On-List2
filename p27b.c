/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 100

struct msg{
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main(){
    struct msg message;
    key_t key = ftok("message queue",1079);
    int q_id = msgget(key, 0666 | IPC_CREAT);
    if(q_id == -1){
        perror("Message Queue creation failed\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        if(msgrcv(q_id, &message, sizeof(message.msg_text), 0, 0) == -1) {
            perror("failed\n");
            exit(1);
        }

        if (strcmp(message.msg_text, "0") == 0) {
            printf("Received flag 0, stopping the receiver.\n");
            break;
        } else {
            printf("Received message: %s\n", message.msg_text);
        }
        
    }

    msgctl(q_id, IPC_RMID, NULL);
    return 0;
}
