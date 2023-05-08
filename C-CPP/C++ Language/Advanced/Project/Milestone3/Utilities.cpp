//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca

#include"Utilities.h"

namespace sdds{
	char Utilities::m_delimiter=',';
	Utilities::Utilities(){m_widthField=1;}
	void Utilities::setFieldWidth(size_t newWidth){m_widthField=newWidth;}
	size_t Utilities::getFieldWidth() const{return m_widthField; }
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
		// if(str.rfind(m_delimiter)==-1) more=false;
		if(str.find(m_delimiter,next_pos+1)>str.length()) {more=false;}
		if(str[next_pos]==m_delimiter) {
			more=false;throw std::string ("!*******EXCEPTION::Delimiter found at next_pos in UTILITIES MODULE*******!");}
		auto res=str.substr(next_pos,str.find(m_delimiter,next_pos+1)-next_pos);
		next_pos=str.find(m_delimiter,next_pos+1)+1;
		if(res.size()>m_widthField) m_widthField=res.size();
		return res;
	}
	void Utilities::setDelimiter(char newDelimiter){m_delimiter=newDelimiter;}
	 char Utilities::getDelimiter(){return m_delimiter;}
}