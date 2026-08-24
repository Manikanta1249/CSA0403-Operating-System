#include <stdio.h>
#include <string.h>

int main() {
    char files[20][30];
    int n = 0, choice;
    char name[30];

    while (1) {
        printf("\n1. Create File");
        printf("\n2. Display Files");
        printf("\n3. Search File");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter file name: ");
            scanf("%s", name);
            strcpy(files[n++], name);
            printf("File created.\n");
        }
        else if (choice == 2) {
            printf("\nFiles:\n");
            for (int i = 0; i < n; i++)
                printf("%s\n", files[i]);
        }
        else if (choice == 3) {
            printf("Enter file name: ");
            scanf("%s", name);

            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(files[i], name) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File found.\n");
            else
                printf("File not found.\n");
        }
        else
            break;
    }

    return 0;
}
