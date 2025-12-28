#include<stdio.h>

int main(){

    int n;
    
    float avg_wt = 0, avg_tat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    int p[n], temp=0;

    printf("Enter burst times for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;   // process IDs
    }

    
    // Sort By Burst Time
    for(int i=0; i<n-1; i++){
        for(int j = 0; j<n-i-1;j++){
            if(bt[j] > bt[j+1]){
                // swap burst times
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                // swap process IDs
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // Calc WT
    wt[0] = 0;
    for(int i=1; i<n; i++){
        wt[i] = wt[i-1]+bt[i-1];
    }

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}