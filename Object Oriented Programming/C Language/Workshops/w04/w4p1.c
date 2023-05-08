/*
*****************************************************************************
                          Workshop - #4 (P1)
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

#include<stdio.h>

int main() 
{
	int iterations = 0
		, iterator = 0;
	char type = '0';

	printf("+----------------------+\n");
	printf("Loop application STARTED\n");
	printf("+----------------------+\n\n");

	while (1)
	{
		printf("D = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &type, &iterations);

		if ((iterations < 3 || iterations>20) && (type == 'D' || type == 'F' || type == 'W'))
		{
			printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
			continue;
		}

		if (type == 'D')
		{
			printf("DO-WHILE: ");
			do {
				printf("D");
				iterator++;
			} while (iterator < iterations);
		}
		else if (type == 'W')
		{
			printf("WHILE   : ");
			while (iterator < iterations)
			{
				printf("W");
				iterator++;
			}
		}
		else if (type == 'F')
		{
			printf("FOR     : ");
			for (;iterator < iterations;iterator++)
			{
				printf("F");
			}
		}
		else if (type == 'Q' )
		{
			//does nothing and breaks out of the loop
			if (iterations != 0)
			{
				printf("ERROR: To quit, the number of iterations should be 0!\n\n");
				continue;
			}
			printf("\n");
			break;
		}
		else
			printf("ERROR: Invalid entered value(s)!");

		

		iterator = 0;
		printf("\n\n");
	}

	printf("+--------------------+\n");
	printf("Loop application ENDED\n");
	printf("+--------------------+\n");


	return 0;
}