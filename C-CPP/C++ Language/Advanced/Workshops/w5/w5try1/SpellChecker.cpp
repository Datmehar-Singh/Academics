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
#include "SpellChecker.h"

namespace sdds
{
    SpellChecker::SpellChecker(const char *filename){
        std::ifstream fptr(filename);
        if(!fptr.is_open()) throw std::string("Bad file name!");
        std::string temp;
        int i=0;
        while(std::getline(fptr,temp)){
            m_badWords[i]=temp.substr(0,temp.find(' '));
            temp=temp.substr(temp.find(' '));
            m_goodWords[i++]=temp.substr(temp.find_first_not_of(' '));
        }
        // m_counterForReplaces=0;
    }
    void SpellChecker::operator()(std::string &text){
        int i=0;
        while(i<6)
        {
            while((int)text.rfind(m_badWords[i])!=-1)
            {
                text.replace(text.rfind(m_badWords[i]),m_badWords[i].length(),m_goodWords[i]);
                m_counterForReplaces[i]++;
            }
            i++;
        }
    }
    void SpellChecker::showStatistics(std::ostream &out) const{
	std::cout<<"Spellchecker Statistics\n";
        for(int i=0;i<6;i++){
            out<<std::right<<std::setw(15)<<m_badWords[i];
            out<<": "<<m_counterForReplaces[i]<<" replacements\n";
        }
    }

}