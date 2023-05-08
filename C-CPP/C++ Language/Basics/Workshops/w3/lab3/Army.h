/*
*****************************************************************************
						Workshop 3 - Part 1
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
    #define MAX_NAME_LEN 50
    class Army{
        char nationality[MAX_NAME_LEN];
        int noOfUnits;
        double powerOfArmy;

        public:

        //This function sets the army to a safe null pointer state
        void setEmpty();

        //This function will assign the values provided to the function as arguments to the subject of the class
        void createArmy(const char* country, double pow, int troops);

        //This function will update the army by adding the argument to its object's army value
        void updateUnits(int troops);

        //These are the GETTER function for return the data member of the object
        //These function are const function which will not alter the values of the object's data members
        const char* checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;

        //This function will check if the army is initialised to a safe empty state
        bool isEmpty() const;

        //This function will return true of the army of the calling object is more that the received one
        bool isStrongerThan(const Army& army)const;


    };

    //This function will make the two object of the army fight and will start the battle between the two arguments
    void battle( Army& arm1, Army& arm2);

    //This function will display the army in the array of armies in a desired format
    void displayDetails(const Army* armies, int size);
}