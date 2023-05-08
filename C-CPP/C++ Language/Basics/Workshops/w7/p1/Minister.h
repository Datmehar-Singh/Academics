/*
*****************************************************************************
						Workshop 7 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef _MINISTER_H
#define _MINISTER_H


#include "MemberParliament.h"

namespace sdds{
class Minister:public MemberParliament{
        private:
        char m_name[50];
        int m_year;

        public:
        Minister(const char* id, int age, int year, const char* name,const char* district);
        void changePM(const char* pm);
        void assumeOffice(double year);
        std::ostream& write(std::ostream& os);
        std::istream& read(std::istream& in);
        friend std::ostream& operator<<(std::ostream& os,Minister& M);
        friend std::istream& operator>>(std::istream& istr, Minister& M);
    
    };
}
#endif