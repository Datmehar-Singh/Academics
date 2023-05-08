/*
*****************************************************************************
						Milestone 1
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 19 November 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef UTILITIES_H_
#define UTILITIES_H_

#include<iostream>
#include<fstream>
#include<iomanip>

#include<string>

namespace sdds{
class Utilities{
	size_t m_widthField;
	static char m_delimiter;
public:
	Utilities();
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};

}

#endif