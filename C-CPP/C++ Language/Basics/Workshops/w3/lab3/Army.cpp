/*
*****************************************************************************
						Workshop 3 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include"Army.h"
#include<cstring>
#include<iomanip>
#include<iostream>
namespace sdds{
    void Army::setEmpty()
    {
        strcpy(this->nationality,"\0");
        this->noOfUnits=0;
        this->powerOfArmy=0.0;
    }

    void Army::createArmy(const char* country, double pow, int troops)
    {
        if(country && strcmp(country,"")!=0&& pow>0 && troops>0)
        {
            strncpy(this->nationality,country, MAX_NAME_LEN);
            this->noOfUnits=troops;
            this->powerOfArmy=pow;
        }
        else 
            this->setEmpty();

        return;
    }

    void Army::updateUnits(int troops)
    {
        this->noOfUnits+=troops;
        this->powerOfArmy+=0.25*troops;
    }

    const char* Army::checkNationality() const
    {
        return this->nationality;
    }

    int Army::checkCapacity() const
    {
        return this->noOfUnits;
    }

    double Army::checkPower() const
    {
        return this->powerOfArmy;
    }

    bool Army::isEmpty() const
    {
        bool nationalityFlag=true,
            powerFlag=true,
            troopFlag=true;
        
        nationalityFlag = strcmp(this->nationality,"\0")==0?true:false;
        powerFlag = this->powerOfArmy==0.0?true:false;
        troopFlag = this->noOfUnits==0?true:false;

        return nationalityFlag && powerFlag && troopFlag;
    }

    bool Army::isStrongerThan(const Army& army)const
    {
        return this->powerOfArmy>army.powerOfArmy;
    }

/*In battle of Atlantis and Ambrosia, Atlantis is victorious!
In battle of United States of Auradon and Azmenistan, Azmenistan is victorious!*/

    void battle( Army& arm1, Army& arm2)
    {
        if(arm1.isStrongerThan(arm2))
        {
			std::cout<<"In battle of "<<arm1.checkNationality()<< " and "<<arm2.checkNationality()<<", "<<arm1.checkNationality()<<" is victorious!\n";
            arm2.updateUnits((-0.50)*arm2.checkCapacity());
        }
        else
        {
			std::cout<<"In battle of "<<arm1.checkNationality()<< " and "<<arm2.checkNationality()<<", "<<arm2.checkNationality()<<" is victorious!"<<"\n";
            arm1.updateUnits((int)((-0.50)*arm1.checkCapacity()));
        }
    }

    void displayDetails(const Army* armies, int size)
    {
        std::cout<<"Armies reporting to battle: \n";
        for( int i=0;i<size;i++)
        {
			if(!(armies+i)->isEmpty())
			{
            std::cout<<"Nationality: "<<(armies+i)->checkNationality()<<",";
            std::cout<<" Units Count: "<<(armies+i)->checkCapacity()<<",";
			std::cout << std::setprecision(1) << std::fixed;
			std::cout<<" Power left: "<<(double)(armies+i)->checkPower()<<"\n";
			}
        }
    }
}