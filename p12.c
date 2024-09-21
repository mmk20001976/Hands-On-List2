/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(){

    int id = fork();
    if(id<0){
        perror("Fork failed\n");
        exit(1);
    }

    if(id == 0){
        sleep(5); // waiting for parent to begin execution;
        int parent_pid = getppid();
        printf("Before becoming Orphan Parent Process id: %d\n",parent_pid);
        kill(parent_pid,SIGKILL);
        
        printf("Process has become Orphan\n");
        while(1);
        
    }
    else{
        printf("Waiting for a Signal from Child Process\n");
        sleep(10);
    }

    return 0;
}