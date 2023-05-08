/*
*****************************************************************************
						Workshop 5 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Power.h"

using namespace std;

namespace sdds {

	/**************Constructors**************/
	Power::Power() {
		this->setEmpty();
	}
	Power::Power(const char* name, int rarity) {
		this->createPower(name, rarity);
	}

	/**************Setters**************/
	void Power::setEmpty() {
		m_name[0] = '\0';
		m_rarity = 0;
	}
	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0) {
			strncpy(this->m_name, name, MAX_NAME_LENGTH);
			this->m_rarity = rarity;
		}
		else {
			this->setEmpty();
		}
	}

	/**************Getters**************/
	const char* Power::checkName() const {
		return m_name;
	}
	int Power::checkRarity() const {
		return m_rarity;
	}

	/**************NULL-Checker**************/
	bool Power::isEmpty() const {
		return (m_name[0] == '\0' || m_rarity == 0 );
	}

	/**************Display Function**************/
	void displayDetails(Power* powers, int size) {
		cout << "List of available powers: " << endl;
		for (int i = 0; i < size; i++) {
			if (!powers[i].isEmpty()) {
				cout << "  Name: " << powers[i].checkName() << ", "
					<< "Rarity: " << powers[i].checkRarity() << endl;
			}
		}
	}
}