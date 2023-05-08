/*
*****************************************************************************
						Workshop 6 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef _BASKET_H
#define _BASKET_H

#include<iostream>


namespace sdds{
    struct Fruit
    {
    char m_name[30 + 1]; // the name of the fruit
    double m_qty;        // quantity in kilograms
    };
    class Basket{
        private:
        Fruit* m_fruits;//pointer for array of fruits
        int m_cnt;//count of fruits in the array
        double m_price;
    
        public:
        Basket();
        Basket(Fruit*, int, double);
        Basket(const Basket&);

        Basket operator=(Basket);

        ~Basket();

        void setPrice(double);
        operator bool();
        Basket& operator+=(Fruit);

        friend std::ostream& operator<<(std::ostream&,Basket);


    };
}
#endif