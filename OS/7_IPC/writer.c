#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char msg[100];
    mkfifo("myfifo", 0666);

    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);

    fd = open("myfifo", O_WRONLY);
    write(fd, msg, sizeof(msg));
    close(fd);

    printf("✅ Message sent.\n");
    return 0;
}
