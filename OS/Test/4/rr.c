#include <stdio.h>

int main() {

    int n,tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], wt[n], tat[n];

    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time & Burst Time of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        // !
        rt[i] = bt[i];
        wt[i] = tat[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int completed = 0; // no of process completed
    int time = 0; // current cpu time

    while(completed < n){
        // int found = 0;
        for(int i=0; i<n; i++){

            if(at[i]<=time && rt[i]>0){
                // found = 1;
                if (rt[i] > tq){
                    time += tq;
                    rt[i] -= tq;
                }else{
                    time +=rt[i];
                    rt[i] = 0;
                    completed++;

                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        // if(!found)
        //     time++;

    }

    float avgWT = 0, avgTAT = 0;
    printf("\nP\tAT\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}