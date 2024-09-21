/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a separate program using signal system call to catch the following signals.
 b. SIGINT
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("SIGINT Signal recived\n");
    exit(1);
}

int main(){

    signal(SIGINT,signalhandler);
    printf("Press Ctrl C\n");
    while(1);
}