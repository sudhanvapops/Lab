// Process | Turnaround Time | Waiting Time
// P2      |     1           |     0
// P1      |     4           |     0
// P3      |     6           |     0

// Average Waiting Time = 0.00
// Average Turnaround Time = 3.67

// Gantt Chart:
// -----------------
// |  P2  |  P1  |  P3  |
// -----------------
// 0      4      16     29


#include <stdio.h>

int main() {
    
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], wt[n], tat[n];

    // Input
    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time & Burst Time of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        wt[i] = tat[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    // Round Robin Loop
    while(completed < n) {

        for(int i = 0; i < n; i++) {

            // process has arrived + still running
            if(at[i] <= time && rt[i] > 0) {

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;

                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }
    }

    // Output
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
