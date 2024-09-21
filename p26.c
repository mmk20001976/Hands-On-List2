/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_TEXT 100

struct message{
    long msg_type;
    char msg_text[MAX_TEXT];
};

int main(){
    key_t key =1000;
    int msgq_id = msgget(key, 0666 | IPC_CREAT);
    if( msgq_id== -1){
        perror("Message queue failed\n");
        exit(EXIT_FAILURE);
    }
    struct message msg;
    msg.msg_type = 1;
    for(int i=0;i<3;i++){
        snprintf(msg.msg_text,MAX_TEXT,"Message id : %d",i+1);
        if(msgsnd(msgq_id, &msg, sizeof(msg.msg_text), 0) == -1){
            perror("Message Send Failed\n");
            exit(EXIT_FAILURE);
        }
        printf("Message Sent : %s\n",msg.msg_text);
    }


}