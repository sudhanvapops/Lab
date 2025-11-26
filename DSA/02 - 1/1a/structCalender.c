#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a day
struct Day {
    char *name;      // Dynamically allocated string
    int  date;
    char *activity;  // Dynamically allocated string
};

int main() {
    // Dynamically create array of 7 elements
    struct Day *calendar = (struct Day *)malloc(7 * sizeof(struct Day));

    // Initialize with sample data using dynamic strings
    char *defaultNames[7] = {
        "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "Sunday"
    };

    char *defaultActivities[7] = {
        "Work from 9 AM to 5 PM",
        "Meeting at 10 AM",
        "Gym at 6 PM",
        "Dinner with friends at 7 PM",
        "Movie night at 8 PM",
        "Weekend getaway",
        "Relax and recharge"
    };

    for (int i = 0; i < 7; i++) {
        calendar[i].name = (char *)malloc(strlen(defaultNames[i]) + 1);
        strcpy(calendar[i].name, defaultNames[i]);

        calendar[i].activity = (char *)malloc(strlen(defaultActivities[i]) + 1);
        strcpy(calendar[i].activity, defaultActivities[i]);

        calendar[i].date = i + 1; // Just assigning 1 to 7
    }

    // Display
    printf("====================================\n");
    printf("        Calendar for the Week       \n");
    printf("====================================\n");

    for (int i = 0; i < 7; i++) {
        printf("%-10s (Date: %2d): %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    }

    printf("====================================\n");

    return 0;
}
