// ## PROGRAM - 01 
 
// Develop a Program in C for the following: 

// b)  Write  functions  create(),  read()  and  display();  to  create  the  calendar,  to  read  the  data 
// from the keyboard and to print weeks activity details report on screen.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DAYS 7
#define FILENAME "calendar.txt"

// Structure to store a day's info
typedef struct Day {
    char name[10];
    int date;
    char activity[100];
} Day;


// Function to initialize day names
void initDays(Day calendar[DAYS], const char *names[]) {
    for (int i = 0; i < DAYS; i++)
        strcpy(calendar[i].name, names[i]);
}


// Function to input calendar data and save to file
void create(Day calendar[DAYS]) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) return printf("Error creating file.\n"), (void)0;

    for (int i = 0; i < DAYS; i++) {
        printf("\nEnter Date & Activity for %s: ", calendar[i].name);
        scanf("%d %[^\n]", &calendar[i].date, calendar[i].activity);
        fprintf(file, "%d\n%s\n", calendar[i].date, calendar[i].activity);
    }

    fclose(file);
    printf("\nCalendar saved to 'calendar.txt'\n");
}

// Function to read data from file
void read( Day calendar[DAYS]) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return printf("No calendar file found.\n"), (void)0;

    for (int i = 0; i < DAYS; i++) {
        fscanf(file, "%d", &calendar[i].date);
        fscanf(file, " %[^\n]", calendar[i].activity);
    }
    fclose(file);
    printf("\nCalendar loaded from 'calendar.txt'\n");
}

// Function to display the calendar
void display( Day calendar[DAYS]) {
    printf("\n------ Weekly Calendar ------\n");
    for (int i = 0; i < DAYS; i++)
        printf("%-10s | %2d | %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    printf("-----------------------------------\n");    
}

int main() {
    struct Day calendar[DAYS];
    const char *dayNames[DAYS] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    initDays(calendar, dayNames);

    printf("1. Create Calendar\n2. Read Calendar\n3. Display Calender\n4. Exit\n");
    
    while (1){
        printf("Choose: ");
        int choice; scanf("%d", &choice);
        switch (choice) {
        case 1:
            create(calendar);
            break;
        case 2:
            read(calendar);
            break;
        case 3:
            display(calendar);
            break;
        case 4:
            printf("Exit...\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}


// ### OUTPUT

// 1. Create Calendar
// 2. Read Calendar
// 3. Display Calender
// 4. Exit
// Choose: 1

// Enter Date & Activity for Monday: 1 Read
// Enter Date & Activity for Tuesday: 2 Sleep
// Enter Date & Activity for Wednesday: 3 Get up
// Enter Date & Activity for Thursday: 4 GYM
// Enter Date & Activity for Friday: 5 work
// Enter Date & Activity for Saturday: 6 Nothing
// Enter Date & Activity for Sunday: 7 Rest

// Calendar saved to 'calendar.txt'
// Choose: 2

// Calendar loaded from 'calendar.txt'
// Choose: 3

// ------ Weekly Calendar ------
// Monday     |  1 | Read
// Tuesday    |  2 | Sleep
// Wednesday  |  3 | Get up
// Thursday   |  4 | GYM
// Friday     |  5 | work
// Saturday   |  6 | Nothing
// Sunday     |  7 | Rest
// -----------------------------------
// Choose: 4
// Exit...