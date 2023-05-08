/*
*****************************************************************************
						Workshop 1 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include"carads.h"
#include<iostream>
#include<iomanip>
#include<string>


namespace sdds{
    void listArgs(int argc,char* argv[])
    {
        std::cout<<"Command Line:\n";
        std::cout<<"--------------------------\n";

        for(int i=0;i<argc;i++)
        {
            std::cout<<"  "<<i+1<<": "<<argv[i]<<"\n";
        }        
	std::cout<<"--------------------------\n\n";
        return;
    }

    Cars::Cars(){
m_model=nullptr;
m_brand=nullptr;
}
    void Cars::read(std::istream& is){
	
	delete[] this->m_model;
	m_model=nullptr;
	delete[] this->m_brand;
	m_brand=nullptr;
        if(is.fail()) return;
        std::string temp;
        getline(is,temp,',');
        m_status=temp[0];
        getline(is,temp,',');
        m_brand=new char[temp.length()+2];
        strcpy(m_brand,temp.c_str());
	m_brand[temp.length()]='\0';

        getline(is,temp,',');
        
        m_model=new char[temp.length()+2];
        strcpy(m_model,temp.c_str());
        getline(is,temp,',');
        m_manyear=stoi(temp);
        getline(is,temp,',');
        m_price=stof(temp);
        getline(is,temp);
        m_isDiscounted=(temp[0]=='Y')?true:false;


        //<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
    }
    void Cars::display(bool resetCounter){
	if(m_brand!=nullptr && m_model!=nullptr){
        static int counter=1;
	if(resetCounter) counter=1;
        std::cout<<std::left<<std::setw(2)<<counter++<<". ";
	//std::cout<<"m_brand size is : "<<strlen(m_brand);
        std::cout<<std::left<<std::setw(10)<<m_brand<<"| ";
        std::cout<<std::left<<std::setw(15)<<m_model<<"| ";
        std::cout<<m_manyear<<" |";
        std::cout<<std::right<<std::setw(12)<<std::fixed<<std::setprecision(2)<<m_price+m_price*g_taxrate<<"|";
        if(m_isDiscounted)
        {
            std::cout<<std::right<<std::setw(12)<<std::setprecision(2)<<m_price+m_price*g_taxrate-(m_price+m_price*g_taxrate)*g_discount;
        }
        
        std::cout<<"\n";
}
    }
    Cars& Cars::operator=(const Cars& c){
	//delete[] m_brand;
	m_brand=nullptr;
        m_brand=new char[strlen(c.m_brand)+2];//
        strcpy(m_brand,c.m_brand);
	//delete[] m_model;
m_model=nullptr;
        m_model=new char[strlen(c.m_model)+2];
        strcpy(m_model,c.m_model);
        m_manyear=c.m_manyear;
        m_price=c.m_price;
        m_status=c.m_status;
        m_isDiscounted=c.m_isDiscounted;
	return *this;
    }
    char Cars::getStatus(){ return m_status;}
    Cars::operator bool(){
        return (m_status=='N')?true:false;
    }
    
    std::istream& operator>>(std::istream& is, Cars& car){ 
car.read(is); 
return is;
}
    void operator>>(const Cars& car1, Cars& car2){
        /*
        
        char m_brand[BRANDSIZE]{};
        char m_model[MODELSIZE]{};
        int m_manyear{};
        double m_price{};
        char m_status{};
        bool m_isDiscounted{};
        */

	
       car2=car1;
       return;
    }
}