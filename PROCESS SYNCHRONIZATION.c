
#include <stdio.h>

int mutex = 1;

void wait() {
    mutex--;
}

void signal() {
    mutex++;
}

int main() {
    if(mutex == 1) {
        wait();
        printf("Process in Critical Section\n");
        signal();
    } else {
        printf("Waiting...\n");
    }
    return 0;
}
