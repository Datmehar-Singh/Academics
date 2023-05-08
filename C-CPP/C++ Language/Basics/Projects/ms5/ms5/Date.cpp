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


// Final Project Milestone 1
// Date Module
// File  Date.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iomanip>
#include <iostream>
#include<cmath>
using namespace std;
#include "Date.h"
namespace sdds {
     bool sdds_test = false;
   int sdds_year = 2022;
   int sdds_mon = 8;
   int sdds_day = 7;
bool Date::validate() {
  errCode(NO_ERROR);
  if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
    errCode(YEAR_ERROR);
  } else if (m_mon < 1 || m_mon > 12) {
    errCode(MON_ERROR);
  } else if (m_day < 1 || m_day > mdays()) {
    errCode(DAY_ERROR);
  }
  return !bad();
}
int Date::mdays() const {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
  int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
  mon--;
  return days[mon] +
         int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) ||
             (m_year % 400 == 0));
}
   int Date::systemYear()const {
      int theYear = sdds_year;
      if (!sdds_test) {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         theYear = lt.tm_year + 1900;
      }
      return theYear;
   }
   void Date::setToToday() {
      if (sdds_test) {
         m_day = sdds_day;
         m_mon = sdds_mon;
         m_year = sdds_year;
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         m_day = lt.tm_mday;
         m_mon = lt.tm_mon + 1;
         m_year = lt.tm_year + 1900;
      }
      errCode(NO_ERROR);
   }
int Date::daysSince0001_1_1() const { // Rata Die day since 0001/01/01
  int ty = m_year;
  int tm = m_mon;
  if (tm < 3) {
    ty--;
    tm += 12;
  }
  return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 +
         m_day - 306;
}
Date::Date() : m_CUR_YEAR(systemYear()) { setToToday(); }
Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
  m_year = year;
  m_mon = mon;
  m_day = day;
  validate();
}
const char *Date::dateStatus() const { return DATE_ERROR[errCode()]; }
int Date::currentYear() const { return m_CUR_YEAR; }
void Date::errCode(int readErrorCode) { m_ErrorCode = readErrorCode; }
int Date::errCode() const { return m_ErrorCode; }
bool Date::bad() const { return m_ErrorCode != 0; }
std::istream &Date::read(std::istream &is) {
  errCode(NO_ERROR);
  //char ch;
  // int i = 0, base = 0, counter = 0,selector=0;

  // int day=-1, mon=-1, year=-1;
  // std::string str;
  // std::getline(is, str);
  // i = str.size() ;
  // while (--i > 0) {
  //   if (!isdigit(str[i]) && !isdigit(str[i - 1])) {
  //     m_ErrorCode = CIN_FAILED;
  //     i = -2; // breaking condition
  //   } else {

  //     if (isdigit(str[i])) {
	// 	  // if(str[i+1]=='0')
	// 	  // 	counter+=(str[i]-48)*pow(10,base+++1);
	// 	  // else
	// 	  	counter+=(str[i]-48)*pow(10,base++);
			  
  //     }else{
	// 	  switch(selector++){
	// 		  //case 2:year=counter;break;
	// 		  case 1:mon=counter;break;
	// 		  case 0:day=counter;break;
	// 		  default: m_ErrorCode = CIN_FAILED;break;
	// 	  }
	// 	  counter=0;
	// 	  base=0;
	//   }
  //   }
  // }
	// year=counter+(str[i]-48)*pow(10,base++);
	// //std::cout<<"\n\nyear is "<<year<<"month is"<<mon<<"day is "<<day<<"\n\n";
  // //is >> year >> ch >> mon >> ch >> day;

  // // if (is.fail()) {
  // //   m_ErrorCode = CIN_FAILED;
  // // } else {
	// if(m_ErrorCode!=CIN_FAILED){
		
  //     m_day = day;
  //     m_mon = mon;
  //     m_year = year;
	// 	validate();
	
	// 	}
  // // }
  // //while(is>>ch ){;}
  // //is.ignore(100000);


  char c;
  int yr=-1,mn=-1,day=-1;
  is>>yr>>c>>mn>>c>>day;
  if(!is.fail())
  {
    m_day = day;
    m_mon = mn;
    m_year = yr;
		validate();
  }
  else{
    errCode(CIN_FAILED);
  }
  return is;
}
std::ostream &Date::write(std::ostream &os) const {
  if (m_ErrorCode != NO_ERROR) {
    os << dateStatus();
  } else {
    os << m_year << "/";
    os << setw(2) << setfill('0') << std::right << m_mon << "/";
    os << setw(2) << setfill('0') << std::right << m_day;
  }
  return os;
}

bool Date::operator==(const Date& d) const {
  return (m_day == d.m_day) && (m_mon == d.m_mon) && (m_year == d.m_year);
}
bool Date::operator!=(const Date& d) const { return !(*this == d); }
bool Date::operator<(const Date& d) const {
  int dDaysSince = d.daysSince0001_1_1();
  int thisDaysSince = daysSince0001_1_1();
  return thisDaysSince < dDaysSince;
  /*if(m_year<d.m_year) return true;
  else if(m_year>d.m_year) return false;
  else{

     if(m_mon<d.m_mon) return true;
     else if(m_mon>d.m_mon) return false;
     else
     {
        if(m_day<d.m_day) return true;
        else if(m_day>=d.m_day) return false;
     }
  }*/
}

bool Date::operator>(const Date& d) const { return !(*this < d) && *this != d; }
bool Date::operator>=(const Date& d) const { return !(*this < d); }
bool Date::operator<=(const Date& d) const { return !(*this > d); }
int Date::operator-(const Date& d ) const {
  int d1 = d.daysSince0001_1_1();
  int d2 = daysSince0001_1_1();
  return d2-d1;
}

Date::operator bool() { return m_ErrorCode == NO_ERROR; }

ostream &operator<<(ostream &os, const Date &RO) { return RO.write(os); }
istream &operator>>(istream &is, Date &RO) { return RO.read(is); }

  

} // namespace sdds
