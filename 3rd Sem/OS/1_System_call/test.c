#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for fork(), exec(), _exit()
#include <sys/wait.h>

int main(){

    pid_t pid;

    printf("Before fork Parent PID: %d\n",getpid());
    pid = fork();

    if(pid < 0){
        perror("Error Creating Child process");
        exit(1);
    }else if(pid == 0){
        printf("Child Process id: %d, Parent id: %d\n",getpid(),getppid());
        execlp("ls","ls",NULL);
        perror("exec failed");
        exit(1);
    }else{
        printf("Waiting for Child to finsih\n");
        wait(NULL);
        printf("Child process finished\n");
    }

    
    return 0;
}