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
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
#include<iomanip>
#include"SpellChecker.h"

namespace sdds{
    class Book {
        std::string m_author, m_title, m_country, m_description;
        size_t m_year;
        double m_price;
        public:
        Book();
        Book(const std::string& strBook);
        Book(const Book& b)
        {
            m_author=b.m_author;
             m_title=b.m_title;
              m_country=b.m_country;
               m_description=b.m_description;
            m_year=b.m_year;
            m_price=b.m_price;
            
        }
        Book operator=(const Book& b)
        {
            m_author=b.m_author;
             m_title=b.m_title;
              m_country=b.m_country;
               m_description=b.m_description;
            m_year=b.m_year;
            m_price=b.m_price;
            return *this;
        }
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        friend std::ostream& operator<<(std::ostream& os, Book b);

        template<class T>
        void fixSpelling(T& spellChecker){
            spellChecker(m_description);
        }
    };
}
#endif