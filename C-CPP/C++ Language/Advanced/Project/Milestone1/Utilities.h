// Name: Idriss Lufungula
// Seneca Student ID: 151838208
// Seneca email: ilufungula@myseneca.ca
// Date of completion: 15 march 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include<iostream>

namespace sdds {
	class Utilities
	{
	public:
	/*	Utilities();
		~Utilities();*/
		void setFieldWidth(size_t newWidth);  
		size_t getFieldWidth() const;       
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);   //extract token from string str referred to by the first parameter.
		//class functions
		static void setDelimiter(char newDelimiter);  
		static char getDelimiter();
		std::string trim(const std::string& str);

	private:
		size_t m_widthField = 1u;       //specifies the lemght of the token extracted
		static char m_delimiter;        //separates the tokens in any given std::string object
	};



}



#endif // !SDDS_UTILITIES_H

