//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca

#ifndef STATION_H_
#define STATION_H_
#include"Utilities.h"
#include<cmath>

namespace sdds{

class Station{
int m_stationId;
std::string m_itemName,m_stationDesc;
unsigned int m_sNo,m_stock;
static size_t m_widthField;
static int id_generator;

public:
std::string trim(std::string str);
Station(const std::string& wholeLine);
const std::string& getItemName() const;
size_t getNextSerialNumber();
size_t getQuantity() const;
void updateQuantity();
void display(std::ostream& os, bool full) const;
};
}

#endif
