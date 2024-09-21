/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter. 
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <x86intrin.h>  
#include <stdint.h>     
#include <unistd.h> 

int main(){
    uint64_t start,end;
    start = _rdtsc();
    for(int i=0;i<100;i++)
    getpid();
    end = _rdtsc();
    printf("cpu cycles taken: %lu\n",end-start);
}