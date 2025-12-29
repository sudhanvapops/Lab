// Develop a C program to simulate the Producer-Consumer problem using semaphores.

// The Producer-Consumer problem models this situation:

// A Producer creates items and puts them into a buffer
// A Consumer removes items from the buffer
// Rules:
// Producer must not produce if buffer is full
// Consumer must not consume if buffer is empty
// Only one process at a time can access the buffer (mutual exclusion)



#include <stdio.h>

int mutex = 1; // Binary semaphore meaning only one process to enter critical section

int full = 0, empty = 3; // These are counting semaphores.
int x = 0; // shared buffer/ resource

void wait(int *s) { (*s)--; } // request resource // Decrement semaphore
void signal(int *s) { (*s)++; } // release resource // Increment semaphore


// What this means conceptually:
// Lock buffer (mutex)
// Check space exists (empty)
// Produce item
// Increase count of full slots
// Unlock buffer
void producer() {
    wait(&mutex); // locks the critical section no other producer/consumer can enter CS
    wait(&empty); // check if there is empty space 
    // producer cant produce if empty == 0

    printf("\nProducer produces item %d", ++x); // ++x produces an item
    signal(&full); // increaes number of filled slot
    signal(&mutex); // release mutes
}

// Lock buffer
// Check item exists
// Consume item
// Increase empty slots
// Unlock buffer
void consumer() {
    wait(&mutex); 
    wait(&full);
    printf("\nConsumer consumes item %d", x--);
    signal(&empty); 
    signal(&mutex);
}

int main() {
    int ch;
    printf("1. Produce  2. Consume  3. Exit");
    while (1) {

        printf("\n\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 1) 
            (mutex && empty) ? producer() : printf("\nBuffer full!");
        else if (ch == 2) 
            (mutex && full) ? consumer() : printf("\nBuffer empty!");
        else if (ch == 3) 
            break;
        else 
            printf("\nInvalid!");
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
