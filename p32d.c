/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : 32. Write a program to implement semaphore to protect any critical section.
 a. rewrite the ticket number creation program using semaphore
 b. protect shared memory from concurrent write access
 c. protect multiple pseudo resources ( may be two) using counting semaphore
 d. remove the created semaphore 
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int main() {
    sem_t sem;

    // Initialize semaphore
    if (sem_init(&sem, 0, 1) == -1) {
        perror("failed");
        exit(EXIT_FAILURE);
    }

    printf("Semaphore created and initialized.\n");
    sem_destroy(&sem);
    return 0;
}
