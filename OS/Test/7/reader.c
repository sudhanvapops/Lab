#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){

    int fd;
    char msg[100];
    mkfifo("myfifo",0666);

    fd = open("myfifo",O_RDONLY);
    read(fd,msg,sizeof(msg));
    close(fd);

    printf("Message received: %s\n", msg);
    
    return 0;
}