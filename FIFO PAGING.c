#include <stdio.h>

int main() {
    int pages[50], frame[10];
    int n, f, i, j, k, flag, pageFault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
        frame[i] = -1;

    j = 0; // pointer for FIFO

    for(i = 0; i < n; i++) {
        flag = 0;

        // Check if page already present
        for(k = 0; k < f; k++) {
            if(frame[k] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If not present ? page fault
        if(flag == 0) {
            frame[j] = pages[i];
            j = (j + 1) % f;  // FIFO replacement
            pageFault++;
        }

        // Print frames
        printf("\n");
        for(k = 0; k < f; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFault);

    return 0;
}
