/*
*****************************************************************************
                          Workshop - #5 (P1)
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

int main(void)
{
    const int jan = 1,
        dec = 12;
    int flag = 0,
      inputYear = 0,
      inputMonth = 0;

    printf("General Well-being Log\n======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &inputYear, &inputMonth);

        if (inputYear<=MAX_YEAR && inputYear>=MIN_YEAR && inputMonth<=dec && inputMonth>=jan )
        {
            flag = 1;
        }
        else if ( !(inputYear<=MAX_YEAR && inputYear>=MIN_YEAR) && inputMonth<=dec && inputMonth>=jan)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if(!(inputYear<=MAX_YEAR && inputYear>=MIN_YEAR) && !(inputMonth<=dec && inputMonth>=jan))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if (inputYear<=MAX_YEAR && inputYear>=MIN_YEAR && !(inputMonth<=dec && inputMonth>=jan))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    }
        while (flag!=1);

    printf("\n*** Log date set! ***\n");
    switch (inputMonth)
    {
    case 1:
        printf("\nLog starting date: %d-JAN-01\n", inputYear);break;
    case 2:
        printf("\nLog starting date: %d-FEB-01\n", inputYear);break;
    case 3:
        printf("\nLog starting date: %d-MAR-01\n", inputYear);break;
    case 4:
        printf("\nLog starting date: %d-APR-01\n", inputYear);break;
    case 5:
        printf("\nLog starting date: %d-MAY-01\n", inputYear);break;
    case 6:
        printf("\nLog starting date: %d-JUN-01\n", inputYear);break;
    case 7:
        printf("\nLog starting date: %d-JUL-01\n", inputYear);break;
    case 8:
        printf("\nLog starting date: %d-AUG-01\n", inputYear);break;
    case 9:
        printf("\nLog starting date: %d-SEP-01\n", inputYear);break;
    case 10:
        printf("\nLog starting date: %d-OCT-01\n", inputYear);break;
    case 11:
        printf("\nLog starting date: %d-NOV-01\n", inputYear);break;
    case 12:
        printf("\nLog starting date: %d-DEC-01\n", inputYear);break;
    }


    return 0;
}