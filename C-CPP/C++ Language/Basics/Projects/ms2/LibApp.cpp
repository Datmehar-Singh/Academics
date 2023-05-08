#include"LibApp.h"

namespace sdds{
     void LibApp::load(){std::cout<<"Loading Data\n";} // prints: "Loading Data"<NEWLINE>
      void LibApp::save(){std::cout<<"Saving Data\n";}  // prints: "Saving Data"<NEWLINE>
      void LibApp::search(){std::cout<<"Searching for publication\n";} // prints: "Searching for publication"<NEWLINE>
      
      void LibApp::returnPub()
      {
        search();
        std::cout<<"Returning publication\n";
        std::cout<<"Publication returned\n";
        m_changed=true;
      }  
        bool LibApp::confirm(const char* message){
            Menu* temp= new Menu(message);
            *temp<<"Yes";
			bool res= (temp->run()==1);
		delete temp;
            return res;
        }

        //public:

        LibApp::LibApp(){
            m_changed=false;

            m_mainMenu.setTitle("Seneca Library Application");
            m_mainMenu<<"Add New Publication";
            m_mainMenu<<"Remove Publication";
            m_mainMenu<<"Checkout publication from library";
            m_mainMenu<<"Return publication to library";

            m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
            m_exitMenu<<"Save changes and exit";
            m_exitMenu<<"Cancel and go back to the main menu";
            load();

        }
        //~LibApp::LibApp(){}
        void LibApp::newPublication(){
            std::cout<<"Adding new publication to library\n";
            //std::cout<<;
            if(confirm("Add this publication to library?")){
                m_changed=true;
                std::cout<<"Publication added\n";
            }
            return;
        }
        void LibApp::removePublication(){
            std::cout<<"Removing publication from library\n";
            //std::cout<<;
			search();
            if(confirm("Remove this publication from the library?")){
                m_changed=true;
                std::cout<<"Publication removed\n";
            }
            return;
        }
        void LibApp::checkOutPub(){
            search();
            if(confirm("Check out publication?"))
            {
                m_changed=true;
                std::cout<<"Publication checked out\n";
            }
        }
        void LibApp::run(){
            int ch=-1;
            do{
				
                ch=m_mainMenu.run();
                switch(ch)
                {
                    case 1:
                    this->newPublication(); break;
                    case 2:
                    this->removePublication(); break;
                    case 3:
                    this->checkOutPub(); break;
                    case 4:
                    this->returnPub(); break;
					default: std::cout<<"invalid choice"; break;
                    case 0:
						{
                        int ch2=-1;
                        bool stopExecution=false;
                        if(m_changed)
                        {
                            ch2=m_exitMenu.run();
                            switch(ch2)
                            {
                                case 1:
                                    save();
                                    stopExecution=true;
                                    break;
								case 2: break;
                                case 0:
                                    if(confirm("This will discard all the changes are you sure?"))
                                        stopExecution=true;
                                    break;
                            }
                            if(stopExecution)
                            {
                                std::cout<<"\n-------------------------------------------\nThanks for using Seneca Library Application";
                                ch=-2;
                            }
                        }
						else{
                            std::cout<<"\n-------------------------------------------\nThanks for using Seneca Library Application";
                            ch=-2;
                        }
							}
                }
                std::cout<<std::endl;
            }while(ch!=-2);
        }
}