/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description :Write a program to create a shared memory.
 a. write some data to the shared memory
 b. attach with O_RDONLY and check whether you are able to overwrite.
 c. detach the shared memory
 d. remove the shared memory
b. ITIMER_VIRTUAL
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SM_SIZE 1024

int main(){
    key_t key = ftok("shmfile",345);
    int sm_id = shmget(key, SM_SIZE, 0666 | IPC_CREAT);
    if(sm_id == -1){
        perror("Shared Memory failed\n");
        exit(EXIT_FAILURE);
    }

    char* data = shmat(sm_id,NULL,0);
    strcpy(data,"Hi!");
    printf("Data written to shared Memory: %s\n",data);
    shmdt(data);
    data = shmat(sm_id, NULL,SHM_RDONLY);
    // Try to overwrite (this should fail)
    // strcpy(data, "Trying to overwrite"); // This should be checked
    printf("Read-only data in shared memory: %s\n", data);
    shmdt(data);
    if(shmctl(sm_id, IPC_RMID, NULL) == -1){
        perror("failed to remove\n");
        exit(EXIT_FAILURE);
    }
    printf("Shared Memory removed\n");
    return 0;



}