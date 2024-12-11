#include<stdio.h>
struct file {
    int all[10];
    int max[10];
    int need[10];
    int flag;
};
int main() {
    struct file f[10];
    int fl = 0;
    int i, j, k, p, b, n, r, g, cnt = 0, id, newr;
    int avail[10], seq[10];
    
    printf("Enter number of processes -- ");
    scanf("%d", &n);
    printf("Enter number of resources -- ");
    scanf("%d", &r);

    for(i = 0; i < n; i++) {
        printf("\nEnter detail for P%d", i);
        printf("\nEnter allocation\t -- \t");
        for(j = 0; j < r; j++) {
            scanf("%d", &f[i].all[j]);
        }
        printf("\nEnter max \t\t -- \t");
        for(j = 0; j < r; j++) {
            scanf("%d", &f[i].max[j]);
        }
        f[i].flag = 0;
    }
    printf("\nEnter available resources \t -- \t");
    for(i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }
    printf("\nEnter new request detail - ");
    printf("\nEnter pid \t -- \t");
    scanf("%d", &id);
    printf("\nEnter request for resource \t -- \t");
    for(i = 0; i < r; i++) {
        scanf("%d", &newr);
        f[id].all[i] += newr;
        avail[i] -= newr;
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            f[i].need[j] = f[i].max[j] - f[i].all[j];
            if(f[i].need[j] < 0) {
                f[i].need[j] = 0;
            }
        }
    }

    cnt = 0;
    while(cnt != n) {
        g = 0;
        for(j = 0; j < n; j++) {
            if(f[j].flag == 0) {
                b = 0;
                for(p = 0; p < r; p++) {
                    if(avail[p] >= f[j].need[p]) {
                        b++;
                    }
                }
                if(b == r) {
                    printf("\nP%d is visited", j);
                    seq[fl++] = j;
                    f[j].flag = 1;
                    for(k = 0; k < r; k++) {
                        avail[k] += f[j].all[k];
                    }
                    cnt++;
                    printf("(");
                    for(k = 0; k < r; k++) {
                        printf("%d ", avail[k]);
                    }
                    printf(")");
                    g = 1;
                }
            }
        }
        if(g == 0) {
            printf("\nREQUEST NOT GRANTED -- DEADLOCK OCCURRED");
            printf("\nSYSTEM IS IN UNSAFE STATE");
            goto end;
        }
    }
    printf("\nSystem is in safe state");
    printf("\nThe safe Sequence is -- (");
    for(i = 0; i < fl; i++) {
        printf("P%d ", seq[i]);
    }
    printf(")");
end:

    printf("\n\nProcess\t\tAllocation\t\tMax\t\tNeed\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t", i);
        for(j = 0; j < r; j++) {
            printf("%6d ", f[i].all[j]);
        }
        for(j = 0; j < r; j++) {
            printf("%6d ", f[i].max[j]);
        }
        for(j = 0; j < r; j++) {
            printf("%6d ", f[i].need[j]);
        }
        printf("\n");
    }
    return 0;
}