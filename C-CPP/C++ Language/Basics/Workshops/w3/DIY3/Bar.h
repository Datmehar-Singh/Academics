/*
*****************************************************************************
						Workshop 3 - Part 2
Full Name  : Khushmeet Singh
Student ID#: 138199211
Email      : khushmeet-singh@myseneca.ca
Date       : 6 May 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


namespace sdds{
    #define TITLE_LEN 20
    class Bar{
        char title[TITLE_LEN];
        char fillChar;
        int val;
        public:
		bool isValid;
        //Bar(){}
        void setEmpty();
        void set(const char*, const char, const int);
        bool isEmpty();

        void draw();
        //~Bar(){}
    };


}