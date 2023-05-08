// /*
// *****************************************************************************
// 						Milestone 3
// Full Name  : Datmehar Singh
// Student ID#: 108011214
// Email      : datmehar-singh@myseneca.ca
// Section    : NHH

// Authenticity Declaration:
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// *****************************************************************************
// */


// #include<iostream>

// namespace sdds{

//     #define MAX_MENU_ITEMS 20

//     class MenuItem{
//     private:
//     char* itemName;
//     friend class Menu;
    

//     MenuItem(const char* desc=nullptr);
//     MenuItem& operator=(const MenuItem&) = delete;
//     MenuItem(const MenuItem&) = delete;
//     ~MenuItem();
//     operator bool();
//     operator const char*();
//     void display(std::ostream& os);
// };

// class Menu{
//     private:
//     MenuItem title;
//     MenuItem* arr[MAX_MENU_ITEMS];
//     int size;

//     public:
//     Menu();
//     Menu(const char* title);
//     ~Menu();

//     std::ostream& displayTitle(std::ostream& os);
//     void displayMenu();
//     unsigned int run();
//     int operator~();
//     Menu& operator<<(const char*);
//     operator int();
//     operator unsigned int();
//     operator bool();
//     const char* operator[](int i) const;

   
// };
//  std::ostream& operator<<(std::ostream&,Menu&);
// int takeInputIntegerRange(int max);
// }