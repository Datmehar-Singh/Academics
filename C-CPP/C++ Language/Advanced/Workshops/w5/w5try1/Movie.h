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
#ifndef MOVIE_H_
#define MOVIE_H_

#include "SpellChecker.h"

namespace sdds
{
    class Movie
    {
        std::string m_title{}, m_description{};
        int m_yearOfRel{};

    public:
        Movie();
        Movie(const Movie &m)
        {
            m_title = m.m_title;
            m_description = m.m_description;
            m_yearOfRel = m.m_yearOfRel;
        }
        Movie &operator=(const Movie &m)
        {
            m_title = m.m_title;
            m_description = m.m_description;
            m_yearOfRel = m.m_yearOfRel;
            return *this;
        }
        const std::string &title() const;
        Movie(const std::string &strMovie);

        template <class T>
        void fixSpelling(T &spellChecker)
        {
            spellChecker(m_title);
            spellChecker(m_description);
        }
        friend std::ostream &operator<<(std::ostream &os, Movie m);
    };
}
#endif