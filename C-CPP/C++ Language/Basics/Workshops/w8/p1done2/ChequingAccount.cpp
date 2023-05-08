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


#include"ChequingAccount.h"

namespace sdds{
ChequingAccount::ChequingAccount(double accBalance, const double transFee,const double monthlyFee): Account(accBalance)
	{
            transactionFee=(transFee>0.0)?transFee:0.0;
            this->monthlyFee=(monthlyFee>0.0)?monthlyFee:0.0;
        }

        bool ChequingAccount::credit(double cr)
        {
            bool res=Account::credit(cr-transactionFee);
            if(this->balance()>transactionFee)
            {
                return res && true;
            }
            else return res && false;
        }
        bool ChequingAccount::debit(double deb)
        {
            bool res=Account::debit(deb+transactionFee);

            if(this->balance()>transactionFee)
            {
                return res && true;
            }
            else return res && false;
        }

        void ChequingAccount::monthEnd()
        {
            this->Account::debit(monthlyFee);
        }
        void ChequingAccount::display(std::ostream& os) const
        {
            os<<"Account type: Chequing"<<"\n";
            os<<"Balance: $"<<std::fixed<<std::setprecision(2)<<this->balance()<<"\n";
            os<<"Per Transaction Fee: "<<std::fixed<<std::setprecision(2)<<transactionFee<<"\n";
            os<<"Monthly Fee: "<<std::fixed<<std::setprecision(2)<<this->monthlyFee<<"\n";
        }

}