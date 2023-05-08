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
#include "Restaurant.h"

namespace sdds
{
    Restaurant::Restaurant()
    {
        m_ptrArr = nullptr;
        m_size = 0;
    }
    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt)
    {	
        m_ptrArr = new Reservation *[cnt];
        for (int i = 0; i <(int) cnt; i++)
        {
		//Reservation res{*reservations[i]};
            m_ptrArr[i] = new Reservation{*reservations[i]};
        }
        m_size = cnt;
    }

    Restaurant::Restaurant(const Restaurant &r)
    {
	if(this==&r) {return;}
	if(m_ptrArr)
	for (int i = 0; i < (int)m_size; i++)
	{
	delete m_ptrArr[i];
}
m_size=0;
        delete[] this->m_ptrArr;

        m_ptrArr = new Reservation *[r.m_size];
        for (int i = 0; i < (int)r.m_size; i++)
        {
            m_ptrArr[i] =  new Reservation{*r.m_ptrArr[i]};
        }
        m_size = r.m_size;
    }
    Restaurant::Restaurant(Restaurant&& r)
    {
        delete[] this->m_ptrArr;
        m_ptrArr=r.m_ptrArr;
        r.m_ptrArr=nullptr;
        this->m_size=r.m_size;
        r.m_size=0;
    }
    Restaurant &Restaurant::operator=(const Restaurant &r)
    {	if(this==&r) {return *this;}
for (int i = 0; i < (int)m_size; i++)
	{
	delete m_ptrArr[i];
}
m_size=0;

        delete[] this->m_ptrArr;

        m_ptrArr = new Reservation *[r.m_size];
       for (int i = 0; i < (int)r.m_size; i++)
        {
            m_ptrArr[i] =  new Reservation{*r.m_ptrArr[i]};
        }
        m_size = r.m_size;
        return *this;
    }
    Restaurant &Restaurant::operator=(Restaurant &&r) {
        if(this==&r) return *this;
        delete[] this->m_ptrArr;
        m_ptrArr=r.m_ptrArr;
        r.m_ptrArr=nullptr;
        this->m_size=r.m_size;
        r.m_size=0;
        return *this;
    }

    size_t Restaurant::size() { return m_size; }
    std::ostream &operator<<(std::ostream &os, Restaurant r)
    {
        static int counter = 1;
        if (r.m_size == 0)
        {
            os << "--------------------------\n";
            os << "Fancy Restaurant (" << counter++ << ")\n";
            os << "--------------------------\n";
            os << "This restaurant is empty!\n";
            os << "--------------------------\n";
        }
        else
        {
            os << "--------------------------\n";
            os << "Fancy Restaurant (" << counter++ << ")\n";
            os << "--------------------------\n";
            for (int i = 0; i < (int)r.size(); i++)
            {
                os << *(r.m_ptrArr[i]);
            }
            os << "--------------------------\n";
        }
return os;
    }
    Restaurant::~Restaurant()
    {
	for(int i=0;i<(int)m_size;i++)
{
delete m_ptrArr[i];
}
m_size=0;
        delete[] m_ptrArr;
    }
}