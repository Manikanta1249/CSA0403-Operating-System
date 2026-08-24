#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];
    char data[] = "Hello UNIX File Management";

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0) {
        printf("File opening failed.\n");
        return 1;
    }

    write(fd, data, strlen(data));

    lseek(fd, 0, SEEK_SET);

    int n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';

    printf("File Content: %s\n", buffer);

    close(fd);

    return 0;
}
