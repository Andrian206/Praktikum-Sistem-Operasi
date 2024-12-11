#include<stdio.h>

struct file {
    int alloc[10];
    int max[10];
    int nd[10];
    int cpl;
};

int main() {
    struct file proc[3];
    int avail[10], wk[10], fin[3] = {0};
    int i, j, k, n = 3, r, flag, dl = 0;

    printf("Masukan Banyak Resource Type : ");
    scanf("%d", &r);

    for (i = 0; i < n; i++) {
        printf("\nMasukan Aloccation dari Proses P%d : ", i);
        for (j = 0; j < r; j++) {
            scanf("%d", &proc[i].alloc[j]);
        }
        printf("Masukan Max dari Proses P%d : ", i);
        for (j = 0; j < r; j++) {
            scanf("%d", &proc[i].max[j]);
        }
        proc[i].cpl = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            proc[i].nd[j] = proc[i].max[j] - proc[i].alloc[j];
        }
    }

    printf("\nMasukan resource yang tersedia : ");
    for (i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    for (i = 0; i < r; i++) {
        wk[i] = avail[i];
    }

    printf("\nMengecek Deadlock..\n");

    for (k = 0; k < n; k++) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (!fin[i]) {
                int c_alloc = 1;
                for (j = 0; j < r; j++) {
                    if (proc[i].nd[j] > wk[j]) {
                        c_alloc = 0;
                        break;
                    }
                }
                if (c_alloc) {
                    for (j = 0; j < r; j++) {
                        wk[j] += proc[i].alloc[j];
                    }
                    fin[i] = 1;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag) {
            dl = 1;
            break;
        }
    }

    if (dl) {
        printf("\nDeadlock Terdeteksi!\n");
        for (i = 0; i < n; i++) {
            if (!fin[i]) {
                printf("P%d ", i);
            }
        }
    } else {
        printf("\nSistem dalam keadaan Safe State.\n");
    }

    return 0;
}
