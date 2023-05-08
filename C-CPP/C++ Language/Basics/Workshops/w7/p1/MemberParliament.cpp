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



#include "MemberParliament.h"
#include<iomanip>
#include<iostream>

namespace sdds{
    MemberParliament::MemberParliament(const char* id, int age){
        strcpy(m_Id,id);
        strcpy(m_district,"Unassigned");
        m_age=age;
    }
        
        void MemberParliament::NewDistrict(const char* district){
            std::cout<<"|"<<std::setw(8)<<std::right<<m_Id<<"| |"<<std::setw(20)<<std::right<<m_district<<" ---> "<<std::setw(23)<<std::left<<district;
            std::cout<<"|\n";
            strcpy(m_district,district);
        }
        MemberParliament::MemberParliament(const MemberParliament& M)
{
	strcpy(this->m_Id,M.m_Id);
	strcpy(this->m_district,M.m_district);
	m_age=M.m_age;
}
        std::ostream& MemberParliament::write(std::ostream& os){
            os<<"| "<<m_Id<<" | "<<m_age<<" | "<<m_district;
            return os;
        }
        
        std::istream& MemberParliament::read(std::istream& in){
            std::cout<<"Age: ";
            in>>m_age;
            std::cout<<"Id: ";
            in>>m_Id;
            std::cout<<"District: ";
            in>>m_district;
			return in;
        }
        
        std::ostream& operator<<(std::ostream& os,MemberParliament M){
           return M.write(os);
        }
        
        std::istream& operator>>(std::istream& istr, MemberParliament& M){
            return M.read(istr);
        }
}