#include <stdio.h>
#define MAX_SEG 10
void main() {
    int ns, la, sn, off, pa;
    int base[MAX_SEG], limit[MAX_SEG];
    int i;

    printf("Enter the number of segments : ");
    scanf("%d", &ns);

    for (i = 0; i < ns; i++) {
        printf("\nEnter base address and limit for segment %d : ", i);
        scanf("%d %d", &base[i], &limit[i]);
    }

    printf("\nEnter logical address to find physical address\n");
    printf("\nEnter segment number and offset : ");
    scanf("%d %d", &sn, &off);

    if (sn >= ns || off >= limit[sn]) {
        printf("\nInvalid Segment Number or Offset\n");
    } else {
        pa = base[sn] + off;
        printf("\nPhysical Address : %d", pa);
    }
}