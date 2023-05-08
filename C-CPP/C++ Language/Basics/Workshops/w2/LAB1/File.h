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


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

#include<stdio.h>
#include<stdlib.h>

namespace sdds
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
  

   /*******Read function and its overloaded forms*******/

   //returns the name of the function by reference
   bool read(char* name);

   //returns the student number by refernce
   bool read(int* stuNum);

   //returns the grade by reference
   bool read(char& grade);

   



}
#endif // !SDDS_FILE_H_
