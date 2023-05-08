/*
*****************************************************************************
						Workshop 10 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
// Workshop 10:
// Card.h
// 2022-02-19
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#include <iostream>
#ifndef SDDS_CARD_H_
#define SDDS_CARD_H_
#include "Write.h"
namespace sdds {
    class Card : public ReadWrite {
        char m_suit[10];
        int m_value;
    public:
        Card(const char* suit = "", const int value= 0);
        void set(const char* suit, const int value);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const char* mmSubstr)const;
        bool operator==(const int mmVal)const;
    };
    std::ostream& operator<<(std::ostream& os, const Card& card);
}
#endif // !SDDS_CARD_H_
