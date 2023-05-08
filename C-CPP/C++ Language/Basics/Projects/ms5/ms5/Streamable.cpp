/*
*****************************************************************************
						Milestone 4
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Streamable.h"
using namespace std;
namespace sdds{
   Streamable::~Streamable(){};
   std::ostream& operator<<(std::ostream& os, const Streamable& RO){
      return RO.write(os);
   }
   std::istream& operator>>(std::istream& is, Streamable& RO){
      return RO.read(is);
   }
   
}