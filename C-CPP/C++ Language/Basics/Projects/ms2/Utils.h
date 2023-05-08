/***********************************************************************
// OOP244 Utils Module
// File  utils.h
// Version
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/


/*
*****************************************************************************
						Milestone 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
    int takeInputIntegerRangeaes(int max){
        int res=0;
        bool flag=true;
        while(flag)
        {
            std::cin>>res;
            if(isdigit(res) && res<=max && res>=0)
            {
                flag=false;
            }
            else{
                std::cout<<"\nInvalid Selection, try again: ";
            }
        }
        return res;
    }

}
#endif // !
