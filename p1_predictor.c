#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Constants
#define MAX_DRIVERS 20
#define MAX_STRING_LENGTH 50
#define TOP_TEAMS_COUNT 5
#define TOP_DRIVERS_COUNT 10
#define ELITE_DRIVERS_COUNT 5

// Data structures
typedef struct
{
    char name[MAX_STRING_LENGTH];
    char engine[MAX_STRING_LENGTH];
    bool isTopTeam;
} Team;

typedef struct
{
    char name[MAX_STRING_LENGTH];
    int number;
    char country[MAX_STRING_LENGTH];
    char favoriteTrack[MAX_STRING_LENGTH];
    char homeTrack[MAX_STRING_LENGTH];
    Team *team;
    bool isTopDriver;
    bool isEliteDriver;
    int points;
    float percentage;
    int predictedPosition;
} Driver;

// Top teams and drivers
const char *topTeams[] = {"McLaren", "Ferrari", "Red Bull", "Mercedes", "Williams"};
const char *topDrivers[] = {"Hamilton", "Leclerc", "Verstappen", "Russell", "Alonso", "Piastri", "Norris", "Albon", "Tsunoda", "Sainz"};
const char *eliteDrivers[] = {"Hamilton", "Verstappen", "Norris", "Leclerc", "Russell"};

int main(int argc, char *argv[])
{
    Team teams[10]; // As always
    Driver drivers[MAX_DRIVERS];
    int driverCount = 0;
    char track[MAX_STRING_LENGTH] = "";
    char condition[MAX_STRING_LENGTH] = "";

    // Parse and validate command line args
    if (argc > 3)
    {
        printf("Error: Too many arguments provided.\n");
        displayUsage();
        return 1;
    }
    else if (argc >= 2)
    {
        strncpy(track, argv[1], MAX_STRING_LENGTH - 1);
        track[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null termination
    }

    if (argc == 3)
    {
        strncpy(condition, argv[2], MAX_STRING_LENGTH - 1);
        condition[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null termination
        toLowercase(condition);

        // Validate condition
        if (strcmp(condition, "wet") != 0 && strcmp(condition, "dry") != 0)
        {
            printf("Error: Race condition must be 'wet' or 'dry'.\n");
            displayUsage();
            return 1;
        }
    }

    if (argc < 3)
    {
        printf("Note: For more accurate predictions, run with track name and race condition.\n");
        displayUsage();
    }
}