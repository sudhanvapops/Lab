// run in linux 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for fork(), exec(), _exit()
#include <sys/wait.h> // for wait()

int main() {
    pid_t pid;

    // gives the process ID of the current program.
    printf("Before fork. Parent PID = %d\n", getpid());

    // creates a child process by duplicating the parent.
    pid = fork();   // create a child process
    // the parent gets +ve number
    // the child gets 0

    // AFter duplicating execution starts from here not from begining

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // This block runs ONLY in the child process.
        // It prints its own PID and the parent PID.
        // Child process
        printf("Child process created. PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Replace child with "ls" command (exec system call)
        // 1st ls this tells the system: “Find the program called ls in the system PATH
        // 2nd ls like running the program 
        execlp("pwd","pwd",NULL);
        // if succesfully executed wont continue down 

        // If exec fails
        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent waiting for child to finish...\n");
        wait(NULL);   // wait for child to terminate
        printf("Child process terminated. Parent exiting.\n");
    }

    return 0;
}
