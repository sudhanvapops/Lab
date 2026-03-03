#include<stdio.h>

int main(){


    int n,temp;
    
    printf("Enter No of Process: ");
    scanf("%d",&n);

    int bt[n],tat[n],wt[n],p[n];
    wt[0] = 0;

    // Burst Time
    for(int i=0;i<n;i++){
        printf("Enter Burst time for Process P%d: ",i+1);
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }

    // Sort according to bt
    for(int i=0;i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(bt[i]>bt[j]){

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // sort pids
                temp = p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }


    // calculate wt
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    float avgtat=0,avgwt=0;

    // caluclate tat
    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
        avgtat += tat[i];
        avgwt += wt[i];
    }

    // print avg and times

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat/n);

    
    return 0;
}