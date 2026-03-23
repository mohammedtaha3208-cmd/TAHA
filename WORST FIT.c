#include <stdio.h>

int main() {
    int block[10], process[10];
    int allocation[10];
    int m, n, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    // WORST FIT (DYNAMIC)
    for(i = 0; i < n; i++) {
        int worst = -1;

        for(j = 0; j < m; j++) {
            if(block[j] >= process[i]) {
                if(worst == -1 || block[j] > block[worst]) {
                    worst = j;
                }
            }
        }

        if(worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];  // reduce size
        }
    }

    // OUTPUT
    printf("\nProcess\tSize\tBlock\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t", i+1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
