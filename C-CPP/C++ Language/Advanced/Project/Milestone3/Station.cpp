//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca

#include"Station.h"
#include<algorithm>



namespace sdds{
int Station::id_generator=0;
size_t Station::m_widthField=0;
std::string Station::trim(std::string str)
    {
        if (str.find_last_not_of(' ') == str.find_first_not_of(' '))
            return str;
        std::string res = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
		return res;
    }


Station::Station(const std::string& wholeLine){
	Utilities u{};
	size_t next=0;
	bool more=true;
		m_stationId=(++Station::id_generator);
		m_itemName=trim(u.extractToken(wholeLine,next,more));
		m_sNo=stoi(u.extractToken(wholeLine,next,more));
		m_stock=stoi(u.extractToken(wholeLine,next,more));
	Station::m_widthField=std::max(Station::m_widthField,u.getFieldWidth());
		m_stationDesc=trim(u.extractToken(wholeLine,next,more));
	return;
}
const std::string& Station::getItemName() const{return m_itemName;}
size_t Station::getNextSerialNumber(){return m_sNo++;}
size_t Station::getQuantity() const{
	return m_stock;
}
void Station::updateQuantity(){if(m_stock>0)m_stock--;}
void Station::display(std::ostream& os, bool full) const{
	os<<std::setfill('0')<<std::right<<std::setw(3)<<m_stationId;
	os<<" | "<<std::setfill(' ')<<std::left<<std::setw(Station::m_widthField)<<m_itemName;
	os<<" | "<<std::right<<std::setfill('0')<<std::setw(6)<<m_sNo;
	os<<" |";
	if(full){
		os<<" ";
		os<<std::right<<std::setw(4)<<std::setfill(' ')<<m_stock;
		os<<" | "<<m_stationDesc;
	}else os<<" ";
	os<<"\n";
}
}