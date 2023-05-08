/*
*****************************************************************************
						Workshop 10 - Part 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
namespace sdds {
	//Find with 3 parameters

	//class TemplateFunctions{
	template <typename T,typename U>
	bool find(sdds::Collection<T> arr,int idx,U valueAtKey)
	{
		return arr[idx]==valueAtKey;
	}


	//Find with 4 parameters
	template <typename T,typename U,typename V>
	int find(sdds::Collection<T> arr,int size,U valueAtKey1,V valueAtKey2)
	{
		for(int i=0;i<size;i++)
		{
			if(arr[i]==valueAtKey1 && arr[i]==valueAtKey2)
				return i;
		}
		return -1;
	}


	//Insertion operator
	template <typename T>
	std::ostream& operator<<(std::ostream& os,Collection<T> arr)
	{
		for( int i=0;i<arr.size();i++)
			os<<arr[i]<<std::endl;

		return os;
	}

	//his function takes a reference to a collection (of template type 1) and an object of the same type. It will then call the overloaded += operator in the collections class to add the new item.

//This function returns a constant collection reference.

	//Load Collection
	template <typename T>
	const Collection<T>& loadCollection(Collection<T>& arr,T obj){
		arr+=obj;
		return arr;
	}

	//};
}
#endif // !SDDS_SEARCH_H_

