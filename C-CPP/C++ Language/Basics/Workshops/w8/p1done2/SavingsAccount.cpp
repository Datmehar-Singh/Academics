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


#include"SavingsAccount.h"

namespace sdds{
        SavingsAccount::SavingsAccount(double balance, double interest):Account(balance)
        {
            this->interestRate=(interest<=0)?0.0:interest;
        }
        void SavingsAccount::monthEnd()
        {
            double intAmt=this->balance()*this->interestRate;
            this->credit(intAmt);
            return;
        }
        void SavingsAccount::display(std::ostream& os) const
        {
            os<<"Account type: Savings"<<"\n";
            os<<"Balance: $"<<std::fixed<<std::setprecision(2)<<this->balance()<<"\n";
            os<<"Interest Rate (%): "<<std::fixed<<std::setprecision(2)<<this->interestRate*100.0<<"\n";
        }
}