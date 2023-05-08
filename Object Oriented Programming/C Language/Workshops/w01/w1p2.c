/*****************************************************************************
							 Workshop - #1 part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#include<stdio.h>

int main()//execution starts
{
	printf("Workshop 1 Part-2\n");//printf prints the line the string under the quotes
	printf("=================\n\n");
	printf("Using tab specifiers...\n");

	printf("\tTab-1\tTab-2\tTab-3\n");
	printf("\t-----\t=====\t-----\n\n");

	printf("\\ this is a back-slash character!\n");//backslash cannot be printed simply by writing it as it symbolises the escape sequences so double backslash works
	printf("%% this is a percent sign character!\n");//% sign needs to be written two times in order to be printed 
	printf("\" this is a double-quote character!\n\n");//since a quote sign is the indicator of end of a string so it cannot be printed simply and needs an escape sequence which is /"
	printf("My favourite quotes are:\n");
	printf("1.\t\"Skill is only developed by hours and hours of work.\"\n");// \t=tab pressed once
	printf("\t\t\t\t\t\t-Usain Bolt\n\n");
	printf("2.\t\"It's not about having time. It's about making time.\"\n");
	printf("\t\t\t\t\t\t-unknown\n\n");
	printf("3.\t\"All of us do not have equal talent. But, all of us\n");
	printf("\thave an equal opportunity to develop our talents.\"\n");
	printf("\t\t\t\t\t\t-A.P.J. Abdul Kalam\n\n");
return 0;
}//execution ends