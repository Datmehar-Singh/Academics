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

    void trim(std::string& str){
        std::string res=str.substr(str.find_first_not_of(' '),str.find_last_not_of(' ')-str.find_first_not_of(' '));
        str=res;
    }
    Reservation::Reservation(const std::string& res){
        std::string temp="";
        std::string str=res;

        temp=str.substr(0,str.find(':'));
        str=str.substr(0,str.find(':')+1);
        trim(temp);
        m_resId=temp;

        temp=str.substr(0,str.find(','));
        str=str.substr(0,str.find(',')+1);
        trim(temp);
        m_resName=temp;

        temp=str.substr(0,str.find(','));
        str=str.substr(0,str.find(',')+1);
        trim(temp);
        m_emailId=temp;

        temp=str.substr(0,str.find(','));
        str=str.substr(0,str.find(',')+1);
        trim(temp);
        m_GuestsNum=stoi(temp);

        temp=str.substr(0,str.find(','));
        str=str.substr(0,str.find(',')+1);
        trim(temp);
        m_day=stoi(temp);

        temp=str.substr(0,str.find(','));
        str=str.substr(0,str.find(',')+1);
        trim(temp);
        m_hour=stoi(temp);        
    }
    void Reservation::update(int day, int time){
        m_day=day;
        m_hour=time;
    }

    std::ostream& operator<<(std::ostream& os, Reservation r){
        os<<std::setw(10)<<std::right<<r.m_resId<<": ";
        os<<std::setw(20)<<std::right<<r.m_resName<<" ";
        os<<std::setw(20)<<std::left<<("<"+r.m_emailId+">")<<" ";

        int h=r.m_hour;
        if(h>6 && h<9) os<<"Breakfast ";
        else if(h>11 && h<3) os<<"Lunch";
        else if(h>5 && h<9) os<<"Dinner";
        else os<<"Drinks";

        os<<" on the day "<<r.m_day<<" @ "<<r.m_hour<<":00 for "<<r.m_GuestsNum;
        if(r.m_GuestsNum==1) os<<" person.";
        else os<<" people.";

        return os;        
    }
        
}