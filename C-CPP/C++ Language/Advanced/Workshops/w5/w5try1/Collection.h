/*
*****************************************************************************
						Workshop 5 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds
{
    template <class T>
    class Collection
    {
        std::string m_name{};
        T *m_arr{};
        size_t m_size;
        void (*funPtr)(const Collection<T> &, const T &){};

    public:
        Collection(const std::string &name)
        {
            m_name = name;
            m_size = 0;
            funPtr = nullptr;
            m_arr = nullptr;
        }
        Collection(const Collection &c) = delete;
        ~Collection()
        {
            delete[] m_arr;
        }
        const std::string &name() const
        {
            return m_name;
        }
        size_t size() const { return m_size; }

        void setObserver(void (*observer)(const Collection<T> &, const T &)){
            funPtr=observer;
        }
        Collection<T>& operator+=(const T& item){

            if(m_arr==nullptr && m_size==0){
                m_size++;
                m_arr=new T[m_size];
                m_arr[0]=item;
                return *this;
            }
            for(int i=0;i<(int)this->m_size;i++)
            {
                if(m_arr[i].title()==item.title())
                    return *this;
            }
            T* m_arrCopy=new T[this->m_size+1];
            for(int i=0;i<(int)this->m_size;i++)
            {
                m_arrCopy[i]=m_arr[i];
            }
            m_arrCopy[this->m_size]=item;
            m_size++;
            delete[] m_arr;
            m_arr=m_arrCopy;
            // std::cout<<"before";
            if(funPtr!=nullptr)
            funPtr(*this,item);
            // std::cout<<"after";
            return *this;
        }
        T& operator[](size_t idx) const{
            if(m_size<=idx) {
	std::string str="** EXCEPTION: Bad index ["+std::to_string(idx)+"]. Collection has ["+std::to_string(m_size)+"] items.";

		throw (str);
}
            return m_arr[idx];

        }
        T* operator[](const std::string& title) const{
            for(int i=0;i<(int)m_size;i++)
            {
                if(m_arr[i].title()==title)
                {
                    return &m_arr[i];
                }
            }
            return nullptr;
        }
        friend std::ostream& operator<<(std::ostream& os, Collection<T>& c){
            for(int i=0;i<(int)c.m_size;i++)
            {
                os<<c.m_arr[i]<<"\n";
            }
            return os;
        }
    };
}

#endif