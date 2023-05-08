/*
*****************************************************************************
						Workshop 4 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include<iostream>
#include "Reservation.h"

namespace sdds{
    class Restaurant{
        private:
        Reservation** m_ptrArr{};
        size_t m_size;
        public:
        Restaurant();
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& r);
        Restaurant(Restaurant&& r);
        Restaurant& operator=(const Restaurant& r);
        Restaurant& operator=(Restaurant&& r);
        size_t size();
        friend std::ostream& operator<<(std::ostream& os, Restaurant r);
        ~Restaurant();
    };
}

#endif