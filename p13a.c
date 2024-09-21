/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signalHandler(int signo, siginfo_t *info, void* context){
    printf("SIGSTOP signal recived\n");
    exit(1);
}

int main(){

    struct sigaction sig_config;
    sig_config.sa_sigaction = signalHandler;
    sig_config.sa_flags = 0;
    sigaction(SIGSTOP, &sig_config, NULL);
    while(1); 
}

// Not able to catch the SIGSTOP signal