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


#include "Minister.h"

namespace sdds{
 Minister::Minister(const char* id, int age, int year, const char* name, const char* District):MemberParliament(id,age){
            m_year=year;
            strcpy(m_name,name);
	 		NewDistrict(District);
        }
        void Minister::changePM(const char* pm){
            strcpy(m_name,pm);
        }
        void Minister::assumeOffice(double year){
            m_year=year;
        }
        std::ostream& Minister::write(std::ostream& os){
            os<<"| "<<getId()<<" | "<<getAge()<<" | "<<getDistrict()<<" | "<<m_name<<"/"<<m_year;
			return os;
        }
        std::istream& Minister::read(std::istream& in){
			int age;
			char Id[32],district[64];
            std::cout<<"Age: ";
            in>>age;
            std::cout<<"Id: ";
            in>>Id;
            std::cout<<"District: ";
            in>>district;
			setAge(age);
			setId(Id);
			setDistrict(district);
            std::cout<<"Reports TO: ";
            in>>m_name;
            std::cout<<"Year Assumed Office: ";
            in>>m_year;
			return in;
        }
        std::ostream& operator<<(std::ostream& os,Minister& M){
            return M.write(os);
        }
        std::istream& operator>>(std::istream& istr, Minister& M){
            return M.read(istr);
        }
}