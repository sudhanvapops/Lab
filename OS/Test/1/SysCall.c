#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for fork(), exec(), _exit()
#include <sys/wait.h> 

int main(){

    pid_t pid;

    printf("Before Fork Parent Pid: %d\n",getpid());

    pid = fork();

    if(pid > 0){
        printf("Parent wating for child to finsh\n");
        wait(NULL);
        printf("Child Process Completed. Parent Exiting\n");
    }else if(pid == 0){
        printf("Child Process Executing\nChild Process ID: %d\nParent Process ID: %d\n",getpid(),getppid());
        execlp("ls","ls",NULL);
        perror("Execlp Failed to execute");
        exit(1);
    }else{
        perror("Fork Has Failed\n");
        exit(1);
    }

}