#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void sort(int arr[], int n, int asc) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (asc ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void scan(int req[], int n, int head, int diskSize, int dir) {
    int distance = 0;

    printf("\nSCAN Disk Scheduling\nHead Movement: %d -> ", head);

    sort(req, n, 1);

    int split = 0;
    while (split < n && req[split] < head)
        split++;

    if (dir == 0) {   // Low End / LEFT direction

        for (int i = split - 1; i >= 0; i--) {
            printf("%d -> ", req[i]);
            distance += abs(head - req[i]);
            head = req[i];
        }

        printf("0 -> ");
        distance += head;
        head = 0;

        for (int i = split; i < n; i++) {
            printf("%d -> ", req[i]);
            distance += abs(head - req[i]);
            head = req[i];
        }

    } else {               // High End / RIGHT direction

        for (int i = split; i < n; i++) {
            printf("%d -> ", req[i]);
            distance += abs(head - req[i]);
            head = req[i];
        }

        printf("%d -> ", diskSize - 1);
        distance += abs((diskSize - 1) - head);
        head = diskSize - 1;

        for (int i = split - 1; i >= 0; i--) {
            printf("%d -> ", req[i]);
            distance += abs(head - req[i]);
            head = req[i];
        }
    }

    printf("\nTotal Head Movement = %d cylinders\n", distance);
}

int main() {
    int n, head, diskSize;
    int req[MAX_REQUESTS];
    int direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter disk size (number of tracks): ");
    scanf("%d", &diskSize);

    printf("Enter direction (1: High end, 0: Low end): ");
    scanf(" %d", &direction);

    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    scan(req, n, head, diskSize, direction);

    return 0;
}


// ! Output
// Enter number of requests: 7
// Enter head position: 50
// Enter disk size (number of tracks): 200
// Enter direction (1: High end, 0: Low end): 1
// Enter request queue:
// 82 170 43 140 24 16 190

// SCAN Disk Scheduling
// Head Movement: 50 -> 82 -> 140 -> 170 -> 190 -> 199 -> 43 -> 24 -> 16 -> 
// Total Head Movement = 332 cylinders


// Enter number of requests: 5 
// Enter head position: 3 
// Enter disk size (number of tracks): 200 
// Enter direction (1: High end, 0: Low end): 0 
// Enter request queue: 176 79 34 60 92 

// SCAN Disk Scheduling Head Movement: 3 -> 0 -> 34 -> 60 -> 79 -> 92 -> 176 -> 
// Total Head Movement = 179 cylinders