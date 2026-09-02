#include <stdio.h>

int main() {
    int p[20], f[10], n, nf, i, j, k, pos, far, next, fault = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &nf);

    for(i = 0; i < nf; i++) f[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < nf; j++)
            if(f[j] == p[i]) found = 1;

        if(!found) {
            pos = 0;
            far = -1;

            for(j = 0; j < nf; j++) {
                if(f[j] == -1) { pos = j; break; }

                next = 999;
                for(k = i + 1; k < n; k++)
                    if(f[j] == p[k]) { next = k; break; }

                if(next > far) {
                    far = next;
                    pos = j;
                }
            }

            f[pos] = p[i];
            fault++;
        }

        for(j = 0; j < nf; j++) printf("%d ", f[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n", fault);
    return 0;
}
