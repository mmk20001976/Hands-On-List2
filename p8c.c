/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a separate program using signal system call to catch the following signals.
 c. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
void signalhandler(int sig_no){
    printf("Overflow\n");
    exit(1);
}

int main(){

    signal(SIGFPE,signalhandler);
    float a = 3.0;
    float b = 0.0;
    a = a/b;
    while(1);
    // scanf("%f",&b);
    // a = a/b;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>

// // Signal handler function for SIGFPE
// void signalhandler(int sig_no) {
//     if (sig_no == SIGFPE) {
//         printf("Floating-point exception (SIGFPE) occurred.\n");
//         exit(1);
//     }
// }

// int main() {
//     // Set up the signal handler for SIGFPE
//     if (signal(SIGFPE, signalhandler) == SIG_ERR) {
//         perror("Unable to set signal handler");
//         exit(1);
//     }

//     float a = 3.0;
//     float b;

//     // Prompt user for input
//     printf("Enter a value for b: ");
//     if (scanf("%f", &b) != 1) {
//         fprintf(stderr, "Invalid input.\n");
//         exit(1);
//     }

//     // Perform division
//     a = a / b;

//     // Print result
//     printf("Result of division: %f\n", a);

//     return 0;
// }
