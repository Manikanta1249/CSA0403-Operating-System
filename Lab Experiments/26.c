#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50], data[200];
    int choice;

    while (1) {
        printf("\n1. Create File");
        printf("\n2. Write File");
        printf("\n3. Read File");
        printf("\n4. Append File");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter file name: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");

            if (fp != NULL) {
                printf("File created successfully.\n");
                fclose(fp);
            }
        }

        else if (choice == 2) {
            printf("Enter file name: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");

            printf("Enter data: ");
            scanf(" %[^\n]", data);

            fprintf(fp, "%s", data);
            fclose(fp);

            printf("Data written successfully.\n");
        }

        else if (choice == 3) {
            printf("Enter file name: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if (fp == NULL) {
                printf("File not found.\n");
            } else {
                printf("\nFile content:\n");

                while (fgets(data, sizeof(data), fp))
                    printf("%s", data);

                fclose(fp);
            }
        }

        else if (choice == 4) {
            printf("Enter file name: ");
            scanf("%s", filename);

            fp = fopen(filename, "a");

            printf("Enter data: ");
            scanf(" %[^\n]", data);

            fprintf(fp, "\n%s", data);
            fclose(fp);

            printf("Data appended successfully.\n");
        }

        else if (choice == 5) {
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
