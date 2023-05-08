/*
*****************************************************************************
                          Workshop - #7 (P1)
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

//defining macros
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define FACTOR_PATH_LENGTH 5//the path length should be a factor of this
#define MAX_LIVES 10
#define MIN_LIVES 1

#include <stdio.h>
#include <ctype.h>

struct PlayerInfo{
    //variables for a single player
    int lives;
    char name;
    int treasuresFound;
    int positionsHistory[MAX_PATH_LENGTH];

};
struct GameInfo{
    //variables for game settings
    int maxMoves;
    int pathLength;
    int bombPositions[MAX_PATH_LENGTH];
    int treasurePositions[MAX_PATH_LENGTH];
};


//function prototypes\/

inline int validate(int, int, int);//key to this function- if it return -1 then it is less than min, if 0 then it lies in the range and if 1 then higher than the maximum value

void configurePlayer(struct PlayerInfo *p);//This function will take the input and call the validate function to validate them

void configureGame(struct GameInfo *g,struct PlayerInfo *p);//Function to set the value of the object of struct GameInfo

void setBombPositions(struct GameInfo *g);//function to set the position of the bombs

void setTreasurePosition(struct GameInfo *g);//function to set the position of treasure

void printInfo(struct GameInfo *g1,struct PlayerInfo *p1);//function to print the information of 

int main(void)//execution starts here
{
    struct PlayerInfo p1 = { 0,'a',0 };
    struct GameInfo g1 = {0,0};

    configurePlayer(&p1);
    configureGame(&g1,&p1);
    setBombPositions(&g1);
    setTreasurePosition(&g1);
    printInfo(&g1, &p1);

    return 0;
}

//function definitions \/

inline int validate(int input, int min, int max)
{
    if(input<min) return -1;
    if (input>max) return 1;
    else return 0;
}

void configurePlayer(struct PlayerInfo *p)
{
    char charTemp;
    int intTemp;
    int flag=1;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
        printf("Enter a single character to represent the player: ");
        scanf(" %c", &charTemp);
        p->name = charTemp;

    while(flag)
    {
        printf("Set the number of lives: ");
        scanf("%d",&intTemp);
        if(validate(intTemp,MIN_LIVES,MAX_LIVES)==0)
        {
            p->lives = intTemp;
            flag = 0;
        }
        else
            printf("     Must be between %d and %d!\n",MIN_LIVES, MAX_LIVES);
    }
    flag=1;

    printf("Player configuration set-up is complete\n\n");
    return;
}

void configureGame(struct GameInfo *g,struct PlayerInfo *p)
{
    int temp = -1,flag=1;
    printf("GAME Configuration\n");
    printf("------------------\n");

    while(flag)
    {
        printf("Set the path length (a multiple of %d between %d-%d): ",FACTOR_PATH_LENGTH , MIN_PATH_LENGTH , MAX_PATH_LENGTH);
        scanf("%d",&temp);

        if(validate(temp,MIN_PATH_LENGTH,MAX_PATH_LENGTH)!=0 || temp%5)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n",FACTOR_PATH_LENGTH , MIN_PATH_LENGTH , MAX_PATH_LENGTH);
        }
        else{
            g->pathLength=temp;
            flag=0;
        }
    }
    flag=1;
    while(flag)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d",&temp);

        if(validate(temp,p->lives,(int)(0.75*g->pathLength))==0)
        {
            flag=0;
            g->maxMoves=temp;
        }
        else 
        {
            printf("    Value must be between 3 and 26\n");
        }
    }
    printf("\n");
}

void setBombPositions(struct GameInfo *g)
{
    int i=0,j=0;

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n",FACTOR_PATH_LENGTH);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",g->pathLength);
    for(;i<g->pathLength/FACTOR_PATH_LENGTH;i++)
    {

        printf("   Positions [%2d-%2d]: ", (i * FACTOR_PATH_LENGTH) + 1, (i * FACTOR_PATH_LENGTH) + FACTOR_PATH_LENGTH);
        for(j=0;j<FACTOR_PATH_LENGTH;j++)
        {
            scanf("%d",&g->bombPositions[i*FACTOR_PATH_LENGTH+j]);
        }
    }
    printf("BOMB placement set\n\n");
}

void setTreasurePosition(struct GameInfo *g)
{
    int i=0,j=0;

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n",FACTOR_PATH_LENGTH);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",g->pathLength);
    for(;i<g->pathLength/FACTOR_PATH_LENGTH;i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * FACTOR_PATH_LENGTH) + 1, (i * FACTOR_PATH_LENGTH) + FACTOR_PATH_LENGTH);
        for(j=0;j<FACTOR_PATH_LENGTH;j++)
        {
            scanf("%d",&g->treasurePositions[i*FACTOR_PATH_LENGTH+j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
}

void printInfo(struct GameInfo *g1,struct PlayerInfo *p1)
{
    int i=0;
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n",p1->name);
    printf("   Lives      : %d\n",p1->lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n",g1->pathLength);
    printf("   Bombs      : ");

    for(i=0;i<g1->pathLength;)
    {
        printf("%d",g1->bombPositions[i++]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for(i=0;i<g1->pathLength;)
    {
        printf("%d",g1->treasurePositions[i++]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

}