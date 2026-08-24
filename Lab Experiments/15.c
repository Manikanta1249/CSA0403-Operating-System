#include <stdio.h>
#include <string.h>

struct User {
    char name[30];
    char files[20][30];
    int count;
};

int main() {
    struct User users[10];
    int nu = 0, choice;
    char username[30], filename[30];

    while (1) {
        printf("\n1. Create User");
        printf("\n2. Create File");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter user name: ");
            scanf("%s", users[nu].name);
            users[nu].count = 0;
            nu++;
            printf("User created.\n");
        }

        else if (choice == 2) {
            printf("Enter user name: ");
            scanf("%s", username);

            int found = -1;
            for (int i = 0; i < nu; i++)
                if (strcmp(users[i].name, username) == 0)
                    found = i;

            if (found != -1) {
                printf("Enter file name: ");
                scanf("%s", filename);
                strcpy(users[found].files[users[found].count++], filename);
                printf("File created.\n");
            } else {
                printf("User not found.\n");
            }
        }

        else if (choice == 3) {
            for (int i = 0; i < nu; i++) {
                printf("\nUser: %s\n", users[i].name);
                for (int j = 0; j < users[i].count; j++)
                    printf("  %s\n", users[i].files[j]);
            }
        }

        else
            break;
    }

    return 0;
}
