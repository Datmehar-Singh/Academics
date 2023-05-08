/*
*****************************************************************************
						Workshop 8 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include"Account.h"

namespace sdds{
        Account::Account(double amt)
	{
            this->currBalance=(amt<=0)?0:amt;
        }
	double Account::balance() const {
            return currBalance;
        }
}