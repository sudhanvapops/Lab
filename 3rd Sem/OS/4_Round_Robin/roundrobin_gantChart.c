#include <stdio.h>

int main() {
    int n, i, time = 0, remain, time_quantum;
    int at[10], bt[10], rt[10];
    int wait_time = 0, turnaround_time = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\n\nProcess\t| Turnaround Time | Waiting Time\n");

    int complete[n];
    for (i = 0; i < n; i++) complete[i] = 0;

    // For Gantt Chart
    int gantt_process[100], gantt_start[100], gantt_end[100];
    int gantt_index = 0;

    while (remain > 0) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                found = 1;

                // Record Gantt start
                gantt_process[gantt_index] = i + 1;
                gantt_start[gantt_index] = time;

                if (rt[i] <= time_quantum) {
                    time += rt[i];
                    rt[i] = 0;
                    remain--;

                    // Record Gantt end
                    gantt_end[gantt_index] = time;
                    gantt_index++;

                    printf("P%d\t| \t%d\t    | \t%d\n", i + 1, time - at[i], time - at[i] - bt[i]);
                    wait_time += time - at[i] - bt[i];
                    turnaround_time += time - at[i];
                } else {
                    rt[i] -= time_quantum;
                    time += time_quantum;

                    // Record Gantt end
                    gantt_end[gantt_index] = time;
                    gantt_index++;
                }
            }
        }
        if (!found) time++; // CPU idle until next process arrives
    }

    printf("\nAverage Waiting Time = %.2f", (float)wait_time / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)turnaround_time / n);

    // Gantt Chart Printing
    printf("\nGantt Chart:\n");

    // Top line
    for (i = 0; i < gantt_index; i++) {
        printf("--------");
    }
    printf("-\n|");

    // Process names
    for (i = 0; i < gantt_index; i++) {
        printf("  P%d  |", gantt_process[i]);
    }
    printf("\n");

    // Bottom line
    for (i = 0; i < gantt_index; i++) {
        printf("--------");
    }
    printf("-\n");

    // Time markings
    printf("0");
    for (i = 0; i < gantt_index; i++) {
        printf("      %d", gantt_end[i]);
    }
    printf("\n");

    return 0;
}
