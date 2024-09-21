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

int ticket_number = 0;  // Shared resource
sem_t sem;

void* create_ticket(void* arg) {
    sem_wait(&sem);  // Enter critical section (P operation)

    ticket_number++;
    printf("Thread %ld created ticket number: %d\n", (long)arg, ticket_number);

    sem_post(&sem);  // Exit critical section (V operation)
    return NULL;
}

int main() {
    pthread_t threads[5];
    
    // Initialize semaphore as binary (1)
    sem_init(&sem, 0, 1);

    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, create_ticket, (void*)i);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);  // Destroy semaphore
    return 0;
}