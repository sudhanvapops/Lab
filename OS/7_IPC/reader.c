// 4. Develop a C program to demonstrate inter-process communication (IPC) between a reader and writer process using mkfifo, open, read, write, close APIs.

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char msg[100];
    mkfifo("myfifo", 0666);

    fd = open("myfifo", O_RDONLY);
    read(fd, msg, sizeof(msg));
    close(fd);

    printf("📩 Message received: %s\n", msg);
    return 0;
}

// gcc writer.c -o writer
// gcc reader.c -o reader

// # Terminal 1
// ./reader

// # Terminal 2
// ./writer
