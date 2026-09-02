#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, disk, i, j, temp, movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk);

    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(req[i] > req[j]) {
                temp = req[i]; req[i] = req[j]; req[j] = temp;
            }

    for(i = 0; i < n && req[i] < head; i++);

    for(j = i; j < n; j++) {
        movement += abs(head - req[j]);
        head = req[j];
    }

    movement += abs(head - (disk - 1));
    head = disk - 1;

    for(j = i - 1; j >= 0; j--) {
        movement += abs(head - req[j]);
        head = req[j];
    }

    printf("Total head movement = %d\n", movement);
    return 0;
}
