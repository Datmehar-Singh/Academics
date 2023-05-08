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


// #include"Menu.h"
// #include<iostream>
// #include<iomanip>
// #include<cstring>

// namespace sdds{

    
//     /*=======MENU ITEM CLASS===========*/
    
//     MenuItem::MenuItem(const char* desc){
//         if(desc!=nullptr)
//         {
//             itemName=new char[strlen(desc)+1];
//             strcpy(itemName,desc);
//         }
//         else 
// 		{
			
// 			//itemName=new char[10];
//             		//strcpy(itemName,"");
// 		itemName=nullptr;
// 		}
//     }
//     MenuItem::~MenuItem(){
//         delete[] itemName;
//     }
//     MenuItem::operator bool(){
//         return itemName!=nullptr;
//     }
//     MenuItem::operator const char*(){
//         return itemName;
//     }
//     void MenuItem::display(std::ostream& os){
//         if(itemName!=nullptr) os<<itemName;
//     }

//     /*=======MENU CLASS===========*/

//     Menu::Menu(){
//         size=0;
		
//     }
//     Menu::Menu(const char* title){
		
// 		this->title.itemName=new char[strlen(title)+1];
//         strcpy(this->title.itemName,title);
//         size=0;
//     }
//     Menu::~Menu(){
	
// 	for( int i=0;i<size;i++)
// {
// delete arr[i];
// }
//     }
// bool checker=true;
//     std::ostream& Menu::displayTitle(std::ostream& os){
// 		checker=true;
// 		//if(this->title)
// 		//std::cout<<"+++"<<(const char*)title<<"++";
//         //if(strcmp("",(const char*)(this->title))){
// 	if((const char*)(this->title)==nullptr)
// 			checker=false;
		

// 		else
// 		os<<(const char*)(this->title);
// 		return os;
//     }
//     /*This function first displays the title (if it is not empty) followed by a ":" and a new-line, then it will display all the MenuItems one by one; adding a row number in front of each. The row numbers are printed in two spaces, right justified followed by a "dash" and a "space". After printing all the MenuItems it should print " 0- Exit" and new-line and "> ".
// For example if the title is "Lunch Menu" and the menu items are "Omelet", "Tuna Sandwich" and "California Rolls", the Menu object should be printed like this:*/
//     void Menu::displayMenu(){
		
//         this->displayTitle(std::cout);

// 		if(checker)
//         std::cout<<":\n";
//         for(int i=0;i<size;i++)
//         {
//             std::cout<<std::setfill(' ')<<std::setw(2)<<std::right<<i+1;
//             std::cout<<"- "<<(const char *)(*arr[i])<<'\n';   
//         }
//         std::cout<<" 0- Exit\n> ";
//     }
//     unsigned int Menu::run(){
//         displayMenu();
//         int res=takeInputIntegerRange(size);
//         return res;
//     }
//     int Menu::operator~(){
//        return this->run();
//     }
//     Menu& Menu::operator<<(const char* menuItemContent){
//         if(size<MAX_MENU_ITEMS)
//         {

// 			this->arr[size]=new MenuItem(menuItemContent);
		
//             //this->arr[size]->itemName=new char[strlen(menuItemContent)+1];
//             //strcpy(this->arr[size]->itemName,menuItemContent);
// 	size++;
//         }
//         return *this;
//     }
// int takeInputIntegerRange(int max){
//         int res=0;
//         bool flag=true;
// 		std::string input;
//         while(flag)
//         {
// 			std::getline(std::cin,input);
//             if( input.size()==1 && input[0]>=48 && input[0]<=48+max)
//             {
// 				res=input[0]-48;
//                 flag=false;
//             }
//             else{
//                 std::cout<<"Invalid Selection, try again: ";
//             }
//         }
// 	//std::cin>>res;
//         return res;
//     }
//     Menu::operator int(){
//         return size;
//     }
//     Menu::operator unsigned int(){
//         return size;
//     }
//     Menu::operator bool(){
//         return size>0;
//     }
//     const char* Menu::operator[](int i) const{
		
// 		//this->arr[i]->display(std::cout);
//         return (const char*)(*(this->arr[i]));
//     }
//     std::ostream& operator<<(std::ostream& os,Menu& M)
//     {
//         ///os<<(const char*)M.title;
		
// 		//std::cout<<"hello this is called";
//          return M.displayTitle(os);
// 		//return os;
//     }
// }