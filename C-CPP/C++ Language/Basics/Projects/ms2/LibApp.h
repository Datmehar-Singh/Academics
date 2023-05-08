#include "Menu.h"

namespace sdds{
    class LibApp{
        private:
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

         void load();  // prints: "Loading Data"<NEWLINE>
      void save();  // prints: "Saving Data"<NEWLINE>
      void search();  // prints: "Searching for publication"<NEWLINE>
      
      void returnPub();  /*  Calls the search() method.
                             prints "Returning publication"<NEWLINE>
                             prints "Publication returned"<NEWLINE>
                             sets m_changed to true;
                         */
        bool confirm(const char* message);

        public:

        LibApp();
        ~LibApp(){}
        void newPublication();
        void removePublication();
        void checkOutPub();
        void run();

    };
}