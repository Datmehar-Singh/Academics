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


#include <iostream>
#include <iomanip>

namespace sdds
{
	class iAccount
	{
		public:
			virtual bool credit(double)=0;
			virtual bool debit(double)=0;
			virtual void monthEnd()=0;
			virtual void display(std::ostream&) const =0;
			virtual ~iAccount(){}
	};
iAccount* CreateAccount(const char*,double);
}