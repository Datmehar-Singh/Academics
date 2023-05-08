/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider-> This submitted
piece of work is entirely of my own creation->
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

// defining macros
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define FACTOR_PATH_LENGTH 5 // the path length should be a factor of this
#define MAX_LIVES 10
#define MIN_LIVES 1

#include <stdio.h>
#include <ctype.h>

struct PlayerInfo
{
    // variables for a single player
    int lives;
    char name;
    int treasuresFound;
    int positionsHistory[MAX_PATH_LENGTH];
};
struct GameInfo
{
    // variables for game settings
    int maxMoves;
    int pathLength;
    int bombPositions[MAX_PATH_LENGTH];
    int treasurePositions[MAX_PATH_LENGTH];
};

// function prototypes\/

inline int validate(int, int, int); // key to this function- if it return -1 then it is less than min, if 0 then it lies in the range and if 1 then higher than the maximum value

void configurePlayer(struct PlayerInfo *p); // This function will take the input and call the validate function to validate them

void configureGame(struct GameInfo *g, struct PlayerInfo *p); // Function to set the value of the object of struct GameInfo

void setBombPositions(struct GameInfo *g); // function to set the position of the bombs

void setTreasurePosition(struct GameInfo *g); // function to set the position of treasure

void printInfo(struct GameInfo *g1, struct PlayerInfo *p1); // function to print the information of player and game

void printArray(void *array, int size, char type);// prints the array whether is char or an int with taking an void pointer as parameter

void play(struct GameInfo *g1, struct PlayerInfo *p1);//this function start the main playing part of the game

int main(void) // execution starts here
{
    struct PlayerInfo p1 = {0, 'a', 0};
    struct GameInfo g1 = {0, 0};

    configurePlayer(&p1);
    configureGame(&g1, &p1);
    setBombPositions(&g1);
    setTreasurePosition(&g1);
    printInfo(&g1, &p1);

    play(&g1, &p1);

    return 0;
}

// function definitions \/

inline int validate(int input, int min, int max)
{
    if (input < min)
        return -1;
    if (input > max)
        return 1;
    else
        return 0;
}

void configurePlayer(struct PlayerInfo *p)
{
    char charTemp;
    int intTemp;
    int flag = 1;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &charTemp);
    p->name = charTemp;
    /*while(flag)
    {
        if (!isalnum(charTemp))
        {

            flag = 0;
        }
        else
            printf("Invalid input, Enter a character symbol\n");
    }*/
    flag = 1;
    while (flag)
    {
        printf("Set the number of lives: ");
        scanf("%d", &intTemp);
        if (validate(intTemp, MIN_LIVES, MAX_LIVES) == 0)
        {
            p->lives = intTemp;
            flag = 0;
        }
        else
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
    }
    flag = 1;

    printf("Player configuration set-up is complete\n\n");
    return;
}

void configureGame(struct GameInfo *g, struct PlayerInfo *p)
{
    int temp = -1, flag = 1;
    printf("GAME Configuration\n");
    printf("------------------\n");

    while (flag)
    {
        printf("Set the path length (a multiple of %d between %d-%d): ", FACTOR_PATH_LENGTH, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &temp);

        if (validate(temp, MIN_PATH_LENGTH, MAX_PATH_LENGTH) != 0 || temp % 5)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", FACTOR_PATH_LENGTH, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
        else
        {
            g->pathLength = temp;
            flag = 0;
        }
    }
    flag = 1;
    while (flag)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &temp);

        if (validate(temp, p->lives, (int)(0.75 * g->pathLength)) == 0)
        {
            flag = 0;
            g->maxMoves = temp;
        }
        else
        {

            printf("    Value must be between %d and %d\n", p->lives, (int)(0.75 * g->pathLength));
        }
    }
    printf("\n");
return;
}

void setBombPositions(struct GameInfo *g)
{
    int i = 0, j = 0;

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", FACTOR_PATH_LENGTH);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g->pathLength);
    for (; i < g->pathLength / FACTOR_PATH_LENGTH; i++)
    {

        printf("   Positions [%2d-%2d]: ", (i * FACTOR_PATH_LENGTH) + 1, (i * FACTOR_PATH_LENGTH) + FACTOR_PATH_LENGTH);
        for (j = 0; j < FACTOR_PATH_LENGTH; j++)
        {
            scanf("%d", &g->bombPositions[i * FACTOR_PATH_LENGTH + j]);
        }
    }
    printf("BOMB placement set\n\n");
return;
}

