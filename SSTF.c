#include <stdio.h>

int main() {
    int req[50], visited[50];
    int n, i, count = 0;
    int head, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;   // mark all unvisited
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // SSTF Logic
    while(count < n) {
        int min = 9999, index = -1;

        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                int diff = req[i] - head;
                if(diff < 0) diff = -diff;

                if(diff < min) {
                    min = diff;
                    index = i;
                }
            }
        }

        // move head to closest request
        seek += min;
        head = req[index];
        visited[index] = 1;
        count++;
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}
