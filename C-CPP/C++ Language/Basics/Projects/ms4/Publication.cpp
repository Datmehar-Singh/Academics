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
#include "Publication.h"
#include <string>
#include "Lib.h"
using namespace std;
namespace sdds{
void Publication::setEmpty(){
    m_shelfId[0] = '\0';
    m_membership = 0;
    m_title[0] = '\0';
    m_libRef=-1;
}

Publication::Publication(){
    m_shelfId[0] = '\0';
    m_membership = 0;
    m_title[0] = '\0';
    m_libRef=-1;
}
bool Publication::onLoan() const{
    bool loanFlag=(m_membership!=0);
    return loanFlag;
}
Date Publication::checkoutDate() const{
    return m_date;
}
int Publication::getRef() const{
    return m_libRef;
}
char Publication::type() const{
    return 'P';
}
// setter for title
// void Publication::setTitle(const char* title){
//     if(title == nullptr){
//         m_title[0] = '\0';
//     }
//     else{
//         strcpy(m_title,title);
//     }
// }
// // setter for shelf
// void Publication::setShelf(const char* shelf){
//     if(shelf == nullptr){
//         m_shelfId[0] = '\0';
//     }
//     else{
//         strcpy(m_shelfId,shelf);
//     }
// }
// setter for libRef
void Publication::setRef(int ref){
    m_libRef=ref;
}
// setter for date 
// void Publication::setDate(const Date& date){
//     m_date=date;
// }
// setter for membership
void Publication::set(int member_id){
    bool flag=member_id>9999 && member_id<=999999;
    if(flag){
        m_membership=member_id;
    }
    else{
        m_membership=0;
    }
}
Publication::~Publication(){
    setEmpty();

}

bool Publication::conIO(ios& io) const{
    return (&io==&cin || &io==&cout);
}

void Publication::resetDate(){
    m_date.setToToday();
}

Publication::operator const char*() const{
    return (const char *)m_title;
}
bool Publication::operator==(const char *newTitle) const {
     string s2(newTitle);
            string s1(m_title);
            return s1.find(s2) != std::string::npos;
}
ostream& Publication::write(std::ostream& os) const{
    if(conIO(os)){
           bool writeFlag=m_title[0] == '\0' && m_shelfId[0] == '\0' && m_membership == 0 && m_libRef == -1;
		
           if(writeFlag) return os;
           else{
		char titleCopy[SDDS_TITLE_WIDTH+3];
		strncpy(titleCopy,m_title,SDDS_TITLE_WIDTH);
		titleCopy[SDDS_TITLE_WIDTH]='\0';
               os<<"| ";
               os<<m_shelfId;
               os<<" | ";
               os<<setw(30)<<std::left << std::setfill('.') << titleCopy;
               os<<" | ";
               bool mFlag=(m_membership==0);
                if(mFlag){
                     os<<" N/A ";
                }
                else{
                     os<<m_membership;
                }
               os<<" | ";
               os<<m_date;
               os<<" |";
               return os;
           }
    }
    else{
           os<<type()<<'\t'<<m_libRef<<'\t'<<m_shelfId<<'\t'<<m_title<<'\t';
              bool mFlag=(m_membership==0);
                if(mFlag){
                     os<<"N/A";
                }
                else{
                     os<<m_membership;
                }
              os<<'\t'<<m_date;
              return os;
    }
 
}
Publication::operator bool() const{
   if (m_title[0] == '\0' || m_shelfId[0] == '\0')
        return false;
   else{
       return true;
   }     
}
int Publication::convertStringToInt(string str)
    {
        int res=0;
        for(unsigned int i=0;i<str.length();i++)
        {
            res=res*10+(str[i]-'0');
        }
        return res;
    }
istream& Publication ::read(istream & is){
setEmpty();

char tabSpace='\t';

if(conIO(is)){
     string ioValue;
    cout<<"Shelf No: ";
    is>>ioValue;
    if(ioValue.size()!=4){
        is.setstate(ios_base::failbit);
    } 
    strcpy(m_shelfId,ioValue.c_str());
    cout<<"Title: ";
    is.ignore(); // ignores one character after the colon and space in the input stream
    getline(is,ioValue,'\n');
    strcpy(m_title,ioValue.c_str());
    cout<<"Date: ";
    is>>m_date;// read date from the input stream
}
else{
    string  fileRead;
    if(!is) return is;
    getline(is,fileRead,tabSpace);
    m_libRef=convertStringToInt(fileRead);
    getline(is,fileRead,tabSpace);
    strcpy(m_shelfId,fileRead.c_str());
    getline(is,fileRead,tabSpace);
    strcpy(m_title,fileRead.c_str());
    getline(is,fileRead,tabSpace);
    m_membership=convertStringToInt(fileRead);
    is>>m_date;
}
if(!m_date){
    is.setstate(std::ios_base::failbit);
}

if(is.fail()){
   setEmpty();
}
return is;
}


}