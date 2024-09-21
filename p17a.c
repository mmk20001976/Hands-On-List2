/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : Description :. Write a program to execute ls -l | wc.
a. use dup
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pipefd[2];
    if(pipe(pipefd) == -1){
        perror("Pipe Creation Failed\n");
        exit(EXIT_FAILURE);
    }
    int id1 = fork();
    if(id1<0){
        perror("Fork Failed\n");
        exit(EXIT_FAILURE);
    }

    if(id1 == 0){
        close(pipefd[0]);
        close(STDOUT_FILENO);
        dup(pipefd[1]);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
    }

    int id2 = fork();
    if(id2<0){
        perror("Fork Failed\n");
        exit(EXIT_FAILURE);
    }

    if(id2 == 0){
        close(pipefd[1]);
        close(STDIN_FILENO);
        dup(pipefd[0]);
        close(pipefd[0]);
        execlp("wc", "wc", (char *)NULL);
    }


    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both child processes to finish
    waitpid(id1, NULL, 0);
    waitpid(id2, NULL, 0);

    return 0;

}

