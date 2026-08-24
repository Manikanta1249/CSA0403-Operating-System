#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    struct stat st;
    DIR *dir;
    struct dirent *entry;

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0) {
        printf("File opening failed.\n");
        return 1;
    }

    printf("File opened successfully.\n");

    fcntl(fd, F_SETFL, O_APPEND);
    printf("fcntl executed.\n");

    lseek(fd, 0, SEEK_END);
    printf("File position moved using lseek.\n");

    if (stat("sample.txt", &st) == 0)
        printf("File size: %ld bytes\n", st.st_size);

    close(fd);

    dir = opendir(".");

    if (dir != NULL) {
        printf("\nDirectory contents:\n");

        while ((entry = readdir(dir)) != NULL)
            printf("%s\n", entry->d_name);

        closedir(dir);
    }

    return 0;
}
