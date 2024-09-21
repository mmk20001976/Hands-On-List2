/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a program to print the system limitation of
 a. maximum length of the arguments to the exec family of functions.
 b. maximum number of simultaneous process per user id.
 c. number of clock ticks (jiffy) per second.
 d. maximum number of open files
 e. size of a page
 f. total number of pages in the physical memory
 g. number of currently available pages in the physical memory. 
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h> 
#include <sys/sysinfo.h>


int main() {
    
    printf("Maximum length of arguments to exec: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Maximum number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Number of clock ticks (jiffy) per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Size of a page: %ld bytes\n", sysconf(_SC_PAGESIZE));
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Total number of pages in physical memory: %ld\n", info.totalram / sysconf(_SC_PAGESIZE));
        printf("Number of currently available pages in physical memory: %ld\n", info.freeram / sysconf(_SC_PAGESIZE));
    }
    else
    perror("sysinfo");
    

    return 0;
}