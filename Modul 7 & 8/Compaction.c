#include <stdio.h>
#define Max 25

void main() {
    int mmr[Max], altd[Max], tb, i, ci = 0, tfs = 0;

    printf("\n\tMemory Compaction Program\n");

    printf("\nMasukan Jumlah Blok Memori : ");
    scanf("%d", &tb);

    printf("\nMasukan Ukuran Blok Memori :\n");
    for (i = 0; i < tb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &mmr[i]);
    }

    for (i = 0; i < tb; i++) {
        altd[i] = 0;
    }

    for (i = 0; i < tb; i++) {
        if (mmr[i] > 0) { 
            altd[ci] = mmr[i];
            ci++;
        } else {
            tfs += -mmr[i];
        }
    }

    altd[ci] = -tfs;
    printf("Block No\tBlock Size\n");
    for (i = 0; i <= ci; i++) {
        printf("%d\t\t%d\n", i + 1, altd[i]);
    }
}