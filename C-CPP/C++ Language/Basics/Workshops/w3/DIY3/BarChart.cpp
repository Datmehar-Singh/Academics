/*
*****************************************************************************
						Workshop 3 - Part 2
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 6 May 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include "BarChart.h"
#include<iostream>
#include<cstring>
namespace sdds{

bool BarChart::areAllValid() const
{
	bool res=true;
	for(int i=0;i<this->sizeOfArray;i++)
		{
			res=res&&this->arrayOfBars[i].isValid;
		}
	return res;
}


void BarChart::init(const char* title, int noOfSamples, char fill)
{
	this->arrayOfBars=new Bar[noOfSamples];
	this->title=new char[strlen(title)+1];
	strcpy(this->title,title);
	this->sizeOfArray=noOfSamples;
	this->fillChar=fill;
	this->added=-1;
}

void BarChart::add(const char* bar_title, int value)
{
	this->added++;
	if(this->added==this->sizeOfArray) 
		return;
	else
	{
		this->arrayOfBars[added].set(bar_title,this->fillChar,value);
	}
}
void BarChart::draw()const
{
	if( added+1==this->sizeOfArray)
	{
	std::cout<<this->title<<'\n';
	for(int i=0;i<71;i++)
		std::cout<<"-";
	std::cout<<"\n";
	for(int i=0;i<sizeOfArray;i++)
		arrayOfBars[i].draw();
	for(int i=0;i<71;i++)
		std::cout<<"-";
	std::cout<<"\n";
		}
	else
		std::cout<<"Invalid Chart!\n";
}

void BarChart::deallocate()
{
	delete[] this->title;
	delete[] arrayOfBars;
}
}