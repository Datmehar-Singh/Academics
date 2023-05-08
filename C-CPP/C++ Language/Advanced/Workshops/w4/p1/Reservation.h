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
        void update(int day, int time);

        friend std::ostream& operator<<(std::ostream& os, Reservation r);

    };
}

#endif