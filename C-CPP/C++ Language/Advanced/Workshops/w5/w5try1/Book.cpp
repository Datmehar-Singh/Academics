/*
*****************************************************************************
						Workshop 5 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Book.h"

namespace sdds
{

    void trim(std::string &str)
    {
        if (str.find_last_not_of(' ') == str.find_first_not_of(' '))
            return;
        std::string res = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
        str = res;
    }

    Book::Book()
    {
        m_author = "";
        m_title = "";
        m_country = "";
        m_description = "";
        m_year = 0;
        m_price = 0.0;
    }
    Book::Book(const std::string &strBook)
    {
        std::string str=strBook,
            temp="";
        trim(str);

        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_author=temp;
        
        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_title=temp;
        
        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_country=temp;
        
        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_price=stod(temp);
        
        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_year=stoi(temp);

        
        // temp=str.substr(0,str.find(','));
        trim(str);
        m_description=str;
        //std::cout<<"lvl1book";
        
    }
    const std::string &Book::title() const { return m_title;}
    const std::string &Book::country() const {return m_country;}
    const size_t &Book::year() const {return m_year;}
    double &Book::price() {return m_price;}
    std::ostream &operator<<(std::ostream &os, Book b) {
        os<<std::right<<std::setw(20)<<b.m_author;
        os<<" | "<<std::right<<std::setw(22)<<b.m_title;
        os<<" | "<<std::right<<std::setw(5)<<b.m_country;
        os<<" | "<<std::right<<std::setw(4)<<b.m_year;
        os<<" | "<<std::right<<std::setw(6)<<std::fixed<<std::setprecision(2)<<b.m_price;
        os<<" | "<<b.m_description;
        return os;
    }

}