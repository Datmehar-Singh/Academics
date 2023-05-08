#ifndef CARADS_H_
#define CARADS_H_

#include<iostream>
#include<cstring>

#define BRANDSIZE 10
#define MODELSIZE 15

extern double g_taxrate;
extern double g_discount;

namespace sdds{
    void listArgs(int argc,char* argv[]);

    class Cars{
        char m_brand[BRANDSIZE]{};
        char m_model[MODELSIZE]{};
        int m_manyear{};
        double m_price{};
        char m_status{};
        bool m_isDiscounted{};

        public:
        Cars();
        void read(std::istream&);
        void display(bool);
        char getStatus();
        ~Cars(){}
    };

}


#endif

/*
This module also defines a class named Cars in the namespace sdds that stores some information about a car ad:

    a C-style null-terminated string of up to 10 characters including the null byte terminator representing the brand of the car.

    a C-style null-terminated string of up to 15 characters including the null byte terminator representing the model of the car.

    the manufacture year of the car.

    the price of the car represented by a double value.

    the status of the cars as used or new using a single character (holds N or U)

    a boolean flag indicating whether or not the car is on promotion discount

Hint: use safe state for all data members {}
*/