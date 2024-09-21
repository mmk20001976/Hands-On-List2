/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to set (any one) system resource limit. Use setrlimit system call. 
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){
    struct rlimit limit;
    if(getrlimit(RLIMIT_FSIZE,&limit) != 0){
        perror("getrlimit failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Soft Limit: ");
    if(limit.rlim_cur == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long) limit.rlim_cur);

    printf("Hard Limit: ");
    if(limit.rlim_max == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long)limit.rlim_max);

    // changing limit;
    limit.rlim_cur = 2048;
    limit.rlim_max = 4096;
    if(setrlimit(RLIMIT_FSIZE,&limit)!=0){
       perror("getrlimit failed\n");
       exit(EXIT_FAILURE);
    }


    printf("New Soft Limit: ");
    if(limit.rlim_cur == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long) limit.rlim_cur);

    printf("New Hard Limit: ");
    if(limit.rlim_max == RLIM_INFINITY)
    printf("unlimited\n");
    else
    printf("%lu\n",(unsigned long) limit.rlim_max);
}