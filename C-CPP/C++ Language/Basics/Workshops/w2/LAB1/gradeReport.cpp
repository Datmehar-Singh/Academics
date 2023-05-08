/*
*****************************************************************************
						Workshop 2 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Student.h"
using namespace sdds;

int main() {
	
   char fileName[20]="students.csv";
	
   if (load(fileName)) {
      display();
   }
   deallocateMemory();
   return 0;
}