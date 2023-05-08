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
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
namespace sdds{
    class SpellChecker{
        std::string m_badWords[6];
        std::string m_goodWords[6];
        int m_counterForReplaces[6]{};
        public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;

    };
}

#endif