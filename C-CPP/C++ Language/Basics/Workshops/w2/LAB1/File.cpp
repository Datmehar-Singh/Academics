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


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include "File.h"

namespace sdds 
{
   FILE* fptr=nullptr;
   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() 
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) 
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() 
   {
      if (fptr) fclose(fptr);
   }

   bool read(char* name)
   {
      return fscanf(fptr, "%[^,],",name);
   }

   bool read(int* stuNum)
   {
      return fscanf(fptr, "%d,",stuNum);
   }

	bool read(char& ch)
   {
      return fscanf(fptr, "%c\n",&ch);
	   
   }

   
}