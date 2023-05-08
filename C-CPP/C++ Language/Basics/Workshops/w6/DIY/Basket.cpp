/*
*****************************************************************************
						Workshop 6 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/



#include "Basket.h"
#include<iomanip>

namespace sdds{
    Basket::Basket(){
        m_fruits=nullptr;
        m_cnt=0;
        m_price=0.0;
    }
    
    Basket::Basket(Fruit* f, int size, double price){
        if(f!=nullptr && size>0 && price>0.0)
        {
            //m_fruits=f;
		m_fruits=new Fruit[size];
		for(int i=0;i<size;i++)
		{
			m_fruits[i]=f[i];
		}
            m_cnt=size;
            m_price=price;
        }
        else
        {
            m_fruits=nullptr;
            m_cnt=0;
            m_price=0.0;
        }
    }
    
    Basket::Basket(const Basket& b){

        //code to deep copy fruits array
        m_cnt=b.m_cnt;
        if(b.m_fruits!=nullptr && b.m_cnt>0)
        {
            m_fruits=new Fruit[b.m_cnt];
            for(int i=0;i<b.m_cnt;i++)
            {
                m_fruits[i]=b.m_fruits[i];
            }
        }else{
            m_fruits=nullptr;
        }

        if(b.m_price>0.0) m_price=b.m_price;
        else m_price=0.0;
    }
 
    Basket Basket::operator=(Basket b){
        m_cnt=b.m_cnt;
	delete[] m_fruits;
        if(b.m_fruits!=nullptr && b.m_cnt>0)
        {
		//if(m_fruits!=nullptr)
		
            m_fruits=new Fruit[b.m_cnt];
            for(int i=0;i<b.m_cnt;i++)
            {
                m_fruits[i]=b.m_fruits[i];
            }
        }else{
            m_fruits=nullptr;
        }

        if(b.m_price>0.0) m_price=b.m_price;
        else m_price=0.0;

        return *this;
    }

    Basket::~Basket(){
        //if(m_cnt!=0)
        delete[] this->m_fruits;
    }

    void Basket::setPrice(double price){
        if(price>0.0) m_price=price;
        return;
    }
    
    Basket::operator bool(){
        return (m_fruits!=nullptr|| m_cnt);
    }
    
    Basket& Basket::operator+=(Fruit f){


        Fruit* tempArr=new Fruit[m_cnt+1];
        for(int i=0;i<m_cnt;i++)
        {
            tempArr[i]=m_fruits[i];
        }
        tempArr[m_cnt]=f;

        if(this->m_fruits!=nullptr)
          delete[] m_fruits;
        m_fruits=new Fruit[m_cnt+1];

        for(int i=0;i<=m_cnt;i++)
        {
            m_fruits[i]=tempArr[i];
        }

        delete[] tempArr;
        m_cnt++;

        return *this;
    }

    std::ostream& operator<<(std::ostream& ostr,Basket b){
        if(b.m_cnt==0)
            ostr<<"The basket is empty!\n";
        else
        {
            ostr << "Basket Content:\n";
            for( int i=0;i<b.m_cnt;i++)
            {
                ostr<<std::setw(10)<<std::right<<b.m_fruits[i].m_name;
                ostr<<": "<< std::fixed << std::setprecision(2) <<b.m_fruits[i].m_qty<<"kg\n";
            }
            ostr<<"Price: "<<b.m_price<<'\n';
        }
        return ostr;
    }

}