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
#include <unistd.h>
#include <semaphore.h>

sem_t sem_resources;

void* access_resources(void* arg) {
    sem_wait(&sem_resources);  // Acquire resource

    printf("Thread %ld is accessing a resource.\n", (long)arg);
    sleep(1);  // Simulate resource usage
    printf("Thread %ld has finished using the resource.\n", (long)arg);

    sem_post(&sem_resources);  // Release resource
    return NULL;
}

int main() {
    pthread_t threads[5];

    // Initialize counting semaphore with 2 resources
    sem_init(&sem_resources, 0, 2);

    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, access_resources, (void*)i);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_resources);  // Destroy semaphore
    return 0;
}
