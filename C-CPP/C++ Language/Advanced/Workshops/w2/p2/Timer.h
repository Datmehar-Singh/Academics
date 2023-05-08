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


#ifndef TIMER_H_
#define TIMER_H_

#include<chrono>

namespace sdds{
    class Timer{
        private:
        std::chrono::time_point<std::chrono::steady_clock> startTime;
        public:
        void start();
        long long stop();
};
}
#endif