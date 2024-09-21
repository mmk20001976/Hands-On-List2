/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :  Write a program to receive messages from the message queue.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>

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

    for(int i=0;i<3;i++){
        message.msg_type = 1;       
        snprintf(message.msg_text,sizeof(message.msg_text),"Hi! I am Message %d",i+1);
        msgsnd(q_id, &message, sizeof(message.msg_text), 0);
        sleep(1);
    }

    message.msg_type = 1;
    strcpy(message.msg_text,"0");
    msgsnd(q_id, &message, sizeof(message.msg_text), 0);
    return 0;
}
