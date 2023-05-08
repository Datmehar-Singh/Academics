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

#include <iostream>
using namespace std;
namespace sdds {
    class Streamable {
      public:
      virtual bool conIO(std::ios& is) const=0;
      virtual std::ostream& write(std::ostream& os) const=0 ;
      virtual std::istream& read(std::istream& is)=0 ;
      virtual operator bool() const=0;
      virtual ~Streamable(); // virtual destructor
    };
    std::ostream& operator<<(std::ostream& os, const Streamable& RO);
    std::istream& operator>>(std::istream& is, Streamable& RO);
}




