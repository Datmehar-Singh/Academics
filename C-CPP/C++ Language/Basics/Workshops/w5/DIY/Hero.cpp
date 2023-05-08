/*
*****************************************************************************
						Workshop 5 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include"Hero.h"
#include<iostream>
#include<fstream>
#include<cstring>
namespace sdds{

    Hero::Hero()
    {
        name[0]='\0';
        powersArr=nullptr;
        numOfPowers=-1;
        powersLevel=-1;
    }

    Hero::Hero(const char* name, Power* powerArr, int numOfPowers)
    {
        strncpy(this->name,name,MAX_NAME_LENGTH);
        this->powersArr=powerArr;
        this->numOfPowers=numOfPowers;


        int sumOfRarity=0;
        for(int i=0;i<numOfPowers;i++)
            sumOfRarity+=powersArr[i].checkRarity();

        this->powersLevel=numOfPowers*sumOfRarity;

    }

    std::ostream& Hero::display(std::ostream& os)const
    {
        os<<"Name: "<<this->name<<std::endl;
		displayDetails(this->powersArr,this->numOfPowers);
        
        os<<"Power Level: "<<this->powersLevel;
        return os;
    }

    void Hero::operator+=(Power obj)
    {
        //updating powersArr
        int i=0;
        Power* newArr=new Power[numOfPowers+1];
        for(i=0;i<numOfPowers;i++)
        {
            newArr[i] = this->powersArr[i];
        }

        newArr[i]=obj;
		//Power* temp=this->powersArr;
        //delete[] this->powersArr;
		//this->powersArr=nullptr;
        this->powersArr=newArr;
        //delete[] newArr;
        //delete[] temp;

        //updating numOfPowers
        numOfPowers++;

        //updating powerLevel
        int sumOfRarity=0;
        for(int i=0;i<numOfPowers;i++)
            sumOfRarity+=powersArr[i].checkRarity();

        this->powersLevel=numOfPowers*sumOfRarity;
    }

    int Hero::operator-=(int power)
    {
		this->powersLevel-=power;
        return 0;
    }

    bool Hero::operator<(const Hero& rightObj)
    {
        return powersLevel<rightObj.powersLevel;
    }
    bool Hero::operator>(const Hero& rightObj)
    {
        return powersLevel>rightObj.powersLevel;
    }
    void operator<<(Hero& leftObj,Power& rightObj)
    {
        leftObj+=rightObj;
    }
    void operator>>(Power& leftObj,Hero& rightObj)
    {
        rightObj+=leftObj;
    }
}