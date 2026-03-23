#include <stdio.h>

int main() {
    int pages[50], frame[10], time[10];
    int n, f, i, j, k, flag, pageFault = 0, t = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        flag = 0;

        // Check if page already present
        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                time[j] = ++t; // update recent use
                break;
            }
        }

        // If not present ? page fault
        if(flag == 0) {
            int lru = 0;

            // find least recently used
            for(j = 1; j < f; j++) {
                if(time[j] < time[lru])
                    lru = j;
            }

            frame[lru] = pages[i];
            time[lru] = ++t;
            pageFault++;
        }

        // Print frames
        printf("\n");
        for(j = 0; j < f; j++) {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", pageFault);

    return 0;
}
