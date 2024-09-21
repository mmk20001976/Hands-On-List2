/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
    sem_t *sem = sem_open("/mycountingsemaphore", O_CREAT, 0644, 3);
    if(sem == SEM_FAILED){
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }

    printf("Before Entering The Critical Section\n");
    sem_wait(sem);
    printf("Inside the Critical Section\n");
    sleep(2);
    printf("Press Enter to Exit CS\n");
    getchar();
    sem_post(sem);

    sem_close(sem);
    // sem_unlink("/mysemaphore");
    return 0;
}