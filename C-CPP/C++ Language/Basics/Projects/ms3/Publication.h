/*
*****************************************************************************
						Milestone 3
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include "Date.h"
#include "Streamable.h"
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



    
};

}