/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

#include <stdio.h>
#include "core.h"

void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ;
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// function to input an int data type and return it after validating that it is an int for sure
int inputInt(void)
{
    int res = 0, flag = 1;
    char newLine = '0';
    scanf("%d%c", &res, &newLine);
    while (flag)
    {
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
            scanf(" %d%c", &res, &newLine);
        }
        else
            flag = 0;
    }
    return res;
}

// fucntion to input an int which is strictly positive
int inputIntPositive(void)
{
    int flag = 1, res = 0;

    while (flag)
    {
        res = inputInt();
        if (res < 1)
            printf("ERROR! Value must be > 0: ");
        else
            flag = 0;
    }
    return res;
}

// function which will return an integer value that will remain in the range
int inputIntRange(int lower_bound, int upper_bound)
{
    int flag = 1, res = 0;

    while (flag)
    {
        res = inputInt();
        if (res < lower_bound || res > upper_bound)
            printf("ERROR! Value must be between %d and %d inclusive: ", lower_bound, upper_bound);
        else
            flag = 0;
    }
    return res;
}

// A fucntion which will gaurantee the input of a single character which is present in the cstring
char inputCharOption(char string[])
{
    char res = 'a';
    int flag = 1, i = 0;

    while (flag)
    {
        scanf(" %c", &res);
        for (i = 0; string[i] != '\0' && flag; i++)
        {

            if (res == string[i])
                flag = 0;
        }
        if (flag)
            printf("ERROR: Character must be one of [%s]: ", string);
    }
    return res;
}

void inputCString(char *string, int lower_bound, int upper_bound)
{
    int flag = 1, i = 0;
    while (flag)
    {
        scanf(" %[^\n]s", string);
        for (i = 0; *(string + i) != '\0'; i++)
        {
            ;
        }

        if (lower_bound == upper_bound && i != lower_bound)
            printf("ERROR: String length must be exactly %d chars: ", lower_bound);
        else if (lower_bound != upper_bound)
        {
            if (i > upper_bound)
                printf("ERROR: String length must be no more than %d chars: ", upper_bound);
            else if (i < lower_bound && lower_bound != upper_bound)
                printf("ERROR: String length must be between %d and %d chars: ", lower_bound, upper_bound);
            else
                flag = 0;
        }
        else if (lower_bound == upper_bound && i == lower_bound)
            flag = 0;
    }
}

void displayFormattedPhone(char *const string)
{
    if (!string)
    {
        printf("(___)___-____");
        return;
    }
    int flag = 0, i = 0;

    for (i = 0; *(string + i) != '\0'; i++)
    {
        if (*(string + i) < 48 || *(string + i) > 57)
            flag++;
    }
    if (i == 10 && !flag)
    {
        for (i = 0; i < 10; i++)
        {
            if (i == 0)
                printf("(");
            else if (i == 3)
                printf(")");
            else if (i == 6)
                printf("-");

            printf("%c", *(string + i));
        }
    }
    else
    {
        printf("(___)___-____");
    }
}