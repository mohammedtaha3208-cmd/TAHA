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

    // Sort requests
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
    // Find position of head
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            pos = i;
            break;
        }
    }

    // Move RIGHT
    for(i = pos; i < n; i++) {
        seek += (req[i] - head);
        head = req[i];
    }

    // Go to end
    seek += (size - 1 - head);
    head = size - 1;

    // Jump to beginning (0)
    seek += (size - 1);
    head = 0;

    // Continue RIGHT again
    for(i = 0; i < pos; i++) {
        seek += (req[i] - head);
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}
