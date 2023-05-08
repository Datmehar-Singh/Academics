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
#include"Reservation.h"

namespace sdds{
    Reservation::Reservation(){
        m_resId="";
        m_resName="";
        m_emailId="";
        m_GuestsNum=0;
        m_day=0;
        m_hour=0;
    }
    
    Reservation::Reservation(const Reservation& r){
        
        //if(this==&r) {return;}
        m_resId=r.m_resId;
        m_resName=r.m_resName;
        m_emailId=r.m_emailId;
        m_GuestsNum=r.m_GuestsNum;
        m_day=r.m_day;
        m_hour=r.m_hour;
    }
    Reservation& Reservation::operator=(const Reservation& r){

        if(this==&r) {return *this;}
        m_resId=r.m_resId;
        m_resName=r.m_resName;
        m_emailId=r.m_emailId;
        m_GuestsNum=r.m_GuestsNum;
        m_day=r.m_day;
        m_hour=r.m_hour;
        return *this;
    }

    void trim(std::string& str){
        if(str.find_last_not_of(' ')==str.find_first_not_of(' '))
            return;
        std::string res=str.substr(str.find_first_not_of(' '),str.find_last_not_of(' ')-str.find_first_not_of(' ')+1);
        str=res;
    }
    Reservation::Reservation(const std::string& res){
        std::string temp="";
        std::string str=res;

        temp=str.substr(0,str.find(':'));
        str=str.substr(str.find(':')+1);
        trim(temp);
        m_resId=temp;

        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_resName=temp;

        temp=str.substr(0,str.find(','));

        str=str.substr(str.find(',')+1);
        trim(temp);
        m_emailId=temp;

        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_GuestsNum=stoi(temp);

        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_day=stoi(temp);

        temp=str.substr(0,str.find(','));
        str=str.substr(str.find(',')+1);
        trim(temp);
        m_hour=stoi(temp);        
    }
    void Reservation::update(int day, int time){
        m_day=day;
        m_hour=time;
    }

    std::ostream& operator<<(std::ostream& os, Reservation r){
	os<<"Reservation ";
        os<<std::setw(10)<<std::right<<r.m_resId<<": ";
        os<<std::setw(20)<<std::right<<r.m_resName<<" ";
        os<<std::setw(24)<<std::left<<(" <"+r.m_emailId+">")<<" ";

        int h=r.m_hour;
        if(h>=6 && h<=9) os<<"Breakfast";
        else if(h>=11 && h<=15) os<<"Lunch";
        else if(h>=17 && h<=21) os<<"Dinner";
        else os<<"Drinks";

        os<<" on day "<<r.m_day<<" @ "<<r.m_hour<<":00 for "<<r.m_GuestsNum;
        if(r.m_GuestsNum==1) os<<" person.\n";
        else os<<" people.\n";

        //os<<"\n";

        return os;        
    }
        
}