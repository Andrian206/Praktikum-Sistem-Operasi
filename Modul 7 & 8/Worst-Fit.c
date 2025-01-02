#include <stdio.h>
#include <conio.h>
#define Max 25
void main(){
    int Frag[Max], B[Max], F[Max], i, j, NB, NF, temp, highest = 0;
    static int BF[Max], FF[Max];
    printf("\n\tMemory Management Scheme - Worst Fit");

    printf("\nEnter The Number of Blocks : ");
    scanf("%d", &NB);

    printf("\nEnter The Number of Files : ");
    scanf("%d", &NF);

    printf("\nEnter The Size of The Blocks : -\n");
    for(i = 1; i <= NB; i++){
        printf("Block %d : ", i);
        scanf("%d", &B[i]);
    }

    printf("\nEnter The Size of The Files : -\n");
    for(i = 1; i <= NF; i++) {
        printf("File %d : ", i);
        scanf("%d", &F[i]);
    }

    for(i = 1; i <= NF; i++){
        for(j = 1; j <= NB; j++){
            if (BF[j] != 1){ 
                temp = B[j] - F[i]; 
                if (temp >= 0 && highest < temp){ 
                    FF[i] = j; 
                    highest = temp;
                }
            }
        }
        Frag[i] = highest; 
        BF[FF[i]] = 1; 
        highest = 0; 
    }

    printf("\nFileNo \tFileSize \tBlockNO \tBlockSize \tFragment");
    for(i = 1; i <= NF & FF[i] !=0 ; i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, F[i], FF[i], B[FF[i]], Frag[i]);
    }
    getch();
}