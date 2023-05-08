/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    //variable declaration and initialisation
    int apples = -1,
        oranges = -1,
        pears = -1,
        tomatoes = -1,
        cabbages = -1;
    int applesPicked = -1,
        orangesPicked = -1,
        pearsPicked = -1,
        tomatoesPicked = -1,
        cabbagesPicked = -1;
    int ch = 0;


    do {
        printf("Grocery Shopping\n");
        printf("================");
        while (1)
        {
            printf("\nHow many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples < 0) printf("ERROR: Value must be 0 or more.");
            else break;
        }


        while (1)
        {
            printf("\nHow many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges < 0) printf("ERROR: Value must be 0 or more.");
            else break;
        }

        while (1)
        {
            printf("\nHow many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears < 0) printf("ERROR: Value must be 0 or more.");
            else break;
        }


        while (1)
        {
            printf("\nHow many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes < 0) printf("ERROR: Value must be 0 or more.");
            else break;
        }

        while (1)
        {
            printf("\nHow many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages < 0) printf("ERROR: Value must be 0 or more.");
            else break;
        }

        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        if (apples)
        {
            while (1)
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &applesPicked);


                if (applesPicked > apples) {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n",apples);
                }
                else if (applesPicked == apples) {
                    printf("Great, that's the apples done!\n");
                    break;
                }
                else if (applesPicked < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Looks like we still need some APPLES...\n");
                    apples -= applesPicked;
                }

            }
            printf("\n");
        }

        if (oranges)
        {
            while (1)
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &orangesPicked);


                if (orangesPicked > oranges) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n",oranges);
                }
                else if (orangesPicked == oranges) {
                    printf("Great, that's the oranges done!\n");
                    break;
                }
                else if (orangesPicked < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Looks like we still need some ORANGES...\n");
                    oranges -= orangesPicked;
                }

            }
        printf("\n");
        }

        if (pears)
        {
            while (1)
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pearsPicked);


                if (pearsPicked > pears) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n",pears);
                }
                else if (pearsPicked == pears) {
                    printf("Great, that's the pears done!\n");
                    break;
                }
                else if (pearsPicked < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Looks like we still need some PEARS...\n");
                    pears -= pearsPicked;
                }

            }
        printf("\n");
        }

        if (tomatoes)
        {
            while (1)
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &tomatoesPicked);


                if (tomatoesPicked > tomatoes) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else if (tomatoesPicked == tomatoes) {
                    printf("Great, that's the tomatoes done!\n");
                    break;
                }
                else if (tomatoesPicked < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Looks like we still need some TOMATOES...\n");
                    tomatoes -= tomatoesPicked;
                }

            }
            printf("\n");

        }

        if (cabbages)
        {
            while (1)
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &cabbagesPicked);


                if (cabbagesPicked > cabbages) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n",cabbages);
                }
                else if (cabbagesPicked == cabbages) {
                    printf("Great, that's the cabbages done!\n");
                    break;
                }
                else if (cabbagesPicked < 1) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Looks like we still need some CABBAGES...\n");
                    cabbages -= cabbagesPicked;
                }

            }
            printf("\n");
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &ch);
        printf("\n");


    }while (ch != 0);
	printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}