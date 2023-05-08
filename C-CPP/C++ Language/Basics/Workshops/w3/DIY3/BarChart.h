/*
*****************************************************************************
						Workshop 3 - Part 2
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 6 May 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include "Bar.h"

namespace sdds {
class BarChart {
  char *title;
  Bar *arrayOfBars;
  int sizeOfArray;
  int added;
	char fillChar;

public:
bool areAllValid() const;

void init(const char* title, int noOfSamples, char fill);
void add(const char* bar_title, int value);
void draw()const;
void deallocate();
};



} // namespace sdds