/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

//function to input an int data type and return it after validating that it is an int for sure
int inputInt(void);

//fucntion to input an int which is strictly positive
int inputIntPositive(void);

//function which will return an integer value that will remain in the range
int inputIntRange(int lower_bound , int upper_bound);

//A fucntion which will gaurantee the input of a single character which is present in the cstring
char inputCharOption(char string[]);

//A fucntion which will gaurantee the input of a a cstring whose length is between a given range
void inputCString(char* string , int lower_bound , int upper_bound);

//displays formatted phone number
void displayFormattedPhone(char* const string);

//clears standard input buffer
void clearInputBuffer(void);

void suspend(void);


