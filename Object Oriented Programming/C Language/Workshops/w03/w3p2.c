/*
*****************************************************************************
						  Workshop - #3 (P2)
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
#include<stdlib.h>

int main()
{
	const double TAX = 0.13;
	const char patSize = 'S',
		salSize = 'M',
		tomSize = 'L';

	float smallShirtPrice = 0.0,
		mediumShirtPrice = 0.0,
		largeShirtPrice = 0.0;
	int noOfShirtsPatty = 0,
		noOfShirtsSally = 0,
		noOfShirtsTommy = 0;




	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%f", &smallShirtPrice)?1:exit(101);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%f", &mediumShirtPrice)?1:exit(101);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%f", &largeShirtPrice)?1:exit(101);

	printf("\nShirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2f\n", smallShirtPrice);
	printf("MEDIUM : $%.2f\n", mediumShirtPrice);
	printf("LARGE  : $%.2f\n\n", largeShirtPrice);



	printf("Patty's shirt size is '%c'\n", patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &noOfShirtsPatty)?1:exit(101);
	printf("\nTommy's shirt size is '%c'\n", tomSize);
	printf("Number of shirts Tommy is buying: ");
	scanf("%d", &noOfShirtsTommy)?1:exit(101);
	printf("\nSally's shirt size is '%c'\n", salSize);
	printf("Number of shirts Sally is buying: ");
	scanf("%d", &noOfShirtsSally)?1:exit(101);



	int intsubTotalPatty = (int)(noOfShirtsPatty * smallShirtPrice * 1000);
	int decision = (intsubTotalPatty % 10) >= 5 ? 1 : 0;
	intsubTotalPatty /= 10;
	intsubTotalPatty += decision;
	double totalPricePatty = (double)intsubTotalPatty / 100 + (intsubTotalPatty % 100) / 100;

	int intsubTotalSally = (int)(noOfShirtsSally * mediumShirtPrice * 1000);
	decision = (intsubTotalSally % 10) >= 5 ? 1 : 0;
	intsubTotalSally /= 10;
	intsubTotalSally += decision;
	double totalPriceSally = (double)intsubTotalSally / 100 + (intsubTotalSally % 100) / 100;

	int intsubTotaltommy = (int)(noOfShirtsTommy * (tomSize == 'L' ? largeShirtPrice : (tomSize == 'M' ? mediumShirtPrice : (tomSize == 'S' ? smallShirtPrice : 0))) * 1000);
	decision = (intsubTotaltommy % 10) >= 5 ? 1 : 0;
	intsubTotaltommy /= 10;
	intsubTotaltommy += decision;
	double totalPriceTommy = (double)intsubTotaltommy / 100 + (intsubTotaltommy % 100) / 100;



	//rounding of the tax numbers for the three customers

	int intTaxPatty = TAX * totalPricePatty * 1000;
	decision = (intTaxPatty % 10) >= 5 ? 1 : 0;
	intTaxPatty /= 10;
	intTaxPatty += decision;
	double totalTaxPatty = (double)intTaxPatty / 100 + (intTaxPatty % 100) / 100;

	int intTaxSally = TAX * totalPriceSally * 1000;
	decision = (intTaxSally % 10) >= 5 ? 1 : 0;
	intTaxSally /= 10;
	intTaxSally += decision;
	double totalTaxSally = (double)intTaxSally / 100 + (intTaxSally % 100) / 100;

	int intTaxTommy = TAX * totalPriceTommy * 1000;
	decision = (intTaxTommy % 10) >= 5 ? 1 : 0;
	intTaxTommy /= 10;
	intTaxTommy += decision;
	double totalTaxTommy = (double)intTaxTommy / 100 + (intTaxTommy % 100) / 100;

	printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");


	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, (patSize == 'L' ? largeShirtPrice : (patSize == 'M' ? mediumShirtPrice : (patSize == 'S' ? smallShirtPrice : 0))), noOfShirtsPatty, totalPricePatty, totalTaxPatty, totalPricePatty + totalTaxPatty);
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, (salSize == 'L' ? largeShirtPrice : (salSize == 'M' ? mediumShirtPrice : (salSize == 'S' ? smallShirtPrice : 0))), noOfShirtsSally, totalPriceSally, totalTaxSally, totalPriceSally + totalTaxSally);
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, (tomSize == 'L' ? largeShirtPrice : (tomSize == 'M' ? mediumShirtPrice : (tomSize == 'S' ? smallShirtPrice : 0))), noOfShirtsTommy, totalPriceTommy, totalTaxTommy, totalPriceTommy + totalTaxTommy);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	printf("%33.4lf %9.4lf %9.4lf\n\n", totalPricePatty + totalPriceSally + totalPriceTommy, totalTaxPatty + totalTaxSally + totalTaxTommy, totalPricePatty + totalPriceSally + totalPriceTommy + totalTaxPatty + totalTaxSally + totalTaxTommy);
	double totalPriceWithoutTax = totalPricePatty + totalPriceSally + totalPriceTommy;
	int afterDec = (int)(totalPriceWithoutTax * 100) % 100;



	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n\n");

	int copyOfPriceWithoutTax = (int)totalPriceWithoutTax;

	int afterDecCopy = afterDec;
	int toonies = copyOfPriceWithoutTax / 2; copyOfPriceWithoutTax %= 2;
	int loonies = copyOfPriceWithoutTax;
	int quarter = afterDecCopy / 25;
	afterDecCopy %= 25;
	int dimes = afterDecCopy / 10;
	afterDecCopy %= 10;
	int nickels = (afterDecCopy / 5);
	afterDecCopy %= 5;
	int pennies = afterDecCopy;


	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("%22.4lf\n", totalPriceWithoutTax);
	printf("Toonies  %3d %9.4lf\n", toonies, totalPriceWithoutTax - toonies * 2);
	printf("Loonies  %3d %9.4lf\n", loonies, totalPriceWithoutTax - toonies * 2 - loonies * 1);
	printf("Quarters %3d %9.4lf\n", quarter, ((double)(afterDec - 25 * quarter) / 100));
	printf("Dimes    %3d %9.4lf\n", dimes, ((double)(afterDec - quarter * 25 - dimes * 10) / 100));
	printf("Nickels  %3d %9.4lf\n", nickels, ((double)(afterDec - quarter * 25 - dimes * 10 - nickels * 5) / 100));
	printf("Pennies  %3d %9.4lf\n", pennies, ((double)(afterDec - quarter * 25 - dimes * 10 - nickels * 5 - pennies) / 100));

	printf("\nAverage cost/shirt: $%.4lf\n\n", totalPriceWithoutTax / 13);
	printf("Sales INCLUDING tax\n");
	double totalPriceWithTax = totalPriceWithoutTax + totalTaxPatty + totalTaxSally + totalTaxTommy;

	int copyOfPriceWithTax = (int)totalPriceWithTax;

	 afterDec = ((int)(totalPriceWithTax * 10000)%100==99?(int)(totalPriceWithTax * 100)%100+1:(int)(totalPriceWithTax * 100)%100) ;//% 100
	 afterDecCopy = afterDec;
	 toonies = copyOfPriceWithTax / 2; 
	 copyOfPriceWithTax %= 2;
	 loonies = copyOfPriceWithTax;
	 quarter = afterDecCopy / 25;
	 afterDecCopy %= 25;
	 dimes = afterDecCopy/10;
	 afterDecCopy %= 10;
	 nickels = (afterDecCopy /5);
	 afterDecCopy %= 5;
	 pennies = afterDecCopy;



	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	printf("%22.4lf\n", totalPriceWithTax);
	printf("Toonies  %3d %9.4lf\n", toonies, totalPriceWithTax - toonies * 2);
	printf("Loonies  %3d %9.4lf\n", loonies, totalPriceWithTax - toonies * 2 - loonies * 1);
	printf("Quarters %3d %9.4lf\n", quarter, ((double)(afterDec - 25 * quarter) / 100));
	printf("Dimes    %3d %9.4lf\n", dimes, ((double)(afterDec - quarter * 25 - dimes * 10) / 100));
	printf("Nickels  %3d %9.4lf\n", nickels, ((double)(afterDec - quarter * 25 - dimes * 10 - nickels * 5) / 100));
	printf("Pennies  %3d %9.4lf\n", pennies, ((double)(afterDec - quarter * 25 - dimes * 10 - nickels * 5 - pennies) / 100));

	printf("\nAverage cost/shirt: $%.4lf\n", totalPriceWithTax/13);

		return 0;
}

