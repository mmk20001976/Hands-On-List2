/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to create a message queue and print the key and message queue id
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

int main(){
    key_t key =12;
    int msgq_id = msgget(key, 0666 | IPC_CREAT);
    if( msgq_id== -1){
        perror("Message queue failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Message Queue Key: %d\n",key);
    printf("Message Queue ID: %d\n",msgq_id);
    return 0;
}