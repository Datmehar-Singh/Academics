/*
*****************************************************************************
						Workshop 7 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "CrimeStatistics.h"

namespace sdds{
std::string trim(std::string str)
    {
        if (str.find_last_not_of(' ') == str.find_first_not_of(' '))
            return str;
        std::string res = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
		return res;
    }

CrimeStatistics::CrimeStatistics(std::string filename){
	
	std::ifstream fptr(filename);
	
	std::string wholeLine{};
	if(fptr.is_open())
	{
		struct Crime c{};
		while(std::getline(fptr,wholeLine))
		{
			c.m_province=trim(wholeLine.substr(0,25));
			c.m_district=trim(wholeLine.substr(25,25));
			c.m_crime=trim(wholeLine.substr(50,25));
			
			c.m_year=stoi(wholeLine.substr(75,5));
			c.m_numOfCases=stoi(wholeLine.substr(80,5));
			c.m_resolved=stoi(wholeLine.substr(85,5));
			
		crimes.push_back(c);
		}
	}//is_open(filename)
	else{
		throw std::string("!********EXCEPTION::File not found******!");
	}
}
void CrimeStatistics::display(std::ostream& out) const{
	// out<<"size is "<<crimes.size();
	int totCrimes=0, resCrimes=0;
	for_each(crimes.begin(),crimes.end(),[&out,&totCrimes, &resCrimes](struct Crime c)//can also be done using the copy fucntion but this makes it more readable
	{
		out<<c<<std::endl;
		totCrimes+=c.m_numOfCases;
		resCrimes+=c.m_resolved;
	});
	std::cout<<"----------------------------------------------------------------------------------------\n";
	out<<"|                                                                 Total Crimes:"<<std::setw(7)<<totCrimes<<" |\n";
	out<<"|                                                         Total Resolved Cases:"<<std::setw(7)<<resCrimes<<" |\n";
	return;
}
std::ostream& operator<<(std::ostream& out, const Crime& theCrime){
	out<<"| "<<std::left<<std::setw(21)<<theCrime.m_province;
	out<<" | "<<std::setw(15)<<theCrime.m_district;
	out<<" | "<<std::setw(20)<<theCrime.m_crime;
	out<<" | "<<std::right<<std::setw(6)<<theCrime.m_year;
	out<<" | "<<std::setw(4)<<theCrime.m_numOfCases;
	out<<" | "<<std::setw(3)<<theCrime.m_resolved;
	out<<" |";
	return out;
}
void CrimeStatistics::sort(std::string fieldName){
	if(fieldName == "Province"){
		std::sort(crimes.begin(),crimes.end(),[](struct Crime c1,struct Crime c2){
			return c1.m_province<c2.m_province;});
	}else if(fieldName=="Crime"){
		std::sort(crimes.begin(),crimes.end(),[](struct Crime c1,struct Crime c2){return c1.m_crime<c2.m_crime;});
	}else if(fieldName=="Cases"){
		std::sort(crimes.begin(),crimes.end(),[](struct Crime c1,struct Crime c2){return c1.m_numOfCases<c2.m_numOfCases;});
	}else if(fieldName=="Resolved"){
		std::sort(crimes.begin(),crimes.end(),[](struct Crime c1,struct Crime c2){return c1.m_resolved<c2.m_resolved;});
	}
	return;
}

void CrimeStatistics::cleanList(){
	std::vector<Crime> vecRes{};
	// std::copy_if(crimes.begin(),crimes.end(),std::back_inserter(vecRes),[](struct Crime c){
	// 	return c.m_crime!="[None]";
	// });
	// crimes.clear();
	// std::cout<<"SIZE OF RES ARR IS "<<vecRes.size();
	// copy(vecRes.begin(),vecRes.end(),std::back_inserter(crimes));
	for_each(crimes.begin(),crimes.end(),[](struct Crime& c){
		if(c.m_crime=="[None]"){
			c.m_crime.erase();
		}
	});
	return;
	
}
bool CrimeStatistics::inCollection(std::string crimeName) const{
	bool res=false;
	for_each(crimes.begin(),crimes.end(),[&res,crimeName](struct Crime c){
		if(c.m_crime==crimeName){
			res=true;
		}
	});
	return res;
}

std::vector<Crime> CrimeStatistics::getListForProvince(std::string provinceName) const{
	std::vector<Crime> res;
copy_if(crimes.begin(),crimes.end(),std::back_inserter(res),[provinceName](struct Crime c){
		return c.m_province==provinceName;
	});
	return res;
}

}