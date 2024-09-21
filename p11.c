/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : 1. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void new_signalHandler(int signo, siginfo_t *info, void *context ){
    printf("SIGINT received\n");
    printf("Doing Nothing\n");
    return;
   
}
void default_signalHandler(int signo, siginfo_t *info, void *context){
    printf("SIGINT received\n");
    exit(1);
}



int main(){

    struct sigaction sig_config;
    sig_config.sa_sigaction = new_signalHandler;
    sig_config.sa_flags = 0;
    sigaction(SIGINT, &sig_config, NULL);

    printf("Press Ctrl + C (does nothing)\n");
    sleep(5);

    memset(&sig_config, 0, sizeof(sig_config));
    sig_config.sa_sigaction = default_signalHandler;
    sig_config.sa_flags = 0;

    sigaction(SIGINT, &sig_config, NULL); 
    printf("Press Ctrl + C (default behaviour)\n");
    while(1);

    return 0;
}