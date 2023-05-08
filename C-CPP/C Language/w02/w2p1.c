/*
*****************************************************************************
                          Workshop - #2 (P1)
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
#include<stdbool.h>

int main(void)
{
    float proPriceOne = 111.4900,
        proPriceTwo = 222.9900,
        proPriceThree = 334.4900;
    int id1 = 111,
        id2 = 222,
        id3 = 111;
    char taxed1 = 'Y',
        taxed2 = 'N',
        taxed3 = 'N';
    const double testValue=330.99;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", id1);
    printf("  Taxed: %c\n", taxed1);
    printf("  Price: $%.4f\n\n", proPriceOne);
    printf("Product-2 (ID:%d)\n", id2);
    printf("  Taxed: %c\n", taxed2);
    printf("  Price: $%.4f\n\n", proPriceTwo);
    printf("Product-3 (ID:%d)\n", id3);
    printf("  Taxed: %c\n", taxed3);
    printf("  Price: $%.4f\n\n", proPriceThree);

    float avg = (proPriceOne + proPriceTwo + proPriceThree) / 3;
    printf("The average of all prices is: $%.4f\n\n", avg);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", taxed1=='Y'?1:0);
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (taxed2=='N'&&taxed3=='N')?1:0);
    printf("3. Is product 3 less than testValue ($%.2f)? -> %d\n\n", testValue, proPriceThree<testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", (proPriceThree>proPriceTwo+proPriceOne)?1:0);
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n\n", proPriceOne>=(proPriceThree-proPriceTwo),  (proPriceThree - proPriceTwo));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", proPriceTwo>=avg);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", (id1!=id2 && id1!=id3)?1:0);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (id2!=id1 && id2!=id3)?1:0);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", (id3!=id1 && id3!=id2)?1:0);

    return 0;
}