/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signalHandler(int signo, siginfo_t *info, void *context){
    printf("SIGSEGV received\n");
    printf("Signal Number: %d\n",signo);
    printf("Adress where Fault occured: %p\n",info->si_addr);
    exit(1);
}

int main(){

    struct sigaction sig_conf;
    sig_conf.sa_sigaction = signalHandler;
    sig_conf.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV,&sig_conf,NULL);

    int *p = NULL;
    *p =100;
    
    return 0;
}