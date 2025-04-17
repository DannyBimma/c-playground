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
#define NUM_TEAMS 10
#define NUM_DRIVERS 20
#define SUCCESS 0
#define ERROR_INVALID_TEAM_INDEX -1

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

// Configuration data structure
typedef struct
{
    const char *teamNames[NUM_TEAMS];
    const char *engines[NUM_TEAMS];
    const bool isTopTeam[NUM_TEAMS];
    const char *driverNames[NUM_DRIVERS];
    const int driverNumbers[NUM_DRIVERS];
    const char *driverCountries[NUM_DRIVERS];
    const char *driverFavTracks[NUM_DRIVERS];
    const char *driverHomeTracks[NUM_DRIVERS];
    const int driverTeamIndices[NUM_DRIVERS];
    const bool isTopDriver[NUM_DRIVERS];
    const bool isEliteDriver[NUM_DRIVERS];
} F1Configuration;

// Global configuration data
static const F1Configuration f1Config = {
    .teamNames = {"McLaren", "Ferrari", "Red Bull", "Mercedes", "Aston Martin",
                  "Alpine", "Haas", "Racing Bulls", "Williams", "Sauber"},
    .engines = {"Mercedes", "Ferrari", "Honda RBPT", "Mercedes", "Mercedes",
                "Renault", "Ferrari", "Honda RBPT", "Mercedes", "Ferrari"},
    .isTopTeam = {true, true, true, true, false,
                  false, true, true, true, false},
    .driverNames = {"Norris", "Piastri", "Leclerc", "Hamilton", "Verstappen",
                    "Tsunoda", "Russell", "Antonelli", "Alonso", "Stroll",
                    "Gasly", "Doohan", "Bearman", "Ocon", "Lawson",
                    "Hadjar", "Albon", "Sainz", "Hulkenberg", "Bortoleto"},
    .driverNumbers = {4, 81, 16, 44, 33, 22, 63, 12, 14, 18, 10, 7, 87, 31, 30,
                      6, 23, 55, 27, 5},
    .driverCountries = {"United Kingdom", "Australia", "Monaco", "United Kingdom", "Netherlands",
                        "Japan", "United Kingdom", "Italy", "Spain", "Canada",
                        "France", "Australia", "United Kingdom", "France", "New Zealand",
                        "France", "Thailand", "Spain", "Germany", "Brazil"},
    .driverFavTracks = {"Great Britain", "Spa", "Monaco", "Great Britain", "Spa",
                        "Suzuka", "Silverstone", "Imola", "Spain", "Canada",
                        "Monaco", "Australia", "Jeddah", "France", "New Zealand",
                        "France", "Thailand", "Spain", "Germany", "Brazil"},
    .driverHomeTracks = {"Great Britain", "Australia", "Monaco", "Great Britain", "Netherlands",
                         "Japan", "Great Britain", "Italy", "Spain", "Canada",
                         "France", "Australia", "Great Britain", "France", "New Zealand",
                         "France", "Thailand", "Spain", "Germany", "Brazil"},
    .driverTeamIndices = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9},
    .isTopDriver = {true, true, true, true, true,
                    true, true, true, true, false,
                    true, false, true, true, false,
                    true, true, true, true, false},
    .isEliteDriver = {true, false, true, true, true,
                      false, true, false, true, false,
                      false, false, false, false, false,
                      true, false, false, false, false}};

// Function prototypes
int initTeamsAndDrivers(Team teams[], Driver drivers[], int *driverCount);
void calcPoints(Driver drivers[], int driverCount, const char *track, const char *condition);
void calcPercentages(Driver drivers[], int driverCount);
void predictPositions(Driver drivers[], int driverCount);
void printResults(Driver drivers[], int driverCount, const char *track, const char *condition);
bool isStringInArray(const char *str, const char *array[], int size);
void toLowercase(char *str);
void usageInstructions(void);

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
        usageInstructions();
        return 1;
    }
    else if (argc >= 2)
    {
        strncpy(track, argv[1], MAX_STRING_LENGTH - 1);
        track[MAX_STRING_LENGTH - 1] = '\0'; // Null termination
    }

    if (argc == 3)
    {
        strncpy(condition, argv[2], MAX_STRING_LENGTH - 1);
        condition[MAX_STRING_LENGTH - 1] = '\0';
        toLowercase(condition);

        // Validate condition
        if (strcmp(condition, "wet") != 0 && strcmp(condition, "dry") != 0)
        {
            printf("Error: Race condition must be 'wet' or 'dry'.\n");
            usageInstructions();
            return 1;
        }
    }

    if (argc < 3)
    {
        printf("Note: For more accurate predictions, run with track name and race condition.\n");
        usageInstructions();
    }

    // Function calls
    initTeamsAndDrivers(teams, drivers, &driverCount);

    calcPoints(drivers, driverCount, track, condition);

    calcPercentages(drivers, driverCount);

    predictPositions(drivers, driverCount);

    printResults(drivers, driverCount, track, condition);

    return 0;
}

