#include <stdio.h>

int main() {
    int p[20], f[10], used[10], n, nf, i, j, k, pos, min, fault = 0, found;

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
            for(j = 0; j < nf; j++)
                if(f[j] == -1) { pos = j; break; }

            if(f[pos] != -1) {
                min = 999;
                for(j = 0; j < nf; j++) {
                    used[j] = -1;
                    for(k = i - 1; k >= 0; k--)
                        if(f[j] == p[k]) { used[j] = k; break; }

                    if(used[j] < min) {
                        min = used[j];
                        pos = j;
                    }
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
