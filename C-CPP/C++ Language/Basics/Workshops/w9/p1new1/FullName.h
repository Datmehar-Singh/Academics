

// /*
// *****************************************************************************
// 						Workshopo 9
// Full Name  : Datmehar Singh
// Student ID#: 108011214
// Email      : datmehar-singh@myseneca.ca
// Section    : NHH

// Authenticity Declaration:
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// *****************************************************************************
// */

#include<iostream>
#include "Name.h"

namespace sdds {

    class FullName :public Name {
        char* m_value;
    public:
        FullName() {
            m_value = nullptr;
        }
        FullName(const char* name, const char* lastname) :Name(name) {
if(lastname!=nullptr){
                m_value = new char[strlen(lastname) + 1];
                strcpy(m_value, lastname);
}
else m_value=nullptr;

                   }
        // Rule of three goes here:

        FullName(const FullName& n) :Name(n) {
            //if (m_value!=nullptr)
                //delete[] m_value;
if(n.m_value!=nullptr){

                this->m_value = new char[strlen(n.m_value) + 1];
                strcpy(m_value, n.m_value);
                //n.m_value[strlen(n.m_value)] = '\0';
}
else m_value=nullptr;
        }
        FullName& operator=(const FullName& n)
        {
            Name::operator=(n);
                delete[] m_value;
                m_value = nullptr;


            if (n.m_value != nullptr) {
                this->m_value = new char[strlen(n.m_value) + 1];
                strcpy(m_value, n.m_value);
                //n.m_value[strlen(n.m_value)] = '\0';
            }
            else m_value = nullptr;

            return *this;
        }



        operator const char* ()const
        {
            return m_value;
        }
        virtual operator bool()const
        {
            //return true;
            return m_value != nullptr && Name::operator bool();
        }
        virtual std::ostream& display(std::ostream& ostr = std::cout)const
        {
            //ostr << (Name)(*this);
            if (m_value != nullptr) {
                Name::display(ostr);
                ostr << m_value;
            }

            return ostr;
        }
        virtual std::istream& read(std::istream& istr = std::cin)
        {

            char input [30];

            delete[] m_value;
            m_value = nullptr;

            Name::read(istr);
            istr.getline(input, 30, '\n');
            if (!istr.fail()) {
                            m_value = new char[strlen(input) + 1];
            strcpy(m_value, input);

            }
            return istr;
        }
        friend std::ostream& operator<<(std::ostream& os, FullName& n)
        {
            return n.display(os);
        }
        friend std::istream& operator>>(std::istream& is, FullName& n) {
            return n.read(is);

        }
        ~FullName() {
            if (m_value != nullptr) {
                delete[] m_value;
                m_value = nullptr;
            }
        }

    };
}