#include "Power.h"
#include <fstream>
#include<iostream>

namespace sdds {

/*
*****************************************************************************
						Workshop 5 - Part 2
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 19 June 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


class Hero {
private:
  char name[MAX_NAME_LENGTH]; // Name of the hero
  Power *powersArr;           // Array of powers a hero can have
  int numOfPowers;            // number of powers for a hero
  int powersLevel;            // level of powers for a hero

public:
  /******Constructors*********/
  Hero();
  Hero(const char *name, Power *powerArr, int numOfPowers);
  ~Hero() {
    if (powersArr != nullptr)
      delete[] powersArr;
  }

  /******Functions*********/
  std::ostream &display(std::ostream &os) const;

  /*******Operator Overloads*******/
  void operator+=(Power obj);
  int operator-=(int power);
  bool operator<(const Hero &rightObj);
  bool operator>(const Hero &rightObj);
  std::ostream &display()const {
	  return this->display(std::cout);
  }
  friend void operator<<(Hero &leftObj, Power &rightObj);
  friend std::ostream &operator<<(std::ostream &os, Hero rightObj) {
    return rightObj.display(os);
  }
  friend void operator>>(Power &leftObj, Hero &rightObj);
};
} // namespace sdds