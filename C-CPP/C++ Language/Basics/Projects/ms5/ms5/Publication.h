/*
*****************************************************************************
						Milestone 4
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef PUBLICATION_H_
#define PUBLICATION_H_

#include "Streamable.h"
#include "Date.h"
#include <iomanip>
#include <string>
#include <cstring>


namespace sdds{
class Publication:public Streamable {
 public :
    char m_title[100];
    char m_shelfId[5];
    int m_libRef;
    int m_membership;
    Date m_date;
    Publication();
    ~Publication();

	virtual void setAuthName(const char * name){return;}
	virtual char* returnAuthName(){return nullptr;}
    void setEmpty();
    void setRef(int ref);
    void resetDate();
    virtual void set(int member_id);
    bool onLoan() const;
    Date checkoutDate() const;
    int getRef() const;
    bool conIO(std::ios & io) const;
    virtual char type() const;
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& is);
    operator bool() const;
    operator const char*() const;
    bool operator == (const char *newTitle) const;
    std::ostream& writeDataReadFromIO(std::ostream& os) const;
    std::ostream&  writeFromFilesReading(std::ostream& os) const;
    int convertStringToInt(string str);
	char* shelfId(){return m_shelfId;}
	char* title(){return m_title;}


    
};
/*std::ostream& printStringUpto(std::ostream& os,const char* str,int range){
        if(range>(int)strlen(str))
            range=strlen(str);

        for(int i=0;i<range;i++)
        {
            os<<str[i];
        }
        return os;
    }
*/

}

#endif