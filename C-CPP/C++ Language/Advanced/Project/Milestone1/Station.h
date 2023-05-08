// Name: Datmehar Singh
// Seneca Student ID: 108011214
// Seneca email: datmehar-singh@myseneca.ca
// Date of completion: 18 march 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include<iostream>
#include <string>
#include "Utilities.h"

namespace sdds {


	class Station
	{
	public:

		Station(const std::string& str);
		const std::string& getItemName()const;
		size_t getQuantity()const;
		size_t getNextSerialNumber();
		void updateQuantity();
		void display(std::ostream& os, bool full)const;

	private:
		//instance variables also called a non-static member,
		int m_id{};
		std::string m_name{};
		std::string m_description{};
		size_t m_serialNumber{};
		size_t m_currentItemNum{};
		//class variables
		static size_t m_widthField ;
		static size_t id_generator;

	};

}

#endif // !SDDS_STATION_H

