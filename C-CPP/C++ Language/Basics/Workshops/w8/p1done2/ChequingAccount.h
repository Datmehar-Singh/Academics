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
    class ChequingAccount:public Account{
        private:
        double transactionFee;
        double monthlyFee;

        public:
        ChequingAccount(double accBalance, const double transFee,const double monthlyFee);
        bool credit(double cr);
        bool debit(double deb);
        void monthEnd();
        void display(std::ostream& os) const;
    };
}