#include <stdio.h>

int main() {
    int base[10], limit[10];
    int n, i, seg, offset;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    // Input base and limit
    for(i = 0; i < n; i++) {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d %d", &base[i], &limit[i]);
    }

    // Input logical address
    printf("Enter segment number: ");
    scanf("%d", &seg);

    printf("Enter offset: ");
    scanf("%d", &offset);

    // Check validity
    if(seg >= n || offset >= limit[seg]) {
        printf("Invalid Address\n");
        
    } else {
        int physical = base[seg] + offset;
        printf("Physical Address = %d\n", physical);
    }

    return 0;
}
