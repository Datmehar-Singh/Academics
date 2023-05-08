/*
*****************************************************************************
						Workshop 2 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef TENNIS_LOG_H_
#define TENNIS_LOG_H_

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

namespace sdds{
    class TennisMatch{
        public:
            std::string m_TID;
            std::string m_TName;
            unsigned int m_MID;
            std::string m_MWinner;
            std::string m_MLoser;
            
            TennisMatch(std::string,std::string,int,std::string,std::string);
            TennisMatch();
            friend std::ostream& operator<<(std::ostream&,TennisMatch);
            TennisMatch& operator=(const TennisMatch& t);
            ~TennisMatch();
    };

    class TennisLog{
        private:
            TennisMatch* m_arr{};
            int m_size;
        public:
            TennisLog();
            TennisLog(std::string);
            TennisLog(const TennisLog&);
            TennisLog& operator=(const TennisLog&);
            TennisLog(TennisLog&&);
            TennisLog& operator=(TennisLog&&);
            void addMatch(TennisMatch);
            TennisLog findMatches(std::string);
            TennisMatch operator[](size_t);
            operator size_t();
            ~TennisLog();

    };
}
#endif