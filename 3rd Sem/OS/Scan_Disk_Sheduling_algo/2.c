#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[25], n, head, size, move;
    int i, j, temp, total = 0, pos;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size (number of tracks): ");
    scanf("%d", &size);

    printf("Enter head movement direction (1=high end, 0=low end): ");
    scanf("%d", &move);

    /* Add head to request queue */
    queue[n++] = head;

    /* Sort the request queue */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }

    /* Find head position */
    for (i = 0; i < n; i++)
        if (queue[i] == head) {
            pos = i;
            break;
        }

    printf("\nDisk Sequence: %d", head);

    /* SCAN towards higher end */
    if (move == 1) {

        for (i = pos + 1; i < n; i++) {
            total += abs(queue[i] - head);
            head = queue[i];
            printf(" -> %d", head);
        }

        /* Move to last track */
        total += abs((size - 1) - head);
        head = size - 1;
        printf(" -> %d", head);

        /* Reverse direction */
        for (i = pos - 1; i >= 0; i--) {
            total += abs(queue[i] - head);
            head = queue[i];
            printf(" -> %d", head);
        }
    }

    /* SCAN towards lower end */
    else {

        for (i = pos - 1; i >= 0; i--) {
            total += abs(queue[i] - head);
            head = queue[i];
            printf(" -> %d", head);
        }

        /* Move to first track */
        total += abs(head - 0);
        head = 0;
        printf(" -> %d", head);

        /* Reverse direction */
        for (i = pos + 1; i < n; i++) {
            total += abs(queue[i] - head);
            head = queue[i];
            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal Head Movement = %d\n", total);

    return 0;
}
