/*
*****************************************************************************
						  Workshop - #8 (P2)
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

// User Libraries
#include "w8p2.h"

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

	if (intNum) // changes the value of pointer only when nullptr is not passed
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
		   temp = 0;

	struct CatFoodInfo c1 = {sku, price, calPerServe, weight};

	printf("\nCat Food Product #%d\n", numOfProduct + 1);
	printf("--------------------\n");

	printf("SKU           : ");
	sku = getIntPositive(NULL);
	c1.skuNumber = sku;

	printf("PRICE         : $");
	price = getDoublePositive(NULL);
	c1.price = price;

	printf("WEIGHT (LBS)  : ");
	temp = getDoublePositive(&weight);
	if (temp != weight)
	{
		return c1;
	}
	else
	{
		c1.weight = weight;
	}

	printf("CALORIES/SERV.: ");
	temp = getIntPositive(&calPerServe);
	if (temp != calPerServe)
	{
		return c1;
	}
	else
	{
		c1.calPerServing = calPerServe;
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
void displayCatFoodData(const int sku,double *const price,
					const int calPerServing,
					double *const weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calPerServing);

	return;
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double *const weightLbs, double *weightKgs)
{
	if (weightKgs)
		*weightKgs =  (*weightLbs)/LBS_TO_KGS ;

	return (*weightLbs)/LBS_TO_KGS ;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(double *const weightLbs, int *weightG)
{
	if (weightG)
		*weightG = (int)(1000 * (*weightLbs) / LBS_TO_KGS);

	return (int)(1000 * (*weightLbs) /LBS_TO_KGS);
}

// 10. convert lbs: kg and g
void convertLbs(double *const weightLbs, double *weightKg, int *weightG)
{
	int temp = 0;
	if (weightKg && weightG)
	{
		*weightKg = convertLbsKg(weightLbs, NULL);
		temp = convertLbsG(weightLbs, weightG);
	}

	if (temp != *weightG)
	{
		printf("\n\n !***Conversion function for lbs to grams not working***!\n\n");
		return;
	}
	return;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *res)
{
	if (res)
		*res = (double)totalGrams / servingSizeGrams;

	return *res = (double)totalGrams / servingSizeGrams;
}

// 12. calculate: cost per serving
double calculateCostPerServing(double *const price, double *const totalServings, double *costPerServing)
{
	if (costPerServing)
		*costPerServing = *price / *totalServings;

	return *price / *totalServings;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(double *const pricePerServe, int *const caloriesPerServe, double *costPerCalorie)
{
	if (costPerCalorie)
		*costPerCalorie = *pricePerServe / *caloriesPerServe;

	// printf("\n%lf   %lf  %lf\n",*pricePerServe ,	 *caloriesPerServe,*pricePerServe / *caloriesPerServe);

	return *pricePerServe / *caloriesPerServe;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo data)
{
	struct ReportData r1 = {0};
	double temp = 0;

	r1.skuNumber = data.skuNumber;
	r1.price = data.price;
	r1.calPerServe = data.calPerServing;
	r1.weightInLbs = data.weight;

	// calling the functions
	r1.weightInKgs = convertLbsKg(&(r1.weightInLbs), NULL);
	temp = convertLbsG(&(r1.weightInLbs), &(r1.weightInGrams));
	if (temp != r1.weightInGrams)
	{
		printf("\n\n !***Conversion function for lbs to grams not working***!\n\n");
		return r1;
	}

	temp = calculateServings(GRAMS_PER_SERVING, r1.weightInGrams, &(r1.totalServings));
	if (temp != r1.totalServings)
	{
		printf("\n\n !***servings function not working***!\n\n");
		return r1;
	}

	temp = calculateCostPerServing(&(r1.price), &(r1.totalServings), &(r1.costPerServing));
	if (temp != r1.costPerServing)
	{
		printf("\n\n !***cost per serving not working***!\n\n");
		//return r1;
	}

	r1.calCostPerServe = calculateCostPerCal(&(r1.costPerServing), &(r1.calPerServe), NULL);
	return r1;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", GRAMS_PER_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
	return;
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int isCheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data.skuNumber, data.price, data.weightInLbs, data.weightInKgs, data.weightInGrams, data.calPerServe, data.totalServings, data.costPerServing, data.calCostPerServe);

	if (isCheapest)
		printf(" ***");

	printf("\n");
	return;
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo const cheapestData)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n\n", cheapestData.skuNumber, cheapestData.price);
	printf("Happy shopping!\n");
return;
}

int cheapestIndexReturn(struct CatFoodInfo arr[])
{
	int i,min=-100000;
	for( i=0;i<NO_OF_PRODUCTS;i++)
	{
		if(arr[i].price>arr[min].price)
			min=i;
	}
	return min;
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int counter = -1,cheapestCounter;
	struct CatFoodInfo arrOfInfo[NO_OF_PRODUCTS];
	struct ReportData arrayOfReports[NO_OF_PRODUCTS];

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

	displayReportHeader();

	cheapestCounter=cheapestIndexReturn(arrOfInfo);

	for (counter = 0; counter < NO_OF_PRODUCTS; counter++)
	{
		arrayOfReports[counter]=calculateReportData(arrOfInfo[counter]);

		if(counter==cheapestCounter)
			displayReportData(arrayOfReports[counter],1);
		else
			displayReportData(arrayOfReports[counter],0);
	}
	displayFinalAnalysis(arrOfInfo[cheapestCounter]);

	

	return;
}