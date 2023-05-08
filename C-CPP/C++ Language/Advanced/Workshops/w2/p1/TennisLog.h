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
            TennisMatch* m_arr;
            int m_size;
        public:
            TennisLog();
            TennisLog(std::string);
            void addMatch(TennisMatch);
            TennisLog findMatches(std::string);
            TennisMatch operator[](size_t);
            operator size_t();
            ~TennisLog();

    };
}
#endif