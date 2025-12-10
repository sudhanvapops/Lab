#include <stdio.h>
#include <string.h>

#define DAYS 7
#define FILENAME "calendar.txt"

// Structure to store a day's info
struct Day {
    char name[10];
    int date;
    char activity[100];
};


// Function to initialize day names
void initDays(struct Day calendar[DAYS], const char *names[]) {
    for (int i = 0; i < DAYS; i++)
        strcpy(calendar[i].name, names[i]);
}


// Function to input calendar data and save to file
void create(struct Day calendar[DAYS]) {
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
void read(struct Day calendar[DAYS]) {
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
void display(struct Day calendar[DAYS]) {
    printf("\n------ Weekly Calendar ------\n");
    for (int i = 0; i < DAYS; i++)
        printf("%-10s | %2d | %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    printf("-----------------------------------\n");    
}

int main() {
    struct Day calendar[DAYS];
    const char *dayNames[DAYS] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    
    initDays(calendar, dayNames);

    printf("1. Create Calendar\n2. Read Calendar\nChoose: ");
    int choice; scanf("%d", &choice);

    (choice == 1) ? create(calendar) : read(calendar);

    display(calendar);
    return 0;
}
