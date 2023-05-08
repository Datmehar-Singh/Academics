#define _CRT_SECURE_NO_WARNINGS
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
#include"Book.h"

namespace sdds{
    Book::Book():Publication()
    {
        authorName=nullptr;
    }
    Book::Book(const Book& B):Publication(B){
        if(authorName)
        delete[] authorName;

	if(B.authorName!=nullptr){
        authorName=new char[strlen(B.authorName)+1];
        strcpy(authorName,B.authorName);
}
    }
    Book& Book::operator=(const Book& B){
	if(authorName!=nullptr){
        delete[] authorName;
	authorName=nullptr;
}
	Publication::operator=(B);

	if(B.authorName!=nullptr){

        authorName=new char[strlen(B.authorName)+1];
        strcpy(authorName,B.authorName);
	}

        return *this;
    }
    Book::~Book(){
        if(authorName!=nullptr){
	
            delete[] authorName;
		authorName=nullptr;
}
    }
    char Book::type() const{
        return 'B';
    }
    std::ostream& Book::write(std::ostream& os) const
    {
        Publication::write(os);
        if(conIO(os))
        {
            if (authorName != nullptr) {
            os<<" ";            //printStringUpto(os,authorName,SDDS_AUTHOR_WIDTH);
		unsigned int range=SDDS_AUTHOR_WIDTH;
		char authNameCopy[SDDS_AUTHOR_WIDTH+3]="\0";
		strncpy(authNameCopy,authorName,SDDS_AUTHOR_WIDTH);
		authNameCopy[SDDS_AUTHOR_WIDTH]='\0';
		if(range>strlen(authorName)) range=strlen(authorName);
	os<<std::setw(SDDS_AUTHOR_WIDTH)<<std::setfill(' ')<<std::left<<authNameCopy;
	  	    os<<" |";
}
        }
        else{
            os<<"\t"<<authorName;
        }
        return os;
    }
    std::istream& Book::read(std::istream& is){
        char authName[256]="\0";

        Publication::read(is);
        delete[] authorName;
        authorName=nullptr;

        if(conIO(is))
        {
            is.ignore();
            std::cout<<"Author: ";
            is.get(authName,256);
        }
        else{
            is.ignore(101,'\t');
            is.get(authName,256);
        }

        if(!is.fail())
        {
            authorName=new char[strlen(authName)+1];
            strcpy(authorName,authName);
        }

        return is;

    }

    
    void Book::set(int memId)
    {
        Publication::set(memId);
        Publication::resetDate();
        return;
    }
    
     Book::operator bool(){
        return (Publication::operator bool() && authorName!=nullptr);
     }
}