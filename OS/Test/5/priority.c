#include <stdio.h>


typedef struct {
    int pid, wt, bt, tat, pr;
} Process;

int main(){

    int n; float avgWT = 0, avgTAT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n],temp;

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time & Priority for P%d: ", i + 1);
        scanf("%d %d",&p[i].bt,&p[i].pr);
        p[i].pid = i+1;
    }

    // Sort by priority (ascending)
    for (int i=0; i<n-1; i++){
        for(int j =0; j<n-i-1;j++){
            
            if(p[j].pr > p[j+1].pr){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // Calculate WT & TAT
    p[0].wt = 0;
    p[0].tat = p[0].bt; 
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

     printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
        avgWT += p[i].wt; avgTAT += p[i].tat;
    }

    printf("\nAvg WT=%.2f\tAvg TAT=%.2f\n", avgWT / n, avgTAT / n);
    
    return 0;
}