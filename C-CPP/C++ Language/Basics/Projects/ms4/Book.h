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
#ifndef BOOK_H_
#define BOOK_H_

#include"Publication.h"
//#include"Utils.h"
#include"Lib.h"


namespace sdds{
    class Book:public Publication{
        char* authorName;

        public:
        Book();
        Book(const Book& B);
        Book& operator=(const Book& B);
        ~Book();

        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        void set(int memId);
        operator bool();
    };
}
#endif