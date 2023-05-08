#include"carads.h"
#include<iostream>
#include<iomanip>


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

    Cars::Cars(){}
    void Cars::read(std::istream& is){
        if(is.fail()) return;
        char temp[20];
        is.getline(temp,100,',');
        m_status=temp[0];
        is.getline(temp,100,',');
        strcpy(m_brand,temp);
        is.getline(temp,100,',');
        strcpy(m_model,temp);
        is.getline(temp,100,',');
        m_manyear=atoi(temp);
        is.getline(temp,100,',');
        m_price=atof(temp);
        is.getline(temp,100,'\n');
        m_isDiscounted=temp[0]=='Y'?true:false;


        //<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
    }
    void Cars::display(bool resetCounter){
        static int counter=1;
	if(resetCounter) counter=1;
        std::cout<<std::left<<std::setw(2)<<counter++<<". ";
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
    char Cars::getStatus(){ return m_status;}
}