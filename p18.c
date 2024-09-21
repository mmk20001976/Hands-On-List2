/*
============================================================================
Name : p1.c
Author : Mohammed Mubashir Khan
Description : WWrite a program to find out total number of directories on the pwd.
 execute ls -l | grep ^d | wc ? Use only dup2.
Date: 20th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pipefd[2];
    int pipefd2[2];
    if(pipe(pipefd) == -1){
        perror("Pipe Creation Failed\n");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipefd2) == -1){
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
        dup2(pipefd[1],STDOUT_FILENO);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
    }


    int id2 = fork();
    if(id2<0){
        perror("Fork Failed\n");
        exit(EXIT_FAILURE);
    }

    if(id2 == 0){
        close(pipefd[1]); // 1st pipe write end
        dup2(pipefd[0],STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd2[0]); // 2nd pipe read end
        dup2(pipefd2[1],STDOUT_FILENO);
        close(pipefd2[1]);
        execlp("grep", "grep", "^d", (char *)NULL);
    }
    int id3 = fork();
    if(id3<0){
        perror("Fork Failed\n");
        exit(EXIT_FAILURE);
    }

    if(id3 == 0){
        close(pipefd[0]);
        close(pipefd[1]);
        close(pipefd2[1]); // 2nd pipe write end
        dup2(pipefd2[0],STDIN_FILENO);
        close(pipefd2[0]);
        execlp("wc", "wc", (char *)NULL);
    }


    close(pipefd[0]);
    close(pipefd[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);

    // Wait for both child processes to finish
    waitpid(id1, NULL, 0);
    waitpid(id2, NULL, 0);
    waitpid(id3, NULL, 0);

    return 0;

}


