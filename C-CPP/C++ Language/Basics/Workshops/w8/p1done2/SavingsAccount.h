/*
*****************************************************************************
						Workshop 8 - Part 1
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 21 july 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include "Account.h"
#include<iomanip>

namespace sdds{
    class SavingsAccount : public Account{
        private:
        double interestRate;
        public:
        SavingsAccount(double balance, double interest);
        void monthEnd();
        void display(std::ostream& os) const;
    };
}