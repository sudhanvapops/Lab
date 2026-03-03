#include<stdio.h>

int main(){

    int n;
    float avgWt=0,avgTat=0;

    printf("Enter No of process: ");
    scanf("%d",&n);
    int bt[n],tat[n],wt[n];

    // BT Input
    for(int i=0; i<n; i++){
        printf("Enter BT for P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    // WT Calculate
    for (int i=1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    // TAT Calculate
    for (int i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
        avgTat += tat[i];
        avgWt += wt[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTat/n);

    return 0;
}