void usageInstructions(void)
{
    printf("Usage: ./grand_prixdictor [track] [condition]\n");
    printf("Where [track] is the name of the race track or country\n");
    printf("And [condition] is either 'wet' or 'dry'\n");
    printf("Example: ./grand_prixdictor 'Monza' 'wet'\n");
}

void toLowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

bool isStringInArray(const char *str, const char *array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcasecmp(str, array[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

int initTeamsAndDrivers(Team teams[], Driver drivers[], int *driverCount)
{
    if (!teams || !drivers || !driverCount)
    {
        return ERROR_INVALID_TEAM_INDEX;
    }

    // Initialize teams
    for (int i = 0; i < NUM_TEAMS; i++)
    {
        if (strlen(f1Config.teamNames[i]) >= MAX_STRING_LENGTH ||
            strlen(f1Config.engines[i]) >= MAX_STRING_LENGTH)
        {
            return ERROR_INVALID_TEAM_INDEX;
        }
        strncpy(teams[i].name, f1Config.teamNames[i], MAX_STRING_LENGTH - 1);
        teams[i].name[MAX_STRING_LENGTH - 1] = '\0';
        strncpy(teams[i].engine, f1Config.engines[i], MAX_STRING_LENGTH - 1);
        teams[i].engine[MAX_STRING_LENGTH - 1] = '\0';
        teams[i].isTopTeam = f1Config.isTopTeam[i];
    }

    // Initialize drivers
    *driverCount = 0;
    for (int i = 0; i < NUM_DRIVERS; i++)
    {
        // Validate team index
        if (f1Config.driverTeamIndices[i] < 0 || f1Config.driverTeamIndices[i] >= NUM_TEAMS)
        {
            return ERROR_INVALID_TEAM_INDEX;
        }

        // Validate string lengths
        if (strlen(f1Config.driverNames[i]) >= MAX_STRING_LENGTH ||
            strlen(f1Config.driverCountries[i]) >= MAX_STRING_LENGTH ||
            strlen(f1Config.driverFavTracks[i]) >= MAX_STRING_LENGTH ||
            strlen(f1Config.driverHomeTracks[i]) >= MAX_STRING_LENGTH)
        {
            return ERROR_INVALID_TEAM_INDEX;
        }

        // Copy strings with bounds checking
        strncpy(drivers[i].name, f1Config.driverNames[i], MAX_STRING_LENGTH - 1);
        drivers[i].name[MAX_STRING_LENGTH - 1] = '\0';

        strncpy(drivers[i].country, f1Config.driverCountries[i], MAX_STRING_LENGTH - 1);
        drivers[i].country[MAX_STRING_LENGTH - 1] = '\0';

        strncpy(drivers[i].favoriteTrack, f1Config.driverFavTracks[i], MAX_STRING_LENGTH - 1);
        drivers[i].favoriteTrack[MAX_STRING_LENGTH - 1] = '\0';

        strncpy(drivers[i].homeTrack, f1Config.driverHomeTracks[i], MAX_STRING_LENGTH - 1);
        drivers[i].homeTrack[MAX_STRING_LENGTH - 1] = '\0';

        // Set other fields
        drivers[i].number = f1Config.driverNumbers[i];
        drivers[i].team = &teams[f1Config.driverTeamIndices[i]];
        drivers[i].isTopDriver = f1Config.isTopDriver[i];
        drivers[i].isEliteDriver = f1Config.isEliteDriver[i];

        // Initialize calculation fields
        drivers[i].points = 0;
        drivers[i].percentage = 0.0f;
        drivers[i].predictedPosition = 0;

        (*driverCount)++;
    }

    return SUCCESS;
}

void calcPoints(Driver drivers[], int driverCount, const char *track, const char *condition)
{

    // Init points to 0 for all drivers
    for (int i = 0; i < driverCount; i++)
    {
        drivers[i].points = 0;
    }

    // Calc points for each driver ability
    for (int i = 0; i < driverCount; i++)
    {
        if (drivers[i].team->isTopTeam)
        {
            drivers[i].points += 10;
        }

        if (drivers[i].isTopDriver)
        {
            drivers[i].points += 12;
        }

        if (drivers[i].isEliteDriver)
        {
            drivers[i].points += 15;
        }

        // Engine points
        if (strcmp(drivers[i].team->engine, "Mercedes") == 0 ||
            strcmp(drivers[i].team->engine, "Ferrari") == 0 ||
            strcmp(drivers[i].team->engine, "Honda RBPT") == 0)
        {
            drivers[i].points += 5;
        }

        // Track points
        if (track != NULL && strlen(track) > 0)
        {
            bool isFavoriteTrack = strcasecmp(track, drivers[i].favoriteTrack) == 0;
            bool isHomeTrack = strcasecmp(track, drivers[i].homeTrack) == 0 ||
                               strcasecmp(track, drivers[i].country) == 0;

            if (isFavoriteTrack && isHomeTrack)
            {
                drivers[i].points += 12;
            }
            else if (isFavoriteTrack || isHomeTrack)
            {
                drivers[i].points += 6;
            }
        }

        // Wet race points
        if (condition != NULL && strcmp(condition, "wet") == 0 && drivers[i].isTopDriver)
        {
            drivers[i].points += 6;
        }
    }
}

void calcPercentages(Driver drivers[], int driverCount)
{
    int totalPoints = 0;

    // Total points
    for (int i = 0; i < driverCount; i++)
    {
        totalPoints += drivers[i].points;
    }

    // Percentage for each driver
    for (int i = 0; i < driverCount; i++)
    {
        drivers[i].percentage = (float)drivers[i].points / totalPoints * 100.0;
    }
}

// Comparison function for qsort to sort drivers by points
int compareDrivers(const void *a, const void *b)
{
    Driver *driverA = (Driver *)a;
    Driver *driverB = (Driver *)b;

    if (driverA->points > driverB->points)
        return -1;
    if (driverA->points < driverB->points)
        return 1;
    return 0;
}

void predictPositions(Driver drivers[], int driverCount)
{
    // Copy and sort drivers array
    Driver sortedDrivers[MAX_DRIVERS];
    memcpy(sortedDrivers, drivers, driverCount * sizeof(Driver));

    // Sort drivers by points (high to low)
    qsort(sortedDrivers, driverCount, sizeof(Driver), compareDrivers);

    // Assign positions into original driver array
    for (int i = 0; i < driverCount; i++)
    {
        for (int j = 0; j < driverCount; j++)
        {
            if (drivers[j].number == sortedDrivers[i].number)
            {
                drivers[j].predictedPosition = i + 1;
                break;
            }
        }
    }
}

void printResults(Driver drivers[], int driverCount, const char *track, const char *condition)
{
    // Print header
    printf("\n======= F1 Grand Prix Predictor =======\n\n");

    if (track != NULL && strlen(track) > 0)
    {
        printf("Track: %s\n", track);
    }
    else
    {
        printf("Track: Not specified\n");
    }

    if (condition != NULL && strlen(condition) > 0)
    {
        printf("Condition: %s\n", condition);
    }
    else
    {
        printf("Condition: Not specified\n");
    }

    printf("\n");

    // Sort drivers by predicted position
    Driver sortedDrivers[MAX_DRIVERS];
    memcpy(sortedDrivers, drivers, driverCount * sizeof(Driver));
    qsort(sortedDrivers, driverCount, sizeof(Driver), compareDrivers);

    // Driver with highest percentage
    Driver *highestDriver = &sortedDrivers[0];

    printf("Most likely winner: %s (%.2f%% probability)\n\n",
           highestDriver->name, highestDriver->percentage);

    // Print remaining grid positions
    printf("Predicted Grid:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("| Pos | Driver        | Team           | Points | Probability | Number | Country       |\n");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < driverCount; i++)
    {
        printf("| P%-2d | %-13s | %-14s | %-6d | %-10.2f%% | #%-5d | %-13s |\n",
               i + 1,
               sortedDrivers[i].name,
               sortedDrivers[i].team->name,
               sortedDrivers[i].points,
               sortedDrivers[i].percentage,
               sortedDrivers[i].number,
               sortedDrivers[i].country);
    }

    printf("--------------------------------------------------------------------------------\n");
}
