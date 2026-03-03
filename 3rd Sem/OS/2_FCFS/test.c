#include <stdio.h>


int main(){
    
    int np;
    float avg_wt =0 ,avg_tat=0;

    printf("Enter Number of Process: ");
    scanf("%d",&np);

    int wt[np],bt[np],tat[np];
    wt[0] = 0;

    printf("Enter burst time: ");
    for(int i=0; i<np;i++){
        printf("P%d: ", i+1);
        scanf("%d",(bt+i));
    }

    for(int i = 1; i < np; i++) {
        wt[i] = wt[i-1]+bt[i-1];
    }

     for(int i = 0; i < np; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < np; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/np);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/np);
    
    return 0;
}