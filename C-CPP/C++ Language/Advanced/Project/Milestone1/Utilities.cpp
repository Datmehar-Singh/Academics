// Name: Datmehar Singh
// Seneca Student ID: 108011214
// Seneca email: datmehar-singh@myseneca.ca
// Date of completion: 18 march 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#include"Utilities.h"

namespace sdds {

	 char Utilities::m_delimiter = ',';



   //sets the field width of the current object to the value of the parameter newWidth
   void Utilities::setFieldWidth(size_t newWidth)
   {
      m_widthField = newWidth;
   }
   // returns the field width of the current object
   size_t Utilities::getFieldWidth() const
   {
      return size_t(m_widthField);
   }

	std::string Utilities::trim(const std::string& str) {
		size_t first = str.find_first_not_of(' ');
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, (last - first + 1));
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string extractedToken;
		std::string tempStr = str;
		size_t distance;

		if (tempStr[next_pos] == m_delimiter) {
			more = false;
			throw std::logic_error("ERROR: Delimiter found at 'next_pos'.");
		}
		else if (more) {
			size_t extractNextToken = tempStr.find(m_delimiter, next_pos);
			if (extractNextToken != std::string::npos) {
				distance = extractNextToken - next_pos;
			}
			else {
				distance = tempStr.length() - next_pos;
			}
			extractedToken = tempStr.substr(next_pos, distance);

			if (extractedToken.length() > 0) {
				extractedToken = trim(extractedToken);

				if (extractNextToken != std::string::npos) {
					next_pos = extractNextToken + 1;
					more = true;
				}
				else {
					next_pos = 0u;
					more = false;
				}
				m_widthField = m_widthField > extractedToken.length() ? m_widthField : extractedToken.length();
			}
			else {
				more = false;
				throw std::logic_error("ERROR: Empty token.");
			}
		}

		return extractedToken;
	}


   void Utilities::setDelimiter(char newDelimiter)
   {
      //sets the delimiter for thes class to the character received
      m_delimiter = newDelimiter;
   }

   char Utilities::getDelimiter()
   {//returns the delimiter for this class
      return m_delimiter;
   }

}