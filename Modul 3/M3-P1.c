#include<stdio.h>
#include<conio.h>

int main(){
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("\nEnter Burst Time for Processes %d -- ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];

    for(i = 1; i < n; i++){
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++){
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", i, bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time -- %f", wtavg/n);
    printf("\n\nAverage Turnaround Time -- %f", tatavg/n);

    getch();
    return 0;
}