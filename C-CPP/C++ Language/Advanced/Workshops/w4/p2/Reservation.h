/*
*****************************************************************************
						Workshop 4 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef RESERVATION_H
#define RESERVATION_H

#include<iostream>
#include<string>
#include<iomanip>

namespace sdds{
    class Reservation
    {
        private:
        std::string m_resId;
        std::string m_resName;
        std::string m_emailId;
        int m_GuestsNum;
        short int m_day;
        short int m_hour;

        public:
        Reservation();
        Reservation(const std::string& res);
        Reservation(const Reservation& r);
        Reservation& operator=(const Reservation& r);
        void update(int day, int time);

        friend std::ostream& operator<<(std::ostream& os, Reservation r);

    };
}

#endif