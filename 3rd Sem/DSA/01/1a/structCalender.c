// ## PROGRAM - 01 
 
// Develop a Program in C for the following: 

// a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent 7 days of a week. 
// Each Element of the array is a structure having three fields. 
// The first field is the name of the Day (A dynamically allocated String), 
//  the second field is the date of the Day (A integer), 
// the third field is the description of the activity for a particular day (A dynamically allocated String). 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a day
typedef struct Day {
    char *name;      // Dynamically allocated string
    int  date;
    char *activity;  // Dynamically allocated string
} DAY;

int main() {
    // Dynamically create array of 7 elements
    DAY *calendar = (DAY *)malloc(7 * sizeof(DAY));

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

// ### Output
// ====================================
//         Calendar for the Week       
// ====================================
// Monday     (Date:  1): Work from 9 AM to 5 PM
// Tuesday    (Date:  2): Meeting at 10 AM
// Wednesday  (Date:  3): Gym at 6 PM
// Thursday   (Date:  4): Dinner with friends at 7 PM
// Friday     (Date:  5): Movie night at 8 PM
// Saturday   (Date:  6): Weekend getaway
// Sunday     (Date:  7): Relax and recharge
// ====================================