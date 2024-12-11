#include <stdio.h>

int main() {
    int alloc[5] = {1, 0, 1, 0, 0};
    int req[5] = {0, 1, 0, 1, 0};
    int avail = 1;
    int i, dl = 1;

    printf("Process\tAllocation\tRequest\n");
    for (i = 0; i < 5; i++) {
        printf("P%d\t\t%d\t\t%d\n", i, alloc[i], req[i]);
        if (req[i] <= avail) {
            avail += alloc[i];
            dl = 0;
        } else {
            printf("Waiting P%d Process.\n", i);
        }
    }

    if (dl)
        printf("\nDeadlock!\n");
    else
        printf("\nSafe State.\n");
    
    return 0;
}
