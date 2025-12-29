#include<stdio.h>
#define MAX 10

int n,m;
int avail[MAX],safeSeq[MAX],finish[MAX];
int need[MAX][MAX], alloc[MAX][MAX], max[MAX][MAX];

void readMatrix(int matrix[MAX][MAX],char *matrixType){
    printf("Enter Values for %s Matrix: ",matrixType);
    for (int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void readAvailable(int available[MAX]){
    printf("Enter the Value for Resourse Available: ");
    for(int i=0;i<m;i++)
        scanf("%d",&available[i]);
}

void calaculateNeed(){
    for (int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

int isSafe(){

    int work[MAX],count=0;

    for(int i=0;i<m;i++)
        work[i] = avail[i];

    for(int i=0;i<n;i++)
        finish[i] = 0;
    
    while (count < n) {

        int found = 0;

        for (int i = 0; i < n; i++) {
            if(!finish[i]){

                // eleigible for execution now
                int j;
                for(j=0;j<m;j++){
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m){ // free the resource
                    for(int k=0; k<m; k++){
                        work[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }

            }
        }
        
        if(!found)
            return 0;
    }
    return 1;

}

int main(){

    printf("Enter Number of Process: ");
    scanf("%d",&n);

    printf("Enter Number of Resouces: ");
    scanf("%d",&m);

    readMatrix(alloc,"Allocation");
    readMatrix(max,"Maximum");
    readAvailable(avail);

    calaculateNeed();

    int res = isSafe();
    if(res) { // 1
        printf("The System is Safe\nThe Safe Sequence is: ");
        for(int i=0; i<n;i++){
            printf(i != n-1 ? "P%d -> ": "P%d", safeSeq[i]);
        }
    }else { // 0
        printf("\nThe System is Unsafe Possible Deadlock");
    }

    return 0;
}