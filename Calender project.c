#include <stdio.h>

// checking the year is a leap year or not
int LeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0); 
        }
        return 1; 
    }
    return 0; 
}

// printing  a single month of the year
void printMonth(int month, int year, int startDay, int daysinMonth) {
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};

    printf("\n   %s %d \n", months[month - 1], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    // Print spaces before the first day of the month
    for (int i = 0; i < startDay; i++)
    {
        printf("   ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysinMonth; day++) 
    {
        printf("%2d ", day);
        startDay++;
        if (startDay > 6) 
        { // Move to the next line after Saturday
            startDay = 0;
            printf("\n");
        }
    }
    printf("\n");
}

int getStartingDay(int year) 
{
    int century = year / 100;
    int yearofCentury = year % 100;

    
    return (1 + (13 * (1 + 1)) / 5 + yearofCentury + yearofCentury / 4 + century / 4 + 5 * century) % 7;
}


// code  to print the full calendar for the year
void printCalendar(int year) 
{
    int startDay = getStartingDay(year); 
    int daysinMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // setting February for leap years
    if (LeapYear(year)) 
    {
        daysinMonths[1] = 29; // February has 29 days in a leap year
    }

    // Print each month in the year
    for (int month = 1; month <= 12; month++) 
    {
        printMonth(month, year, startDay, daysinMonths[month - 1]);
        startDay = (startDay + daysinMonths[month - 1]) % 7; 
    }
}

int main() {
    int year;

    // Get the year of input from user
    printf("Enter a year: ");
    scanf("%d", &year);
    // Check  the input of  year is a leap year or not 
    if (LeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
    printf("\tCalendar\n ");

    // Print the calendar for the full year
    printCalendar(year);

    return 0;
}
 