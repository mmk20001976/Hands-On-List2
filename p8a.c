/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a separate program using signal system call to catch the following signals.
 a. SIGSEGV
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("Segmentation fault occured\n");
    exit(1);
}
int main(){

    signal(SIGSEGV,signalhandler);
    int *p = NULL;
    *p = 42; 
    return 0;

}