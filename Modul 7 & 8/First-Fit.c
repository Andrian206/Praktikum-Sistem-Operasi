#include <stdio.h>
#include <conio.h>
#define Max 25
void main(){
    int Frag[Max], B[Max], F[Max], i, j, NB, NF, temp;
    static int BF[Max], FF[Max];
    printf("\n\tMemory Management Scheme - First Fit");

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
                if (temp >= 0){ 
                    FF[i] = j;
                    break;
                }
            }
        }
        Frag[i] = temp; 
        BF[FF[i]] = 1; 
    }

    printf("\nFileNo \tFileSize \tBlockNO \tBlockSize \tFragment");
    for(i = 1; i <= NF; i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, F[i], FF[i], B[FF[i]], Frag[i]);
    }
    getch();
}