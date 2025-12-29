#include <stdio.h>
#include <stdlib.h>

int mutex=1;
int full=0, empty=3;
int x = 0;


int wait(int *s) {(*s)--;}
int signal(int *s) {(*s)++;}

void producer(){
    wait(&mutex);
    wait(&empty);
    // produce item
    printf("Producer produces item %d\n", ++x);
    signal(&full);
    signal(&mutex);
}

void consumer(){
    wait(&mutex);
    wait(&full);
    //consume item
    printf("Consumer Consumes item %d\n", x--);
    signal(&empty);
    signal(&mutex);
}

int main(){
    int ch;
    printf("1.Produce\n2.Consume\n3.exit\n");

    while (1) {

        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch (ch){
            case 1:
                (mutex && empty) ? producer() : printf("Buffer full!\n") ;
                break;
            case 2:
                (mutex && full) ? consumer() : printf("Buffer empty\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    
    return 0;
}