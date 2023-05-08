//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca

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