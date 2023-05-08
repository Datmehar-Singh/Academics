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
#include "Movie.h"

namespace sdds
{
    void trimStr(std::string &str)
    {
        if (str.find_last_not_of(' ') == str.find_first_not_of(' '))
            return;
        std::string res = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
        str = res;
    }
    Movie::Movie()
    {
        m_description = "";
        m_title = "";
        m_yearOfRel = 0;
    }
    const std::string &Movie::title() const { return m_title; }
    Movie::Movie(const std::string &strMovie)
    {
        std::string str = strMovie,
                    temp = "";
        trimStr(str);

        temp = str.substr(0, str.find(','));
        str = str.substr(str.find(',') + 1);
        trimStr(temp);
        m_title = temp;

        temp = str.substr(0, str.find(','));
        str = str.substr(str.find(',') + 1);
        trimStr(temp);
        //std::cout<<"\n++++"<<temp<<"______\n";
        m_yearOfRel = stoi(temp);

        trimStr(str);
        m_description = str;
    }

    

    std::ostream &operator<<(std::ostream &os, Movie m){
        os<<std::right<<std::setw(40)<<m.m_title;
        os<<" | "  <<std::right<<std::setw(4)<<m.m_yearOfRel;
        os<<" | "<<m.m_description;
        return os;
    }
}