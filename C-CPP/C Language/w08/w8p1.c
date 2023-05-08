/*
*****************************************************************************
                                  Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>
#include <stdlib.h>

// User Libraries
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *intNum)
{
	int num = 0;

	while (num < 1)
	{
		scanf("%d", &num);
		if (num < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	}

	if (intNum)//changes the value of pointer only when nullptr is not passed
		*intNum = num;

	return num;
}


// 2. Get user input of double type and validate for a positive non-zero number
double getDoublePositive(double *doubleNum)
{
	double num = 0;

	while (num <= 0)
	{
		scanf("%lf", &num);

		if (num <= 0)
			printf("ERROR: Enter a positive value: ");
	}
	if (doubleNum)
		*doubleNum = num;

	return num;
}


//    (return the number while also assigning it to the pointer argument)
// 3. Opening Message (include the number of products that need entering)
void openingMessage()
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", NO_OF_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_PER_SERVING);
	
	return;
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numOfProduct)
{
	int sku = -1, 
		calPerServe = -1;

	double price = 0.0, 
		weight = 0.0,
		temp=0;

	struct CatFoodInfo c1 = {sku, price, calPerServe, weight};

	
	printf("\nCat Food Product #%d\n", numOfProduct + 1);
	printf("--------------------\n");

	printf("SKU           : ");
	sku = getIntPositive(NULL);
	c1.skuNumber=sku;
	
	printf("PRICE         : $");
	price = getDoublePositive(NULL);
	c1.price=price;
	
	
	printf("WEIGHT (LBS)  : ");
	temp  = getDoublePositive(&weight);
	if(temp!=weight)
	{
		return c1;
	}else{
	c1.weight=weight;
	}

	
	printf("CALORIES/SERV.: ");
	temp = getIntPositive(&calPerServe);
	if(temp!=calPerServe)
	{
		return c1;
	}else{
	c1.calPerServing=calPerServe;
	}

	

	return c1;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, 
						double *const price, 
						const int calPerServing, 
						double *const weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calPerServing);

	return;
}


// 7. Logic entry point
void start(void)
{
	int counter = -1;
	struct CatFoodInfo arrOfInfo[NO_OF_PRODUCTS];

	openingMessage();

	while (++counter < NO_OF_PRODUCTS)
	{
		arrOfInfo[counter] = getCatFoodInfo(counter);
	}

	displayCatFoodHeader();

	for (counter = 0; counter < NO_OF_PRODUCTS; counter++)
	{
		displayCatFoodData(arrOfInfo[counter].skuNumber, 
							&arrOfInfo[counter].price, 
							arrOfInfo[counter].calPerServing, 
							&arrOfInfo[counter].weight);
	}

	return;
}
