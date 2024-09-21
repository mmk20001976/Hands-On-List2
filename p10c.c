/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a separate program using sigaction system call to catch the following signals.
 a. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGFPE
void signalhandler(int signum) {
    printf("Caught SIGFPE: Floating Point Exception (signal number: %d)\n", signum);
    exit(EXIT_FAILURE); 
}

int main() {
    struct sigaction sa;

    sa.sa_handler = signalhandler;   
    sigemptyset(&sa.sa_mask);         
    sa.sa_flags = 0;                  

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("Error setting SIGFPE handler");
        exit(EXIT_FAILURE);
    }

    int a = 5;
    int b = 0;
    printf("Result: %d\n", a / b);    

    return 0;
}
