



#include <stdio.h>

int main() {
    int pages[10] = {1,2,3,4,1,2,5};
    int frames[3] = {-1,-1,-1};
    int faults = 0, i, j, found;

    for(i = 0; i < 7; i++) {
        found = 0;

        // check if page present
        for(j = 0; j < 3; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // page fault
        if(found == 0) {
            frames[i % 3] = pages[i];
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);

    return 0;
}
