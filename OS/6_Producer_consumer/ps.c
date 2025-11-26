// Develop a C program to simulate the Producer-Consumer problem using semaphores.

#include <stdio.h>

int mutex = 1, full = 0, empty = 3, x = 0;

void wait(int *s) { (*s)--; }
void signal(int *s) { (*s)++; }

void producer() {
    wait(&mutex); wait(&empty);
    printf("\nProducer produces item %d", ++x);
    signal(&full); signal(&mutex);
}

void consumer() {
    wait(&mutex); wait(&full);
    printf("\nConsumer consumes item %d", x--);
    signal(&empty); signal(&mutex);
}

int main() {
    int ch;
    printf("1. Produce  2. Consume  3. Exit");
    while (1) {
        printf("\n\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1) (mutex && empty) ? producer() : printf("\nBuffer full!");
        else if (ch == 2) (mutex && full) ? consumer() : printf("\nBuffer empty!");
        else if (ch == 3) break;
        else printf("\nInvalid!");
    }
}


// SAMPLE INPUT/OUTPUT
// 1. Producer
// 2. Consumer
// 3. Exit

// Enter your choice: 1
// Producer produces item 1

// Enter your choice: 1
// Producer produces item 2

// Enter your choice: 2
// Consumer consumes item 2

// Enter your choice: 2
// Consumer consumes item 1
