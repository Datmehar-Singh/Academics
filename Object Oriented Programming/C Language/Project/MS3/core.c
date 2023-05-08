/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include <string.h>
#include <math.h>
#include "core.h"
#include"clinic.h"

void clearInputBuffer(void)
{
    while (getchar() != '\n'){;}
}
double power(int X, int Y) {

	double power = 1, i=0;

	for (i = 1; i <= Y; ++i)
	 {
		power = power * X;
	}

	return power;

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
/*char inputCharOption(char string[])
{
    char res[10];
    int flag = 1, i = 0;

    while (flag)
    {
        scanf(" %[^\n]s",res);
        if(strlen(res)!=1){
            printf("ERROR: Character must be one of [%s]: ", string);}
        else
        {
            for (i = 0; i<strlen(string) && flag; i++)
            {
                if (res[0] == string[i])
                    flag = 0;
            }
            if (flag) printf("ERROR: Character must be one of [%s]: ", string);
        }
    }


    return res[0];
}*/

char inputCharOption(char validChar[])
{
	int flag = 0, i = 0;
	char character;
	char newLine='x';

	do
	{
		scanf(" %c%c", &character, &newLine);
		if (newLine == '\n')
		{
			i = 0;
			while (validChar[i] != 0 && flag == 0)
			{
				if (validChar[i] == character)
					flag = 1;

				else i++;
			}
		}
		else
		{
			clearInputBuffer();
		}

		if (flag == 0)
		{
			printf("ERROR: Character must be one of [%s]: ", validChar);
		}

	} while (flag == 0);

	return character;
}

void inputCString(char *string, int lower_bound, int upper_bound)
{
    int flag = 1;
    while (flag)
    {
        scanf(" %[^\n]s",string);
        
        if (lower_bound == upper_bound && strlen(string) != lower_bound)
            printf("ERROR: String length must be exactly %d chars : ", lower_bound);
        else if (lower_bound != upper_bound)
        {
            if (strlen(string) > upper_bound)
                printf("ERROR: String length must be no more than %d chars: ", upper_bound);
            else if (strlen(string) < lower_bound && lower_bound != upper_bound)
                printf("ERROR: String length must be between %d and %d chars: ", lower_bound, upper_bound);
            else
                flag = 0;
        }
        else if (lower_bound == upper_bound && strlen(string) == lower_bound)
            flag = 0;
    }
}


void inputPhoneNumber(char* num)
{
    char string[20];
    int flag=1;
    while(flag)
    {
        scanf(" %[^\n]s",string);
        if(strlen(string)!=10)
            printf("Invalid 10-digit number! Number: ");
        else 
            flag=0;
    }
    strcpy(num,string);
}

void displayFormattedPhone(const char* string)
{
    if (!string)
    {
        printf("(___)___-____");
        return;
    }
    int flag = 0, i = 0;

    for (i = 0; i<strlen(string); i++)
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


int stringToInteger(char string[]){
    int i;
    double res=0;
        for(i=0;i<strlen(string);i++)
        {
            res+= (int)(((string[i]-48)) * power(10,strlen(string)-1-i));
        }
    return (int)res;
}

void inputDate(int* year,int* month, int* day)
{
    printf("Year        : ");
    *year=inputIntPositive();
    printf("Month (1-12): ");
    *month=inputIntRange(1,12);

    switch(*month%2)
    {
        case 0:
        if(*month!=2){
            printf("Day (1-30)  : ");
            *day=inputIntRange(1,30);
        }else
        {
            if(*year%4)
            {
            printf("Day (1-28)  : ");
            *day=inputIntRange(1,28);
            }else
            {
                printf("Day (1-29)  : ");
                *day=inputIntRange(1,29);
            }
        }break;
        case 1:
            printf("Day (1-31)  : ");
            *day=inputIntRange(1,31);
        break;
    }


}


/*void sortByDate(struct Appointment* appoints,int max)
{    
    int i = 0, j = 0;
    struct Appointment sort = appoints[i];
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max - 1; j++)
        {
            if  (appoints[j].date.year > appoints[j + 1].date.year || (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month > appoints[j + 1].date.month) || (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month == appoints[j + 1].date.month && appoints[j].date.day > appoints[j + 1].date.day) ||
                (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month == appoints[j + 1].date.month && appoints[j].date.day == appoints[j + 1].date.day && appoints[j].time.hour > appoints[j + 1].time.hour) ||
                (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month == appoints[j + 1].date.month && appoints[j].date.day == appoints[j + 1].date.day && appoints[j].time.hour == appoints[j + 1].time.hour && appoints[j].time.min > appoints[j + 1].time.min))
            {
                sort = appoints[j];
                appoints[j] = appoints[j+1];
                appoints[j+1] = sort;
            }
        }
    }
}

int checkDate(struct Date* date,int year, int month, int day)
{
    return (date->day==day && date->month==month && date->year==year)?1:0;

}*/
