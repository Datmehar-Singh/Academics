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
#ifndef STUDENT_H_
#define STUDENT_H_

#include<iostream>


namespace sdds
{
    struct Student
    {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };

    //This function sort the list of students on the basis of their grades
    void sort(struct Student* studentsArr);

    bool load(struct Student* student);

    bool load(const char* fileName);

    void display(struct Student* const student);
    
    void display();

    void deallocateMemory();
}
#endif