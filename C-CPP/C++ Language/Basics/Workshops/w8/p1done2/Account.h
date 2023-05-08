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


#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include "iAccount.h"
namespace  sdds{
	class Account :public iAccount
	{
	private:
		double currBalance;
	
	public:
		Account(double amt);
virtual bool credit(double creditAmount)
        {
            currBalance+=creditAmount;
	return true;
        }
virtual bool debit(double debitAmount)
	{
            currBalance-=debitAmount;
	return true;
        }
	        virtual void monthEnd()=0;
		virtual void display(std::ostream&) const =0;
	protected:
		double balance() const;
	};
}
#endif