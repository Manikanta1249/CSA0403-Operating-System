#include <stdio.h>

int main() {
    int n, r, i, j, k;
    int alloc[10][10], max[10][10], need[10][10], avail[10];
    int finish[10] = {0}, safe[10], count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int possible = 1;

                for (j = 0; j < r; j++)
                    if (need[i][j] > avail[j])
                        possible = 0;

                if (possible) {
                    for (j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n) {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    } else {
        printf("\nSystem is NOT in safe state.");
    }

    return 0;
}
