/*
*****************************************************************************
						Workshop 2 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


namespace sdds
{
	struct DateOfBirth
	{
		int day;
		int month;
		int year;
	};

	struct EmployeeData
	{
		char* firstName;
		char* lastName;
	
		struct DateOfBirth dob;

		bool isValidated;
	};

	//This function will check if the file has opened or not and print apt message
	bool beginSearch(const char* filename);

	//This function reads the month of the birthdate with the one entered by the user
	bool readBirthDate(int month);

	//This will sort the list of employees on the basis of their Year of Birth
	void sort();

	//Displays the list of birthdays in the correct format
	void displayBirthdays();

	//Deallocates the dynamically allocated memory
	void deallocate();

	//Ensures that there are no memory leaks and closes the execution of the program
	void endSearch();

    //Util Functions

    //Function to return number of records in the file
    void numOfEmployees();

    //A function to populate the employees array out of the csv file
    void populateEmployeesArr();
    
    void readAndStore(struct EmployeeData* employee);


}