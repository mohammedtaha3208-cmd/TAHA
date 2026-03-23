#include <stdio.h>

int main() {
    int req[50], n, i;
    int head, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // FCFS Logic
    for(i = 0; i < n; i++) {
        int diff = req[i] - head;

        if(diff < 0)
            diff = -diff;   // absolute value

        seek += diff;
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}
