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


namespace sdds{
    class CleanerBot
    {
        //Data members
        private:
        char* location;
        double battery;
        int noOfBrushes;
        bool active;

        public:
        //Constructors
        CleanerBot();
        CleanerBot(const char* location, double battery, int noOfBrushes, bool active);
		CleanerBot(const CleanerBot &c);
        //Destructors
        ~CleanerBot();

        //Modifiers
        void set(const char* location, double battery, int noOfBrushes, bool active);
        void setLocation(const char* location);
        void setActive(bool isActive);

        //Getters
        char* getLocation();
        double* getBattery();
        int getBrush();
        bool isActive();
        bool isValid() const;

        //Display function
        void display();

        //Utility class functions
    };

    //The stand-alone report function
    void report(CleanerBot* bot,short num_bots);

	
void sort(CleanerBot *bot, short num_bots);

    void displayHeaderNormal();

	void displayLowBatteryWarningHeader(int c);
}