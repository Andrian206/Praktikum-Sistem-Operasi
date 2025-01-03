#include <stdio.h>
#define MAX_OP 10
#define MAX_IP 20
void main() {
    int ps, la, opc, ipc, rp, pa;
    int op, ip, off;
    int fn[MAX_OP][MAX_IP];
    int i, j;

    printf("Enter the page size (in bytes) : ");
    scanf("%d", &ps);

    printf("Enter the number of outer pages : ");
    scanf("%d", &opc);

    printf("Enter the number of inner pages per outer page : ");
    scanf("%d", &ipc);

    rp = opc * ipc;

    for (i = 0; i < opc; i++) {
        printf("\nEnter frame numbers for outer page %d : ", i);
        for (j = 0; j < ipc; j++) {
            scanf("%d", &fn[i][j]);
        }
    }

    printf("\nEnter logical address to find physical address\n");
    printf("\nEnter outer page, inner page, and offset : ");
    scanf("%d %d %d", &op, &ip, &off);

    if (op >= opc || ip >= ipc || off >= ps) {
        printf("\nInvalid Outer Page, Inner Page or Offset");
    } else {
        pa = (fn[op][ip] * ps) + off;
        printf("\nPhysical Address : %d", pa);
    }
}