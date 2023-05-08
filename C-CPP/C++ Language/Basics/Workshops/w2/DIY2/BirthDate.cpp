/*
*****************************************************************************
						Workshop 2 - Part 2
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
#include"BirthDate.h"
#include<cstring>

#define MAX_RECORD_LENGTH 100
#define MAX_NAME_LENGTH 30

int numberOfRecords;
int validatedRecords;

namespace sdds
{
    FILE* fptr=nullptr;
    struct EmployeeData* employees=nullptr;

    

	bool beginSearch(const char* filename)
    {
        fptr=fopen(filename,"r");

        if(fptr)
            std::cout<<"Birthdate search program\n";
        else
        {
            std::cout<<"Data file "<<filename<<" not found!\n";
            return false;
        }

        numOfEmployees();
        
        employees=new struct EmployeeData[::numberOfRecords];

        populateEmployeesArr();

        return true;
    }

    bool readBirthDate(int month)
    {
        bool flag=false;
        for(int i=0;i<::numberOfRecords;i++)
        {
            if(employees[i].dob.month==month)
            {
                flag=true;
                ::validatedRecords++;
                employees[i].isValidated=true;
            }
            else
                employees[i].isValidated=false;
        }
        return flag;
    }

    void sort()
    {
        for(int i=0;i<::numberOfRecords;i++)
        {
            for(int j=i+1;j<::numberOfRecords;j++)
            {
                if(employees[i].dob.year>=employees[j].dob.year)
                {
                    struct EmployeeData temp=employees[i];
                    employees[i]=employees[j];
                    employees[j]=temp;
                }
            }
        }
    }

    void displayBirthdays()
    {
        int counter=0;

	std::cout<<::validatedRecords<<" birthdates found:\n";
;        for(int i=0;i<::numberOfRecords;i++)
        {
            if(employees[i].isValidated)
            {
                std::cout<<++counter<<") "<<employees[i].firstName<< " "<<employees[i].lastName<<":\n";
                std::cout<<employees[i].dob.year<<"-"<<employees[i].dob.month<<"-"<<employees[i].dob.day;
                std::cout<<"\n===================================\n";
                employees[i].isValidated=false;
            }
        }
    }

    void deallocate()
    {
        fclose(fptr);
        for( int i=0;i<::numberOfRecords;i++)
        {
            delete[] employees[i].firstName;
            delete[] employees[i].lastName;
        }
        fptr=nullptr;

        delete[] employees;
    }

    void endSearch()
    {
        fptr=nullptr;
	std::cout<<"Birthdate Search Program Closed.\n";

    }

    void numOfEmployees()
    {
		char line[100];
do{::numberOfRecords++;}while(fgets(line,MAX_RECORD_LENGTH,fptr));
		rewind(fptr);
    }

    void populateEmployeesArr()
    {
        int counter=-1;

        while(++counter<::numberOfRecords)
        {
            readAndStore(&employees[counter]);
			//fgets(employees[counter].firstName,100,fptr);
            //readAndStoreDOB(&employees[counter]);
        }


    }
    void readAndStore(struct EmployeeData* employee)
    {
		char name[100]="\0",fname[100]="\0";
		int x=0,y=0,z=0;
		fscanf(fptr, "%s %[^,],%d/%d/%d",fname,name,&x,&y,&z);

		employee->firstName=new char[strlen(fname)+1];

		employee->lastName=new char[strlen(name)+1];
		
		strcpy(employee->firstName,fname);
		strcpy(employee->lastName,name);
		employee->dob.month=x;
		employee->dob.day=y;
		employee->dob.year=z;
		employee->isValidated=true;
		
    }

}