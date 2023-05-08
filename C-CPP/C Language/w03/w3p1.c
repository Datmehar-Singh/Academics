/*
*****************************************************************************
                          Workshop - #3 (P1)
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
	const double tax = 0.13;
   	const char patSize = 'S';

	float smallShirtPrice = 0.0,
		mediumShirtPrice=0.0,
		largeShirtPrice=0.0;
	int noOfShirts = 0;


	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%f", &smallShirtPrice);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%f", &mediumShirtPrice);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%f", &largeShirtPrice);

	printf("\nShirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2f\n" , smallShirtPrice);
	printf("MEDIUM : $%.2f\n", mediumShirtPrice);
	printf("LARGE  : $%.2f\n\n", largeShirtPrice);
	
	

	printf("Patty's shirt size is '%c'\n",patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &noOfShirts);

	printf("\nPatty's shopping cart...\n");
	printf("Contains : %d shirts\n",noOfShirts);

    int intPrice=(int) (noOfShirts * smallShirtPrice*1000);
    int decision=(intPrice%10)>=5?1:0;
    intPrice/=10;
    intPrice+=decision;
	double totalPrice = (double)intPrice/100+(intPrice%100)/100;
	printf("Sub-total: $%8.4lf\n",totalPrice);
	
	int intTax=tax * totalPrice*1000;
	decision=(intTax%10)>=5?1:0;
	intTax/=10;
	intTax+=decision;
	double totalTax=(double)intTax/100+(intTax%100)/100;
	
	printf("Taxes    : $%8.4lf\n",totalTax);
	printf("Total    : $%8.4lf\n", totalPrice+totalTax);

	return 0;
}