void setTreasurePosition(struct GameInfo *g)
{
    int i = 0, j = 0;

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", FACTOR_PATH_LENGTH);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", g->pathLength);
    for (; i < g->pathLength / FACTOR_PATH_LENGTH; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * FACTOR_PATH_LENGTH) + 1, (i * FACTOR_PATH_LENGTH) + FACTOR_PATH_LENGTH);
        for (j = 0; j < FACTOR_PATH_LENGTH; j++)
        {
            scanf("%d", &g->treasurePositions[i * FACTOR_PATH_LENGTH + j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
return;
}

void printInfo(struct GameInfo *g1, struct PlayerInfo *p1)
{
    int i = 0;
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", p1->name);
    printf("   Lives      : %d\n", p1->lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", g1->pathLength);
    printf("   Bombs      : ");

    for (i = 0; i < g1->pathLength;)
    {
        printf("%d", g1->bombPositions[i++]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < g1->pathLength;)
    {
        printf("%d", g1->treasurePositions[i++]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
return;
}

void printArray(void *array, int size, char type)
{
    int i = 0;
    if (type == 'c')
        for (i = 0; i < size; i++)
        {
            printf("%c", *((char *)array + i));
        }
    else if (type == 'i')
    {
        array = (int *)array;
        for (i = 0; i < size; i++)
            printf("%d", *((int *)array + i));
    }
    else
        return;
}

void play(struct GameInfo *g1, struct PlayerInfo *p1)
{
    int i = 0, flag = 1, k = 0;
    int move = -1;
    char scaleArr[MAX_PATH_LENGTH];//array for scale
    int numberArray[MAX_PATH_LENGTH];//array for printing numbers with every move
    int lives = 0, moves = 0;//local counters for breaking of loops

    for (i = 0; i < g1->pathLength; i++)//initialising the arrays to print
    {
        p1->positionsHistory[i] = 0;//initialises the array to be 0 for every element, just to be on the safe side

        if ((i + 1) % 10)// initialises the scale array
            scaleArr[i] = '|';
        else
            scaleArr[i] = (char)(i / 10 + 49);

        numberArray[i] = (i + 1) % 10;//initialises the number array
    }
    printf("\n  ");//printf for formatting
    for (i = 0; i < g1->pathLength; i++)
    {
        /*if (p1->positionsHistory[i] == 1)
            {
                if (g1->bombPositions[i] == 1 && g1->treasurePositions[i] == 1)
                {
                    printf("&");
                }
                else if (g1->bombPositions[i] != 1 && g1->treasurePositions[i] == 1)
                {
                    printf("$");
                }
                else if (g1->bombPositions[i] == 1 && g1->treasurePositions[i] != 1)
                {
                    printf("!");
                }
                else
                {
                    printf(".");
                }
            }
            else*/
                printf("-");
    }
    printf("\n  ");//prints the arrays initialised before- scaleArray and numberArray
    printArray((void *)scaleArr, g1->pathLength, 'c');
    printf("\n  ");
    printArray((void *)numberArray, g1->pathLength, 'i');

    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", p1->lives - lives, p1->treasuresFound, g1->maxMoves - moves);
    printf("+---------------------------------------------------+\n");
    while (lives != p1->lives && moves != g1->maxMoves)
    {
        flag = 1;

        while (flag)//input the move and validates that between the allowed range
        {
            printf("Next Move [1-%d]: ", g1->pathLength);
            scanf("%d", &move);
            if (validate(move, 1, g1->pathLength) == 0)//calls the function that validates
                flag = 0;
            else
                printf("  Out of Range!!!\n");
        }

        if (p1->positionsHistory[move-1] == 1)//chech the history array and prints the suitable output of the !,$ and 
        {
            printf("\n===============> Dope! You've been here before!\n");
            moves--;
        }
        else
        {
            if (g1->bombPositions[move - 1] == 1 && g1->treasurePositions[move - 1] == 1)
            {
                lives++;
                p1->treasuresFound++;
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            }
            else if (g1->bombPositions[move - 1] != 1 && g1->treasurePositions[move - 1] == 1)
            {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
                p1->treasuresFound++;
            }
            else if (g1->bombPositions[move - 1] == 1 && g1->treasurePositions[move - 1] != 1)
            {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
                lives++;

            }
            else
            {
                printf("\n===============> [.] ...Nothing found here... [.]\n");
            }
            if (lives == p1->lives)
            {
                printf("\nNo more LIVES remaining!\n");
            }
        }
	printf("\n  ");
	int done=0;
        for (k = 0; k < g1->pathLength && !done; k++)
        {
            if (k == move - 1)
            {
                printf("%c",p1->name);
                done = 1;
            }
            else
                printf(" ");
        }

        printf("\n  ");
	p1->positionsHistory[move-1]=1;
        for (i = 0; i < g1->pathLength; i++)
        {
            if (p1->positionsHistory[i] == 1)
            {
                if (g1->bombPositions[i] == 1 && g1->treasurePositions[i] == 1)
                {
                    printf("&");
                }
                else if (g1->bombPositions[i] != 1 && g1->treasurePositions[i] == 1)
                {
                    printf("$");
                }
                else if (g1->bombPositions[i] == 1 && g1->treasurePositions[i] != 1)
                {
                    printf("!");
                }
                else
                {
                    printf(".");
                }
            }
            else
                printf("-");
        }
        printf("\n  ");
        printArray((void *)scaleArr, g1->pathLength, 'c');
        printf("\n  ");
        printArray((void *)numberArray, g1->pathLength, 'i');
        moves++;
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", p1->lives - lives, p1->treasuresFound, g1->maxMoves - moves);
        printf("+---------------------------------------------------+\n");
    }
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    return;
}
