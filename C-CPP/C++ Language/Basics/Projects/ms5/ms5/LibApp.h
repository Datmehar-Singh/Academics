#include "Menu.h"
#include "Publication.h"
#include "Lib.h"

namespace sdds{
    class LibApp{
        private:
		char pubFileName[256];
		Publication* publications[SDDS_LIBRARY_CAPACITY];
		int numOfPublications;
		int tempLibRefNum;
		//Menu pub;
        bool m_changed;
        Menu pubType;
        Menu m_mainMenu;
        Menu m_exitMenu;
        int convertStringToInt(std::string str);

         void load();  // prints: "Loading Data"<NEWLINE>
      void save();  // prints: "Saving Data"<NEWLINE>
      int search(bool all = false, bool isLoan = true); // prints: "Searching for publication"<NEWLINE>
      
      void returnPub();  /*  Calls the search() method.
                       prints "Returning publication"<NEWLINE>
                             prints "Publication returned"<NEWLINE>
                             sets m_changed to true;
                         */
        bool confirm(const char* message);

        public:

        LibApp(const char * filename="\0");
        ~LibApp(){
for( int i=0;i<numOfPublications;i++)
{
delete publications[i];
}
}
        Publication* getPub(int libRef);
        void newPublication();
        void removePublication();
        void checkOutPub();
        void run();

    };
}