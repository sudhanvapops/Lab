// 2.4 Develop a c program to implement Simulate CPU scheduling algorithms to find turnaround time and waiting time using Priority

// Enter number of processes: 3
// Enter Burst Time & Priority for P1: 5 2
// Enter Burst Time & Priority for P2: 3 1
// Enter Burst Time & Priority for P3: 8 3

// PID     BT      PR      WT      TAT
// P2      3       1       0       3
// P1      5       2       3       8
// P3      8       3       8       16

// Avg WT=3.67     Avg TAT=9.00

#include <stdio.h>

typedef struct {
    int pid, bt, pr, wt, tat;
} Process;


int main() {
    int n; float avgWT = 0, avgTAT = 0;
    Process p[10],t;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time & Priority for P%d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].pr);
    }

    // Sort by priority (ascending)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i].pr > p[j].pr) { 
                t = p[i]; 
                p[i] = p[j]; 
                p[j] = t; 
            }

    // Calculate WT & TAT
    p[0].wt = 0; 
    p[0].tat = p[0].bt;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
        avgWT += p[i].wt; avgTAT += p[i].tat;
    }

    printf("\nAvg WT=%.2f\tAvg TAT=%.2f\n", avgWT / n, avgTAT / n);
}