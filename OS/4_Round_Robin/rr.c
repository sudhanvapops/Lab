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

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time & Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    while (completed < n) {

        int idle = 1;  // assume CPU idle

        for (int i = 0; i < n; i++) {

            // If process has arrived and not finished
            if (at[i] <= time && rt[i] > 0) {

                idle = 0;  // CPU did work

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } 
                else {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;

                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        // If no process ran → CPU idle
        if (idle)
            time++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    float sumWT = 0, sumTAT = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
        sumWT += wt[i];
        sumTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", sumWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", sumTAT / n);

    return 0;
}
