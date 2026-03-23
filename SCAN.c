#include <stdio.h>

int main() {
    int req[50], n, i, j, head, size, seek = 0, temp;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // Sort requests (ascending)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(req[j] > req[j + 1]) {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int pos;
    // Find head position in sorted array
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            pos = i;
            break;
        }
    }

    // Move RIGHT first
    for(i = pos; i < n; i++) {
        seek += (req[i] - head);
        head = req[i];
    }

    // Go to end of disk
    seek += (size - 1 - head);
    head = size - 1;

    // Then move LEFT
    for(i = pos - 1; i >= 0; i--) {
        seek += (head - req[i]);
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}
