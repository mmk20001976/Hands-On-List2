/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to print the system resource limits. Use getrlimit system call
Date: 20th Sep, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <sys/resource.h>
void Dispaly(int resource, char* name){
    struct rlimit limit;
    if(getrlimit(resource, &limit) !=0){
        perror("System-Call failed\n");
        exit(EXIT_FAILURE);
    }


    if(limit.rlim_cur == RLIM_INFINITY)
    printf("Soft limit(Current) of is unlimited\n");
    else
    printf("Soft limit(Current) of %s is %lu:",name,(unsigned long) limit.rlim_cur);

    if(limit.rlim_max == RLIM_INFINITY)
    printf("Hard limit(MAX) of is unlimited\n");
    else
    printf("Hard limit(MAX) of %s is %lu:",name,(unsigned long) limit.rlim_max);


}
int main(){
    Dispaly(RLIMIT_CPU, "CPU time limit");
    Dispaly(RLIMIT_FSIZE, "File size limit");
    Dispaly(RLIMIT_DATA, "Data segment size limit");
    Dispaly(RLIMIT_STACK, "Stack size limit");
    Dispaly(RLIMIT_CORE, "Core file size limit");
    Dispaly(RLIMIT_RSS, "Resident set size limit");
    Dispaly(RLIMIT_NOFILE, "Number of open files limit");
    Dispaly(RLIMIT_MEMLOCK, "Locked memory size limit");
    Dispaly(RLIMIT_AS, "Address space limit");
    Dispaly(RLIMIT_NPROC, "Number of processes limit");
    Dispaly(RLIMIT_LOCKS, "File locks limit");
    return 0;
}
