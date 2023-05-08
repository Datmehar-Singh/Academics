/*
*****************************************************************************
						Workshop 3 - Part 2
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 6 May 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include "Bar.h"
#include<cstring>
#include<iostream>
#include<iomanip>

namespace sdds{
    void Bar::setEmpty(){
        strcpy(this->title,"\0");
        this->fillChar='-';
        this->val=0;
        return;
    }

    void Bar::set(const char* title, const char fillChar, const int val){
        strcpy(this->title,title);
        this->fillChar=fillChar;
        this->val=val;
        return;
    }

    bool Bar::isEmpty()
    {
        if(strcmp(this->title,"\0")==0 &&this->fillChar=='-' && this->val==0)
            return true;
        else 
            return false;
    }   

    void Bar::draw()
    {
        if(this->val<0  ||  this->val>100){ 
			this->isValid=false;
			return;
			}
		this->isValid=true;
		//std::cout<<"\n";
        std::cout<<std::left<<std::setfill('.')<<std::setw(19);
        std::cout<<this->title;
		//std::setw(1);
		//std::cout<<std::setw(1)<<"|";
        //std::cout<<;
        std::cout<<std::right<<std::cout.fill(this->fillChar)<<"|"<<std::setw(this->val/2+1);
		std::setw(0);
		std::cout<<"\n";
        //return;
    }
}