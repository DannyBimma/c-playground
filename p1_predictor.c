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

// Function prototypes
void initTeamsAndDrivers(Team teams[], Driver drivers[], int *driverCount);
void calcPoints(Driver drivers[], int driverCount, const char *track, const char *condition);
void calcPercentages(Driver drivers[], int driverCount);
void predictPositions(Driver drivers[], int driverCount);
void printResults(Driver drivers[], int driverCount, const char *track, const char *condition);
bool isStringInArray(const char *str, const char *array[], int size);
void toLowercase(char *str);
void usageInstructions();

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

void usageInstructions()
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

void initTeamsAndDrivers(Team teams[], Driver drivers[], int *driverCount)
{
    // Teams
    // McLaren
    strcpy(teams[0].name, "McLaren");
    strcpy(teams[0].engine, "Mercedes");
    teams[0].isTopTeam = true;

    // Ferrari
    strcpy(teams[1].name, "Ferrari");
    strcpy(teams[1].engine, "Ferrari");
    teams[1].isTopTeam = true;

    // Red Bull
    strcpy(teams[2].name, "Red Bull");
    strcpy(teams[2].engine, "Honda RBPT");
    teams[2].isTopTeam = true;

    // Mercedes
    strcpy(teams[3].name, "Mercedes");
    strcpy(teams[3].engine, "Mercedes");
    teams[3].isTopTeam = true;

    // Aston Martin
    strcpy(teams[4].name, "Aston Martin");
    strcpy(teams[4].engine, "Mercedes");
    teams[4].isTopTeam = false;

    // Alpine
    strcpy(teams[5].name, "Alpine");
    strcpy(teams[5].engine, "Renault");
    teams[5].isTopTeam = false;

    // Haas
    strcpy(teams[6].name, "Haas");
    strcpy(teams[6].engine, "Ferrari");
    teams[6].isTopTeam = true;

    // Racing Bulls
    strcpy(teams[7].name, "Racing Bulls");
    strcpy(teams[7].engine, "Honda RBPT");
    teams[7].isTopTeam = true;

    // Williams
    strcpy(teams[8].name, "Williams");
    strcpy(teams[8].engine, "Mercedes");
    teams[8].isTopTeam = true;

    // Sauber
    strcpy(teams[9].name, "Sauber");
    strcpy(teams[9].engine, "Ferrari");
    teams[9].isTopTeam = false;

    // Drivers
    *driverCount = 0;

    // McLaren drivers
    strcpy(drivers[*driverCount].name, "Norris");
    drivers[*driverCount].number = 4;
    strcpy(drivers[*driverCount].country, "United Kingdom");
    strcpy(drivers[*driverCount].favoriteTrack, "Great Britain");
    strcpy(drivers[*driverCount].homeTrack, "Great Britain");
    drivers[*driverCount].team = &teams[0];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = true;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Piastri");
    drivers[*driverCount].number = 81;
    strcpy(drivers[*driverCount].country, "Australia");
    strcpy(drivers[*driverCount].favoriteTrack, "Spa");
    strcpy(drivers[*driverCount].homeTrack, "Australia");
    drivers[*driverCount].team = &teams[0];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    // Ferrari drivers
    strcpy(drivers[*driverCount].name, "Leclerc");
    drivers[*driverCount].number = 16;
    strcpy(drivers[*driverCount].country, "Monaco");
    strcpy(drivers[*driverCount].favoriteTrack, "Monaco");
    strcpy(drivers[*driverCount].homeTrack, "Monaco");
    drivers[*driverCount].team = &teams[1];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = true;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Hamilton");
    drivers[*driverCount].number = 44;
    strcpy(drivers[*driverCount].country, "United Kingdom");
    strcpy(drivers[*driverCount].favoriteTrack, "Great Britain");
    strcpy(drivers[*driverCount].homeTrack, "Great Britain");
    drivers[*driverCount].team = &teams[1];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = true;
    (*driverCount)++;

    // Red Bull drivers
    strcpy(drivers[*driverCount].name, "Verstappen");
    drivers[*driverCount].number = 33;
    strcpy(drivers[*driverCount].country, "Netherlands");
    strcpy(drivers[*driverCount].favoriteTrack, "Spa");
    strcpy(drivers[*driverCount].homeTrack, "Netherlands");
    drivers[*driverCount].team = &teams[2];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = true;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Tsunoda");
    drivers[*driverCount].number = 22;
    strcpy(drivers[*driverCount].country, "Japan");
    strcpy(drivers[*driverCount].favoriteTrack, "Suzuka");
    strcpy(drivers[*driverCount].homeTrack, "Japan");
    drivers[*driverCount].team = &teams[2];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    // Mercedes drivers
    strcpy(drivers[*driverCount].name, "Russell");
    drivers[*driverCount].number = 63;
    strcpy(drivers[*driverCount].country, "United Kingdom");
    strcpy(drivers[*driverCount].favoriteTrack, "Silverstone");
    strcpy(drivers[*driverCount].homeTrack, "Great Britain");
    drivers[*driverCount].team = &teams[3];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = true;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Antonelli");
    drivers[*driverCount].number = 12;
    strcpy(drivers[*driverCount].country, "Italy");
    strcpy(drivers[*driverCount].favoriteTrack, "Imola");
    strcpy(drivers[*driverCount].homeTrack, "Italy");
    drivers[*driverCount].team = &teams[3];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    // Aston Martin drivers
    strcpy(drivers[*driverCount].name, "Alonso");
    drivers[*driverCount].number = 14;
    strcpy(drivers[*driverCount].country, "Spain");
    strcpy(drivers[*driverCount].favoriteTrack, "Spain");
    strcpy(drivers[*driverCount].homeTrack, "Spain");
    drivers[*driverCount].team = &teams[4];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = true;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Stroll");
    drivers[*driverCount].number = 18;
    strcpy(drivers[*driverCount].country, "Canada");
    strcpy(drivers[*driverCount].favoriteTrack, "Canada");
    strcpy(drivers[*driverCount].homeTrack, "Canada");
    drivers[*driverCount].team = &teams[4];
    drivers[*driverCount].isTopDriver = false;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    // Alpine drivers
    strcpy(drivers[*driverCount].name, "Gasly");
    drivers[*driverCount].number = 10;
    strcpy(drivers[*driverCount].country, "France");
    strcpy(drivers[*driverCount].favoriteTrack, "Monaco");
    strcpy(drivers[*driverCount].homeTrack, "France");
    drivers[*driverCount].team = &teams[5];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Doohan");
    drivers[*driverCount].number = 7;
    strcpy(drivers[*driverCount].country, "Australia");
    strcpy(drivers[*driverCount].favoriteTrack, "Australia");
    strcpy(drivers[*driverCount].homeTrack, "Australia");
    drivers[*driverCount].team = &teams[5];
    drivers[*driverCount].isTopDriver = false;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    // Haas drivers
    strcpy(drivers[*driverCount].name, "Bearman");
    drivers[*driverCount].number = 87;
    strcpy(drivers[*driverCount].country, "United Kingdom");
    strcpy(drivers[*driverCount].favoriteTrack, "Jeddah");
    strcpy(drivers[*driverCount].homeTrack, "Great Britain");
    drivers[*driverCount].team = &teams[6];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Ocon");
    drivers[*driverCount].number = 31;
    strcpy(drivers[*driverCount].country, "France");
    strcpy(drivers[*driverCount].favoriteTrack, "France");
    strcpy(drivers[*driverCount].homeTrack, "France");
    drivers[*driverCount].team = &teams[6];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    // Racing Bulls drivers
    strcpy(drivers[*driverCount].name, "Lawson");
    drivers[*driverCount].number = 30;
    strcpy(drivers[*driverCount].country, "New Zealand");
    strcpy(drivers[*driverCount].favoriteTrack, "New Zealand");
    strcpy(drivers[*driverCount].homeTrack, "New Zealand");
    drivers[*driverCount].team = &teams[7];
    drivers[*driverCount].isTopDriver = false;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Hadjar");
    drivers[*driverCount].number = 6;
    strcpy(drivers[*driverCount].country, "France");
    strcpy(drivers[*driverCount].favoriteTrack, "France");
    strcpy(drivers[*driverCount].homeTrack, "France");
    drivers[*driverCount].team = &teams[7];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = true;
    (*driverCount)++;

    // Williams drivers
    strcpy(drivers[*driverCount].name, "Albon");
    drivers[*driverCount].number = 23;
    strcpy(drivers[*driverCount].country, "Thailand");
    strcpy(drivers[*driverCount].favoriteTrack, "Thailand");
    strcpy(drivers[*driverCount].homeTrack, "Thailand");
    drivers[*driverCount].team = &teams[8];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Sainz");
    drivers[*driverCount].number = 55;
    strcpy(drivers[*driverCount].country, "Spain");
    strcpy(drivers[*driverCount].favoriteTrack, "Spain");
    strcpy(drivers[*driverCount].homeTrack, "Spain");
    drivers[*driverCount].team = &teams[8];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    // Sauber drivers
    strcpy(drivers[*driverCount].name, "Hulkenberg");
    drivers[*driverCount].number = 27;
    strcpy(drivers[*driverCount].country, "Germany");
    strcpy(drivers[*driverCount].favoriteTrack, "Germany");
    strcpy(drivers[*driverCount].homeTrack, "Germany");
    drivers[*driverCount].team = &teams[9];
    drivers[*driverCount].isTopDriver = true;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;

    strcpy(drivers[*driverCount].name, "Bortoleto");
    drivers[*driverCount].number = 5;
    strcpy(drivers[*driverCount].country, "Brazil");
    strcpy(drivers[*driverCount].favoriteTrack, "Brazil");
    strcpy(drivers[*driverCount].homeTrack, "Brazil");
    drivers[*driverCount].team = &teams[9];
    drivers[*driverCount].isTopDriver = false;
    drivers[*driverCount].isEliteDriver = false;
    (*driverCount)++;
}

void calcPoints(Driver drivers[], int driverCount, const char *track, const char *condition)
{

    int totalPoints = 0;

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