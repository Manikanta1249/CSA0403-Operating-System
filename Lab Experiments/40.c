#include <stdio.h>
#include <sys/stat.h>

int main() {
    char file[50];
    struct stat s;

    printf("Enter file name: ");
    scanf("%s", file);

    if(stat(file, &s) != 0) {
        printf("File not found.\n");
        return 1;
    }

    printf("File permissions: %o\n", s.st_mode & 0777);

    printf("Read permission  : %s\n",
           (s.st_mode & S_IRUSR) ? "Yes" : "No");

    printf("Write permission : %s\n",
           (s.st_mode & S_IWUSR) ? "Yes" : "No");

    printf("Execute permission: %s\n",
           (s.st_mode & S_IXUSR) ? "Yes" : "No");

    return 0;
}
