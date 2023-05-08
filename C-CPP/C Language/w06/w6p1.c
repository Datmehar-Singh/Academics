/*
*****************************************************************************
                          Workshop - #6 (P1)
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
    const int MAXINCOME = 400000, MININCOME = 500, MINITEM = 0, MAXITEM = 10, MINITEMCOST = 100;
    double netIncome = 0.0;
    int flag = 0,
        itemNo = 0;
    int counter = 0;
    double itemCostOf[10];
    int importanceOf[10];
    char finOptionOf[10];
    int i = 0;
    double total = 0;


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    while (flag == 0)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if (netIncome <= MININCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (netIncome > MAXINCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        else
        {
            flag = 1;
        }
            printf("\n");
    }
    flag = 0;

    while (flag == 0) 
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &itemNo);

        if (itemNo >= MAXITEM) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else if (itemNo <= MINITEM) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        else
            flag = 1;
        printf("\n");
    }
    while (counter < itemNo)
    {
        printf("Item-%d Details:\n", counter + 1);//used a plus 1 here to reduce the number of times of -1 innthe array access
        while (flag)
        {
            printf("   Item cost: $");
            scanf("%lf", &itemCostOf[counter]);
            if (itemCostOf[counter] < MINITEMCOST)
                printf("      ERROR: Cost must be at least $100.00\n");
            else
                flag = 0;
        }
        flag = 1;
        while (flag)
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &importanceOf[counter]);
            if (importanceOf[counter] < 1 || importanceOf[counter]>3)
                printf("      ERROR: Value must be between 1 and 3\n");
            else
                flag = 0;
        }
        flag = 1;
        while (flag)
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finOptionOf[counter]);
            if (finOptionOf[counter] != 'n' && finOptionOf[counter] != 'y')
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            else
                flag = 0;
        }
        printf("\n");
        flag = 1;
        counter++;
    }
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0;i < counter;i++)
    {
        printf("%3d %6d %8c    %11.2lf\n",i+1,importanceOf[i],finOptionOf[i],itemCostOf[i]);
        total += itemCostOf[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total);
    printf("Best of luck in all your future endeavours!\n");


    return 0;
}