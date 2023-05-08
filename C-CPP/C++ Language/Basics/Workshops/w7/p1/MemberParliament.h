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


#ifndef _MEMBER__PARLIAMENT_H
#define _MEMBER__PARLIAMENT_H

#include<iostream>
#include<cstring>
namespace sdds{
        class MemberParliament{
        private:
        char m_Id[32];
        char m_district[64];
        int m_age;

        public:
        MemberParliament(const char* ids, int age);
		MemberParliament(const MemberParliament& M);
        void NewDistrict(const char* district);
        std::ostream& write(std::ostream& os);
        std::istream& read(std::istream& in);
        friend std::ostream& operator<<(std::ostream& os,MemberParliament M);

		char* getId(){return m_Id;}
		char* getDistrict(){return m_district;}
		int getAge(){return m_age;}

		void setId(char* id){strcpy(m_Id,id);}
		void setDistrict(char* district){strcpy(m_district,district);}
		void setAge(int age){m_age=age;}
        friend std::istream& operator>>(std::istream& istr, MemberParliament& M);
    };
}
#endif
