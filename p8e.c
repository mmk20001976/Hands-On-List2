/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a separate program using signal system call to catch the following signals.
 e. SIGALRM (use setitimer system call)
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("Real-Timer Expired\n");
}
int main(){
    struct itimerval timer; // to set the time
    signal(SIGALRM,signalhandler); // Real time interval sends a SIGALRM 

    timer.it_value.tv_sec = 10; // it_value sets the timer for the first time
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 5; // sets the reccuring interval after which signal will be sent
    timer.it_interval.tv_sec = 5;

    setitimer(ITIMER_REAL,&timer,NULL);

    while(1);
    return 0;

}