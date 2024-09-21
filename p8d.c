/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a separate program using signal system call to catch the following signals.
 d. SIGALRM (use alarm system call)
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("SIGALRM recived\n");
    exit(1);
}

int main(){

    signal(SIGALRM,signalhandler);
    alarm(5);
    while(1);
}
