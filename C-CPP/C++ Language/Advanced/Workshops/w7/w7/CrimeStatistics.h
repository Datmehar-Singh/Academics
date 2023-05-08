/*
*****************************************************************************
						Workshop 7 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef CRIME_STATISTICS_H
#define CRIME_STATISTICS_H


#include<fstream>
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>

namespace sdds{
struct Crime{
std::string m_province,m_district,m_crime;
int m_numOfCases, m_year, m_resolved;
};

class CrimeStatistics{
std::vector<Crime> crimes;

public:
CrimeStatistics(){}
CrimeStatistics(std::string filename);
void display(std::ostream& out) const ;
void sort(std::string fieldName);
void cleanList();
bool inCollection(std::string crimeName) const;
std::vector<Crime> getListForProvince(std::string provinceName) const;
}; 
std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif