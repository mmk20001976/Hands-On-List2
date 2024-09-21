/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
 a. access permission
 b. uid, gid
 c. time of last message sent and received
 d. time of last change in the message queue
 d. size of the queue
 f. number of messages in the queue
 g. maximum number of bytes allowed
 h. pid of the msgsnd and msgrcv
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

int main(){
    key_t key =1234;
    int msgq_id = msgget(key, 0666 | IPC_CREAT);
    if( msgq_id== -1){
        perror("Message queue failed\n");
        exit(EXIT_FAILURE);
    }

    struct msqid_ds buf;
    if(msgctl(msgq_id, IPC_STAT, &buf) == -1) {
        perror("msgctl failed");
        exit(EXIT_FAILURE);
    }
    printf("Access Permissions: %o\n", buf.msg_perm.mode & 0777);
    printf("Owner UID: %d\n", buf.msg_perm.uid);
    printf("Owner GID: %d\n", buf.msg_perm.gid);
    printf("Last message sent time: %s", ctime(&buf.msg_stime));
    printf("Last message received time: %s", ctime(&buf.msg_rtime));
    printf("Last change time: %s", ctime(&buf.msg_ctime));
    printf("Queue Size (bytes): %lu\n", buf.__msg_cbytes);
    printf("Number of Messages: %lu\n", buf.msg_qnum);
    printf("Maximum Bytes Allowed: %lu\n", buf.msg_qbytes);
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);
    return 0;

}