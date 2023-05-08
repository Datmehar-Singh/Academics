/*
*****************************************************************************
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int jan = 1,
        dec = 12;
    int flag = 0,
        inputYear = 0,
        inputMonth = 0;
    double averageMorning = 0.0,
        averageEvening = 0.0,
        morningRating = 0.0,
        eveningRating = 0.0;
    double totalMorning = 0.0,
        totalEvening = 0.0;
    int i;

    printf("General Well-being Log\n======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &inputYear, &inputMonth);

        if (inputYear <= MAX_YEAR && inputYear >= MIN_YEAR && inputMonth <= dec && inputMonth >= jan)
        {
            flag = 1;
        }
        else if (!(inputYear <= MAX_YEAR && inputYear >= MIN_YEAR) && inputMonth <= dec && inputMonth >= jan)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if (!(inputYear <= MAX_YEAR && inputYear >= MIN_YEAR) && !(inputMonth <= dec && inputMonth >= jan))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if (inputYear <= MAX_YEAR && inputYear >= MIN_YEAR && !(inputMonth <= dec && inputMonth >= jan))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while (flag != 1);

    printf("\n*** Log date set! ***\n");

    for (i = 1;i <= LOG_DAYS; i++)
    {
        flag = 1;
        switch (inputMonth)
        {
        case 1:
            if(!(i/10))
            printf("\n%d-JAN-0%d\n", inputYear,i);
            else
                printf("\n%d-JAN-%d\n", inputYear, i);

            break;

        case 2:
            if (!(i / 10))
                printf("\n%d-FEB-0%d\n", inputYear, i);
            else
                printf("\n%d-FEB-%d\n", inputYear, i);

            break;
        case 3:
            if (!(i / 10))
                printf("\n%d-MAR-0%d\n", inputYear, i);
            else
                printf("\n%d-MAR-%d\n", inputYear, i);

            break;
        case 4:
            if (!(i / 10))
                printf("\n%d-APR-0%d\n", inputYear, i);
            else
                printf("\n%d-APR-%d\n", inputYear, i);

            break;
        case 5:
            if (!(i / 10))
                printf("\n%d-MAY-0%d\n", inputYear, i);
            else
                printf("\n%d-MAY-%d\n", inputYear, i);

            break;
        case 6:
            if (!(i / 10))
                printf("\n%d-JUN-0%d\n", inputYear, i);
            else
                printf("\n%d-JUN-%d\n", inputYear, i);

            break;
        case 7:
            if (!(i / 10))
                printf("\n%d-JUL-0%d\n", inputYear, i);
            else
                printf("\n%d-JUL-%d\n", inputYear, i);

            break;
        case 8:
            if (!(i / 10))
                printf("\n%d-AUG-0%d\n", inputYear, i);
            else
                printf("\n%d-AUG-%d\n", inputYear, i);

            break;
        case 9:
            if (!(i / 10))
                printf("\n%d-SEP-0%d\n", inputYear, i);
            else
                printf("\n%d-SEP-%d\n", inputYear, i);

            break;
        case 10:
            if (!(i / 10))
                printf("\n%d-OCT-0%d\n", inputYear, i);
            else
                printf("\n%d-OCT-%d\n", inputYear, i);

            break;
        case 11:
            if (!(i / 10))
                printf("\n%d-NOV-0%d\n", inputYear, i);
            else
                printf("\n%d-NOV-%d\n", inputYear, i);

            break;
        case 12:
            if (!(i / 10))
                printf("\n%d-DEC-0%d\n", inputYear, i);
            else
                printf("\n%d-DEC-%d\n", inputYear, i);

            break;
        }

        while (flag)
        {
            printf("   Morning rating (0.0-5.0): ");      scanf("%lf", &morningRating);
            if (morningRating < 0 || morningRating > 5) printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            else flag = 0;
        }
        flag = 1;
        totalMorning += morningRating;

        while (flag)
        {
            printf("   Evening rating (0.0-5.0): ");      scanf("%lf", &eveningRating);
            if (eveningRating < 0 || eveningRating > 5) printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            else flag = 0;
        }
        totalEvening += eveningRating;
    }


    int tempTotalMorning = totalMorning * 10000;
    int decision = tempTotalMorning % 10 > 5;
    tempTotalMorning /= 10;
    tempTotalMorning += decision;

    averageMorning = totalMorning / LOG_DAYS;
    averageEvening = totalEvening / LOG_DAYS;

    int tempTotalEvening = totalEvening * 10000;
    decision = tempTotalEvening % 10 > 5;
    tempTotalEvening /= 10;
    tempTotalEvening += decision;


    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating:%7.3lf\n", tempTotalMorning/1000.0);
    printf("Evening total rating:%7.3lf\n", tempTotalEvening/1000.0);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n\n", tempTotalMorning / 1000.0 + tempTotalEvening / 1000.0);

    if (((int)(averageMorning * 100)) % 10)
        printf("Average morning rating:%5.1lf\n", ((int)(averageMorning * 100)) % 10 >= 5 ? ((int)(averageMorning * 10) + 1) / 10.0 : (int)(averageMorning * 10) / 10.0);
    else
        printf("Average morning rating:%5.1lf\n", averageMorning);
    
    if(((int)(averageEvening * 100)) % 10 )
        printf("Average evening rating:%5.1lf\n", ((int)(averageEvening * 100)) % 10 >= 5 ? ((int)(averageEvening * 10) + 1) / 10.0 : (int)(averageEvening * 10) / 10.0);
    else
        printf("Average evening rating:%5.1lf\n", averageEvening);

    printf("----------------------------\n");
    printf("Average overall rating:%5.1lf\n", (int)((averageMorning+ averageEvening)*100/2) % 10 >= 5 ? ((int)((averageMorning + averageEvening) * 10/2) + 1) / 10.0 : (int)((averageMorning + averageEvening) * 10/2) / 10.0);

    return 0;
}