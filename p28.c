/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(){
    key_t key = ftok("message queue",987);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1){
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    struct msqid_ds info;
    if(msgctl(msgid, IPC_STAT, &info) == -1) {
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    printf("Current permissions %o\n",info.msg_perm.mode);
    info.msg_perm.mode = 0644;


    if(msgctl(msgid, IPC_SET, &info) == -1) {
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }

    if(msgctl(msgid, IPC_STAT, &info) == -1) {
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    printf("Updated permissions %o\n",info.msg_perm.mode);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;

}