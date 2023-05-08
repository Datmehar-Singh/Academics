/*
*****************************************************************************
						Workshop 4 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include "Car.h"
#include <cstring>
#include <iomanip>
#include <iostream>

namespace sdds {
Car::Car() {

  this->m_type = nullptr;
  this->m_brand = nullptr;
  this->m_model =nullptr;

  this->m_year = -1;
  this->m_code = -1;
  this->m_price = -1.0;
}
Car::Car(const char* type, 
             const char* brand, 
             const char* model, 
             int year, 
             int code, 
             double price) 
{

  this->m_type = new char[strlen(type)+1];
  this->m_brand = new char[strlen(brand)+1];
  this->m_model = new char[strlen(model)+1];

  strcpy(this->m_type, type);
  strcpy(this->m_brand, brand);
  strcpy(this->m_model, model);

  this->m_year = year;
  this->m_code = code;
  this->m_price = price;
	
}


// member  functions declaration

void copyStringAfterChecking(char* dest,char* source)
{
	if(dest!=nullptr)
	{
	dest=new char[strlen(source)+1];
	strcpy(dest,source);
}
else dest=nullptr;
return;
}

Car &Car::setInfo(const char *type, const char *brand, const char *model, int year, int code, double price) {
  Car &newObject = *this;

if(this->m_type!=nullptr)
delete[] this->m_type;

if(this->m_brand!=nullptr)
delete[] this->m_brand;

if(this->m_model!=nullptr)
delete[] this->m_model;




if(type!=nullptr)
{  
this->m_type = new char[strlen(type)];
  strcpy(this->m_type, type);
}
else
this->m_type=nullptr;

if(brand!=nullptr)
{  this->m_brand = new char[strlen(brand)];
  strcpy(this->m_brand, brand);
}
else
this->m_brand=nullptr;


if(model!=nullptr){
  this->m_model = new char[strlen(model)];
  strcpy(this->m_model, model);
}
else
this->m_model=nullptr;

  this->m_year = year;
  this->m_code = code;
  this->m_price = price;
	
  return newObject;
}

void Car::printInfo() const {
  //| 10  spaces | 16        spaces | 16        spaces | 9999 |  999 | 999999.99
  //|
  //+------------+------------------+------------------+------+------+-----------+"
	
	std::cout<<std::left;
  std::cout  << "| "<< std::setw(11)  << this->m_type
	  << "| " << std::setw(17)<< this->m_brand 
	  << "| "<< std::setw(17)  << this->m_model
	  << "| "<< std::setw(5) << this->m_year
	  << "|  "  << std::setw(4)<<this->m_code
	  <<std::right
	  << "| "<<std::setw(9)<< std::setprecision(2) << std::fixed<<this->m_price << " |"<<std::left;
	std::cout<<std::right<<"\n";
}

bool Car::isValid() const {

  bool type = this->m_type == nullptr ? false : true;
  bool brand = this->m_brand == nullptr ? false : true;
  bool model = this->m_model == nullptr ? false : true;

  bool year = this->m_year >= 1990 ? true : false;
  bool code = this->m_code / 100 != 0 ? true : false;
	//std::cout<<"\n\n"<<m_code<<code<<"\n\n";
  bool price = this->m_price > 0 ? true : false;

  return type && brand && model && year && code && price;
}
bool Car::isSimilarTo(const Car &car) const {
	
  bool type = strcmp(this->m_type, car.m_type) == 0,
       brand = strcmp(this->m_brand, car.m_brand) == 0,
       model = strcmp(this->m_model, car.m_model) == 0,
       year = this->m_year == car.m_year;

  return type && brand && model && year;
}
bool has_similar(const Car car[], const int num_cars) {
	int flag=0;
  for (int i = 0; i < num_cars; i++) {
    for (int j = i + 1; j < num_cars; j++) {
		if(car[i].isValid()&&car[j].isValid())
      if (car[i].isSimilarTo(car[j])) {
		  flag++;
        // match is found
      }
    }
  }
	return flag!=0;
}

bool has_invalid(const Car car[], const int num_cars)
{
	for(int i=0;i<num_cars;i++)
		{
			if(!car[i].isValid())
			{
				return true;
			}
		}
	return false;
}

void print(const Car car[], const int num_cars)
{
	for(int i=0;i<num_cars;i++)
		{
			if(car[i].isValid())
				car[i].printInfo();
		}
	return;
}
Car::~Car()
{

delete[] this->m_type;
delete[] this->m_brand;
delete[] this->m_model;


}
}