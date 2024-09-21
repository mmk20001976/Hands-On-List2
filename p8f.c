/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a separate program using signal system call to catch the following signals.
 f. SIGVTALRM (use setitimer system call)
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int sig_no){
    printf("Virtual Timer Expired\n");
}

int main(){

    struct itimerval timer;
    signal(SIGVTALRM, signalHandler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 5;

    setitimer(ITIMER_VIRTUAL,&timer,NULL);

    while(1);
    return 0;


}