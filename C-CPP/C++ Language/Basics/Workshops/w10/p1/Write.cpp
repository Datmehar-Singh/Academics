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
// Write.cpp
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
#include <iostream>
#include "Write.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }
}