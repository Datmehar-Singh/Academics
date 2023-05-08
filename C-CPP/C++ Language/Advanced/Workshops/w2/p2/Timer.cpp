/*
*****************************************************************************
						Workshop 2 - Part 2
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 25 September 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Timer.h"

namespace sdds{
	void Timer::start(){
            startTime=std::chrono::steady_clock::now();
        }
        long long Timer::stop(){
            return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now()-startTime).count();
        }
}
