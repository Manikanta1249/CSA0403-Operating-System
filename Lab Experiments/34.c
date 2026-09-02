#include <stdio.h>

int main() {
    int start, length, i;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks: ");
    scanf("%d", &length);

    printf("Allocated blocks:\n");

    for(i = 0; i < length; i++)
        printf("%d ", start + i);

    printf("\n");
    return 0;
}
