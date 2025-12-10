#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define CYLINDERS 200

void sort(int arr[], int n, int asc) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (asc ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void scan(int req[], int n, int head, char dir[]) {
    int distance = 0;

    printf("\nSCAN Disk Scheduling\nHead Movement: %d -> ", head);

    sort(req, n, 1);

    int split = 0;
    while (split < n && req[split] < head) split++;

    if (dir[0] == 'l') {        // LEFT direction

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

    } else {                  // RIGHT direction

        for (int i = split; i < n; i++) {
            printf("%d -> ", req[i]);
            distance += abs(head - req[i]);
            head = req[i];
        }

        printf("%d -> ", CYLINDERS - 1);
        distance += abs((CYLINDERS - 1) - head);
        head = CYLINDERS - 1;

        for (int i = split - 1; i >= 0; i--) {
            printf("%d -> ", req[i]);
            distance += abs(head - req[i]);
            head = req[i];
        }
    }

    printf("\nTotal Head Movement = %d cylinders\n", distance);
}

int main() {
    int n, head, req[MAX_REQUESTS];
    char direction[10];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter direction (left/right): ");
    scanf("%s", direction);

    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);

    scan(req, n, head, direction);

    return 0;
}


// ! Input 
// 5
// 3
// right
// 176 79 34 60 92

// ! Output
// SCAN Disk Scheduling
// Head Movement: 3 -> 34 -> 60 -> 79 -> 92 -> 176 -> 199 ->
// Total Head Movement = 196 cylinders