

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
#include<cstring>

namespace sdds {
    class Name {
        char* m_value;
    public:
        Name() {
            m_value = nullptr;
        }
        Name(const char* name) {
                m_value = new char[strlen(name) + 1];
                strcpy(m_value, name);
            }
        // Rule of three goes here:

        Name(const Name& n) {
            //if (m_value)
                //delete[] m_value;

            if (n.m_value != nullptr) {

                this->m_value = new char[strlen(n.m_value) + 1];
                strcpy(m_value, n.m_value);
                //n.m_value[strlen(n.m_value)] = '\0';
            }
            else m_value = nullptr;
        }
        Name& operator=(const Name n)
        {
            // if (m_value)
            delete[] m_value;
            m_value = nullptr;

            if (n.m_value != nullptr) {

                this->m_value = new char[strlen(n.m_value) + 1];
                strcpy(m_value, n.m_value);
               // n.m_value[strlen(n.m_value)] = '\0';

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

            return m_value != nullptr;
        }
        virtual std::ostream& display(std::ostream& ostr = std::cout)const
        {
            if (m_value != nullptr)
                ostr << m_value << " ";

            return ostr;
        }
        virtual std::istream& read(std::istream& istr = std::cin)
        {
            delete[] m_value;
            m_value = nullptr;

            char input[30];
            istr >> input;
            if (istr.fail())
            {
//std::cout<<"ISTR FAILED";
                return istr;
            }
		istr.ignore();
                m_value = new char[strlen(input) + 1];

                strcpy(m_value, input);
            return istr;
           
        }
        friend std::ostream& operator<<(std::ostream& os, Name& n)
        {
            return n.display(os);
        }
        friend std::istream& operator>>(std::istream& is, Name& n) {
            return n.read(is);
        }
        ~Name()
        {
            if (m_value != nullptr)
            {
                delete[] m_value;
                m_value = nullptr;
            }
        }

    };
}