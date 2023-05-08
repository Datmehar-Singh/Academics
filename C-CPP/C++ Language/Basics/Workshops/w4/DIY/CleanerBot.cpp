/*
*****************************************************************************
						Workshop 4 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#include "CleanerBot.h"
#include <cstring>
#include <iomanip>
#include <iostream>
namespace sdds {

// Constructors
CleanerBot::CleanerBot() {
  this->location = nullptr;
  this->battery = 0.0;
  this->noOfBrushes = 0;
  this->active = false;
}
CleanerBot::CleanerBot(const char *location, double battery, int noOfBrushes,
                       bool active) {
  if (location != nullptr ) {
    this->location = new char[strlen(location)+1];
    strcpy(this->location, location);
  } else
    this->location = nullptr;
  this->battery = battery;
  this->noOfBrushes = noOfBrushes;
  this->active = active;
}
CleanerBot::CleanerBot(const CleanerBot& c) {
  if (c.isValid())  {
	std::cout<<"\n\n\n"<<c.battery;
	std::cout<<c.location[0]<<"\n\n\n";
    this->location = new char[strlen(c.location)+1];
    strcpy(this->location,c.location );
  } else
    this->location = nullptr;



  this->battery = c.battery;
  this->noOfBrushes = c.noOfBrushes;
  this->active = c.active;
}

// Destructors
CleanerBot::~CleanerBot() { 
if(this->location!=nullptr && this->location[0]!='\0')
{
std::cout<<"\n\n"<<this->location<<"\n\n";
	delete[] this->location; 
}
}

// Modifiers
void CleanerBot::set(const char *location, double battery, int noOfBrushes,
                     bool active) {
  if (location != nullptr) {
    delete[] this->location;
  }
  this->location = new char[strlen(location)];
  strcpy(this->location, location);
  this->battery = battery;
  this->noOfBrushes = noOfBrushes;
  this->active = active;
}
void CleanerBot::setLocation(const char *location) {
  if (location != nullptr) {
    delete[] this->location;
  }
  this->location = new char[strlen(location)];
  strcpy(this->location, location);
}
void CleanerBot::setActive(bool isActive) { this->active = isActive; }

char *CleanerBot::getLocation() { return this->location; }
double *CleanerBot::getBattery() { return &this->battery; }
int CleanerBot::getBrush() { return this->noOfBrushes; }
bool CleanerBot::isActive() { return this->active; }
bool CleanerBot::isValid() const {
  bool locationFlag = this->location != nullptr,
       batteryFlag = (this->battery >= 0.0 && this->battery <= 100.0),
       brushFlag = this->noOfBrushes > 0;

  return locationFlag && batteryFlag && brushFlag;
}

void CleanerBot::display() {
  std::cout << "| " << std::setw(11) << this->location << std::right;
  std::cout << "| " << std::setw(7) << std::fixed << std::setprecision(1)
            << this->battery;
  std::cout << " | " << std::setw(18) << this->noOfBrushes << std::left;
  std::cout << " | " << std::setw(6) << (this->isActive() ? "YES" : "NO")
            << " |\n";
}

void report(CleanerBot *bot, short num_bots) {
  int lowBatteryCounter = 0;
  displayHeaderNormal();
  for (int i = 0; i < num_bots; i++) {
    if ((bot + i)->isValid()) {
      bot[i].display();

      if (*bot[i].getBattery() < 30.0)
        lowBatteryCounter++;
    }
  }
  std::cout << "\n";
  if (lowBatteryCounter) {
    displayLowBatteryWarningHeader(lowBatteryCounter);
    sort(bot, num_bots);
    for (int i = 0; i < num_bots; i++) {
      if ((bot + i)->isValid()) {
        bot[i].display();
      }
    }
	  
  std::cout <<"|"<< std::setw(52) << std::setfill('=') << "="<<"|";
	  
  }
}
CleanerBot temp;
void sort(CleanerBot *bot, short num_bots) {
        
  for (int i = 0; i < num_bots-1; i++) {
    for (int j = i+1 ; j < num_bots ; j++) {
	if(bot[i].isValid()&&bot[j].isValid())
      if (*(bot[i].getBattery()) < *(bot[j].getBattery())) 
      {

	temp = bot[i];
        bot[i] = bot[j];
        bot[j] = temp;
	//delete[] temp.location;
      }
    }
  }
}

void displayHeaderNormal() {
  std::cout << std::setw(42) << "------ Cleaner Bots Report -----\n";
  std::cout << "     " << std::setw(40) << std::setfill('-') << '\n';
  //<<std::setfill('-')

  // std::left;

  std::cout << "|" << " Location"<<std::setfill(' ');
  std::cout << "   | " << std::setw(7) << "Battery" << std::left;
  std::cout << " | " << std::setw(14) << " Number of Brushes";
  std::cout << " | " << std::setw(6) << "Active |\n";

  std::cout << "|------------+---------+--------------------+--------|\n";
}
void displayLowBatteryWarningHeader(int c) {
  //  std::cout << "|" ;
  //   std::cout<< std::setfill('=')<< std::setw(70) ;
  // std::cout << std::setw(1)<<"|" ;

  std::cout << std::setw(53) << std::setfill('=') << "|";
  std::cout << std::setw(55) << std::setfill(' ') << "|\n| LOW BATTERY WARNING:"
            << "|\n";
  std::cout << std::setw(53) << std::setfill('=') << "|";
  std::cout << "|\n" << std::left;
  std::cout << "| Number of robots to be charged: " << c <<std::setfill(' ')<<std::setw(18)<<" ";
            //int i=std::cout.width(18);
  std::cout << "|\n| Sorting robots based on their available power:"
            << std::setw(5) <<  " ";

  std::cout << "|\n|"
            << " Location " ;
	std::cout.width(3) ;
	//std::cout<< ;
  std::cout << "  | " << std::setw(7) << "Battery" << std::left;
  std::cout << " | " << std::setw(16) << " Number of Brushes";
  std::cout << " | " << std::setw(6) << "Active |\n";

  std::cout << "|------------+---------+--------------------+--------|\n";
	

}
} // namespace sdds