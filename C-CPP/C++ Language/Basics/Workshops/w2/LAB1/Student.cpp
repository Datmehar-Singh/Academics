/*
*****************************************************************************
						Workshop 2 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include<iostream>
#include<cstring>
#include "Student.h"
#include "File.h"

int noOfStudents;
struct sdds::Student* students=nullptr;


namespace sdds
{

    void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_grade > students[j + 1].m_grade) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

    bool load(struct Student& student)
    {
        char studentName[128];
        bool nameBool=true,
            gradeBool=true,
            stuNumBool=true;

       	nameBool=read(studentName);
		// std::cout<<"student name is "<<student
		
        int nameLength=strlen(studentName);

        student.m_name=new char[nameLength+1];
        strcpy(student.m_name,studentName);
         stuNumBool=read(&student.m_studentNumber);

          gradeBool=read((student.m_grade));
		

        return nameBool && gradeBool && stuNumBool;
    }

    bool load(const char* fileName)
    {
        int counter=0;
	openFile(fileName);

        ::noOfStudents=noOfRecords();

        ::students=new struct Student[::noOfStudents];
		
        do{
            load(::students[counter]);
            counter++;
        }while(counter<::noOfStudents );

		//closeFile();
		closeFile();
        if(counter!=::noOfStudents) 
        {
            std::cout<<"Error: incorrect number of records read; the data is possibly corrupted.";
            return false;
        }
        else
        {
            return true;
        }

    }

    void display(const struct Student student)
    {
        //name, student number: Grade<NEWLINE>
		//std::cout<<"rr";
       std::cout<<student.m_name<<", ";
        std::cout<<student.m_studentNumber<<": ";
        std::cout<<student.m_grade<<"\n";

    }

    void display()
    {
        int counter=0;
        sdds::sort();
        while(counter<noOfStudents)
        {
            std::cout<<counter+++1<<": ";
            sdds::display(::students[counter-1]);
        }
    }

    void deallocateMemory(){
        int counter=0;
        while(counter++<noOfStudents)
        {
            delete[] students[counter-1].m_name;
        }
        delete[] students;
	closeFile();
    }
}

