//#define _CRT_SECURE_NO_WARNINGS
//#include"LibApp.h"
//#include"Book.h"
//#include<fstream>
//
//namespace sdds{
//     void LibApp::load(){std::cout<<"Loading Data\n";
//     
//     ifstream infile(pubFileName);
//     char type{};
//     int i;
//     for (i = 0; infile; i++) {
//         infile >> type;
//         infile.ignore();
//         if (infile) {
//             /*if (type == 'P')
//             else if (type == 'B')*/
//                 //publications[i] = new Book;
//                 publications[i] = new Publication;
//             if (publications[i]) {
//                 int libRef = -1, membership = -1;
//                 char shelfId[20], title[200];
//                 Date date{};
//                 char tabSpace = '\t';
//
//                 std::string  fileRead;
//                 std::getline(infile, fileRead, '\t');
//                 libRef = convertStringToInt(fileRead);
//                 std::getline(infile, fileRead, tabSpace);
//                 strcpy(shelfId, fileRead.c_str());
//                 std::getline(infile, fileRead, tabSpace);
//                 strcpy(title, fileRead.c_str());
//                 std::getline(infile, fileRead, tabSpace);
//                 membership = convertStringToInt(fileRead);
//                 infile >> publications[numOfPublications]->m_date;
//
//                 strcpy(publications[numOfPublications]->m_shelfId, shelfId);
//                 strcpy(publications[numOfPublications]->m_title, title);
//                 publications[numOfPublications]->m_libRef = libRef;
//                 publications[numOfPublications]->m_membership = membership;
//                 numOfPublications++;
//             }
//         }
//     }
//
//     } // prints: "Loading Data"<NEWLINE>
//      void LibApp::save(){
//          std::cout<<"Saving Data\n";
//
//          ofstream outfile(pubFileName);
//          for (int i = 0;i < numOfPublications;i++)
//          {
//              if (publications[i]->getRef())
//              {
//                  outfile << publications[i]->type() << '\t' << publications[i]->m_libRef << '\t' << publications[i]->m_shelfId << '\t' << publications[i]->m_title << '\t';
//                  bool mFlag = (publications[i]->m_membership == 0);
//                  if (mFlag) {
//                      outfile << "N/A";
//                  }
//                  else {
//                      outfile << publications[i]->m_membership;
//                  }
//                  outfile << '\t' << publications[i]->m_date;
//              }
//          }
//
//
//      }  // prints: "Saving Data"<NEWLINE>
//      void LibApp::search(bool all,bool isLoan)//by default on search by loan
//      {
//          char title[256] = "\0";
//          int ch=pubType.run();
//          char typeChoice = (ch == 1) ? 'B' : 'P';
//
//          std::cout << "Publication Title: ";
//          cin.getline(title,256);
//          std::cout<<"Searching for publication\n";
//          
//
//          if (all)
//          {
//              for (int i = 0;i < numOfPublications;i++)
//              {
//                  if (strstr(publications[i]->m_title, title) != NULL && typeChoice==publications[i]->type())
//                  {
//                      publications[i]->write(std::cout);
//                  }
//              }
//          }
//          else if (all == false && isLoan == true)
//          {
//              for (int i = 0;i < numOfPublications;i++)
//              {
//                  if (strstr(publications[i]->m_title, title) != NULL   &&  publications[i]->m_membership != 0 && typeChoice == publications[i]->type())
//                  {
//                      publications[i]->write(std::cout);
//                  }
//              }
//          }
//          else if (all == false && isLoan == false)
//          {
//              for (int i = 0;i < numOfPublications;i++)
//              {
//                  if (strstr(publications[i]->m_title, title) != NULL && publications[i]->m_membership == 0 && typeChoice == publications[i]->type())
//                  {
//                      publications[i]->write(std::cout);
//                  }
//              }
//          }
//      } // prints: "Searching for publication"<NEWLINE>
//
//      void LibApp::returnPub()
//      {
//        search();
//        std::cout<<"Returning publication\n";
//        std::cout<<"Publication returned\n";
//        m_changed=true;
//      }  
//
//       int convertStringToInt(string str)
//      {
//          int res = 0;
//          for (unsigned int i = 0;i < str.length();i++)
//          {
//              res = res * 10 + (str[i] - '0');
//          }
//          return res;
//      }
//       Publication* LibApp::getPub(int libRef) {
//           for (int i = 0;i < numOfPublications;i++)
//           {
//               if (publications[i]->m_libRef == libRef) return publications[i];
//           }
//       }
//
//
//        bool LibApp::confirm(const char* message){
//            Menu* temp= new Menu(message);
//            *temp<<"Yes";
//			bool res= (temp->run()==1);
//		delete temp;
//            return res;
//        }
//
//        //public:
//
//        LibApp::LibApp(const char * filename){
//            m_changed=false;
//
//			strcpy(pubFileName,"\0");
//
//			if(filename!=nullptr)
//			strcpy(pubFileName,filename);
//
//            std::ifstream is{};
//            is.open(filename);
//
//            numOfPublications= 0;
//
//            while (!is.eof() ) {
//                int libRef = -1,membership=-1;
//                char shelfId[20], title[200];
//                Date date{};
//                char tabSpace = '\t';
//
//                std::string  fileRead;
//                std::getline(is, fileRead, '\t');
//                libRef = convertStringToInt(fileRead);
//                std::getline(is, fileRead, tabSpace);
//                strcpy(shelfId, fileRead.c_str());
//                std::getline(is, fileRead, tabSpace);
//                strcpy(title, fileRead.c_str());
//                std::getline(is, fileRead, tabSpace);
//                membership = convertStringToInt(fileRead);
//                is >> publications[numOfPublications]->m_date;
//
//                strcpy(publications[numOfPublications]->m_shelfId, shelfId);
//                strcpy(publications[numOfPublications]->m_title, title);
//                publications[numOfPublications]->m_libRef = libRef;
//                publications[numOfPublications]->m_membership = membership;
//
//                this->numOfPublications++;
//
//                tempLibRefNum = libRef;
//            }
//			
//            m_mainMenu.setTitle("Seneca Library Application");
//            m_mainMenu<<"Add New Publication";
//            m_mainMenu<<"Remove Publication";
//            m_mainMenu<<"Checkout publication from library";
//            m_mainMenu<<"Return publication to library";
//
//            m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
//            m_exitMenu<<"Save changes and exit";
//            m_exitMenu<<"Cancel and go back to the main menu";
//
//            pubType.setTitle("Choose the type of publication:");
//            pubType << "Book";
//            pubType << "Publication";
//            load();
//
//        }
//        //~LibApp::LibApp(){}
//        void LibApp::newPublication(){
//            if (SDDS_LIBRARY_CAPACITY == numOfPublications) {
//                std::cout << "Library is at its maximum capacity!\n";
//                return;
//            }
//
//            std::cout<<"Adding new publication to library\n";
//            //std::cout<<;
//            Publication* pubTemp=nullptr;
//            int ch = pubType.run();
//            char typeChoice = (ch == 1) ? 'B' : 'P';
//
//            if (typeChoice == 'P')
//                pubTemp = new Publication;
//            else if (typeChoice == 'B')
//                pubTemp = new Book;
//            pubTemp->read(std::cin);
//            if (std::cin.fail()) {
//                std::cin.ignore();
//                std::cout << "Aborted!";
//                exit(101);
//            }
//            if(confirm("Add this publication to library?")){
//
//                if (pubTemp) {
//                    m_changed = true;
//                    tempLibRefNum++;
//                    pubTemp->m_libRef = tempLibRefNum;
//                    publications[numOfPublications++] = pubTemp;
//                    m_changed = true;
//                    std::cout << "Publication added\n";
//                }
//                else {
//                    std::cout << "Failed to add publication!\n";
//                }
//            }
//            else {
//                std::cout << "Aborted!";
//                exit(101);
//            }
//            return;
//        }
//        void LibApp::removePublication(){
//            std::cout<<"Removing publication from library\n";
//            //std::cout<<;
//			search();
//            if(confirm("Remove this publication from the library?")){
//                m_changed=true;
//                std::cout<<"Publication removed\n";
//            }
//            return;
//        }
//        void LibApp::checkOutPub(){
//            search();
//            if(confirm("Check out publication?"))
//            {
//                m_changed=true;
//                std::cout<<"Publication checked out\n";
//            }
//        }
//        void LibApp::run(){
//            int ch=-1;
//            do{
//				
//                ch=m_mainMenu.run();
//                switch(ch)
//                {
//                    case 1:
//                    this->newPublication(); break;
//                    case 2:
//                    this->removePublication(); break;
//                    case 3:
//                    this->checkOutPub(); break;
//                    case 4:
//                    this->returnPub(); break;
//					default: std::cout<<"invalid choice"; break;
//                    case 0:
//						{
//                        int ch2=-1;
//                        bool stopExecution=false;
//                        if(m_changed)
//                        {
//                            ch2=m_exitMenu.run();
//                            switch(ch2)
//                            {
//                                case 1:
//                                    save();
//                                    stopExecution=true;
//                                    break;
//								case 2: break;
//                                case 0:
//                                    if(confirm("This will discard all the changes are you sure?"))
//                                        stopExecution=true;
//                                    break;
//                            }
//                            if(stopExecution)
//                            {
//                                std::cout<<"\n-------------------------------------------\nThanks for using Seneca Library Application";
//                                ch=-2;
//                            }
//                        }
//						else{
//                            std::cout<<"\n-------------------------------------------\nThanks for using Seneca Library Application";
//                            ch=-2;
//                        }
//							}
//                }
//                std::cout<<std::endl;
//            }while(ch!=-2);
//        }
//}

#define _CRT_SECURE_NO_WARNINGS
#include"LibApp.h"
#include"Book.h"
#include"PublicationSelector.h"
#include<fstream>

namespace sdds {
    int LibApp::convertStringToInt(string str)
    {
        int res = 0;
        for (unsigned int i = 0;i < str.length();i++)
        {
            res = res * 10 + (str[i] - '0');
        }
        return res;
    }
    void LibApp::load() {
        std::cout << "Loading Data\n";
	for( int i=0;i<SDDS_LIBRARY_CAPACITY;i++)
	{
	if(publications[i]!=nullptr){
	delete publications[i];
	publications[i]=nullptr;
}
}

        std::ifstream infile(pubFileName);
        // infile.open("LibRecs.txt");
        char type{};
        int i;
        //std::cout << "lvl1";
        for (i = 0; infile; i++) {
            infile >> type;
            infile.ignore(200, '\t');
            if (infile) {
                if (type == 'P') {
                    publications[i] = new Publication;
                }
                else if (type == 'B') {
                    //std::cout << "\n\n//\n\n";
                    publications[i] = new Book;
                }
                int libRef = -1, membership = -1;
                char shelfId[20] = "\0", title[200] = "\0";
                //Date date{};


                std::string  fileRead;
                std::getline(infile, fileRead, '\t');
                //std::cout << "" << fileRead;
                libRef = convertStringToInt(fileRead);
                std::getline(infile, fileRead, '\t');
                strcpy(shelfId, fileRead.c_str());
                std::getline(infile, fileRead, '\t');
                if (fileRead[fileRead.length() - 1] > 47 && fileRead[fileRead.length() - 1] < 58)//catering the case where there is space between title and memId
                {
                    int breakPoint = fileRead.rfind(" ");
                    strcpy(title, fileRead.substr(0, breakPoint).c_str());
                    membership = convertStringToInt(fileRead.substr(breakPoint + 1));
                }
                else {
                    strcpy(title, fileRead.c_str());
                    std::getline(infile, fileRead, '\t');
                    membership = convertStringToInt(fileRead);
                }
                infile >> publications[numOfPublications]->m_date;
		if(type=='B')
				{
					infile.ignore(1);
					std::getline(infile,fileRead,'\n');
					publications[numOfPublications]->setAuthName(fileRead.c_str());
					//strcpy(publications[numOfPublications]->authorName,fileRead);
				}


		                else infile.ignore(200, '\n');
                //P	1093	P008	Canadian Running Magazine	77051	2021-11-25
                 // if (type == 'B'){
                    //  }

                strcpy(publications[numOfPublications]->m_shelfId, shelfId);
                strcpy(publications[numOfPublications]->m_title, title);
                publications[numOfPublications]->m_libRef = libRef;
                publications[numOfPublications]->m_membership = membership;
                numOfPublications++;
		tempLibRefNum=libRef;
                //std::cout << "lvl1";
                //std::cout<<"\n--"<<publications[numOfPublications-1]->m_title;
                 //}
            }
        }

/*
        for (int j = 0;j < numOfPublications;j++)
        {
            std::cout << "BYEEEEEEEEEEEEEEEEEEEEEE\n" << j;
            std::cout << publications[j]->m_title;
        }
*/
    } // prints: "Loading Data"<NEWLINE>
    void LibApp::save() {
        std::cout << "Saving Data\n";

        ofstream outfile(pubFileName);
        for (int i = 0;i < numOfPublications;i++)
        {
	if(publications[i]!=nullptr)
            if (publications[i]->getRef())
            {
                outfile << publications[i]->type() << '\t' ;
outfile<< publications[i]->getRef()<< '\t' ;
outfile<< publications[i]->shelfId() << '\t' ;
outfile<< publications[i]->title()<< '\t';
                bool mFlag = (publications[i]->m_membership == 0);
                if (mFlag) {
                    outfile << "0";
                }
                else {
                    outfile << publications[i]->m_membership;
                }
                outfile << '\t' << publications[i]->m_date ;
		if(publications[i]->type()=='B')
		{
		outfile<<"\t"<<publications[i]->returnAuthName();
		}
		outfile<<"\n";
            }
        }


    }  // prints: "Saving Data"<NEWLINE>
    int LibApp::search(bool all, bool isLoan)//by default on by loan
    {
        char title[256] = "\0";
        int ch = pubType.run();
        char typeChoice = (ch == 1) ? 'B' : 'P';

        std::cout << "Publication Title: ";
        cin.getline(title, 256);
        PublicationSelector pubSel("Select one of the following found matches:");


        if (all)
        {
            for (int i = 0;i < numOfPublications;i++)
            {
                if (strstr(publications[i]->m_title, title) != NULL && typeChoice == publications[i]->type())
                {
                    pubSel<<publications[i];
                }
            }
        }
        else if (all == false && isLoan == true)
        {
            for (int i = 0;i < numOfPublications;i++)
            {
                if (strstr(publications[i]->m_title, title) != NULL && publications[i]->m_membership != 0 && typeChoice == publications[i]->type())
                {
                    pubSel<<publications[i];
                }
            }
        }
        else if (all == false && isLoan == false)
        {
            for (int i = 0;i < numOfPublications;i++)
            {
                if (strstr(publications[i]->m_title, title) != NULL && publications[i]->m_membership == 0 && typeChoice == publications[i]->type())
                {
                    pubSel<<publications[i];
                }
            }
        }
	pubSel.sort();
        return pubSel.run();
    } // prints: "Searching for publication"<NEWLINE>

    void LibApp::returnPub()
    {

        ofstream outfile(pubFileName);

        std::cout << "Returning publication\n";
        std::cout << "Publication returned\n";
        m_changed = true;
    }

    int convertStringToInt(string str)
    {
        int res = 0;
        for (unsigned int i = 0;i < str.length();i++)
        {
            res = res * 10 + (str[i] - '0');
        }
        return res;
    }
    Publication* LibApp::getPub(int libRef) {
        for (int i = 0;i < numOfPublications;i++)
        {
            if (publications[i]->m_libRef == libRef) return publications[i];
        }
        return nullptr;
    }


    bool LibApp::confirm(const char* message) {
        Menu* temp = new Menu(message);
        *temp << "Yes";
        bool res = (temp->run() == 1);
        delete temp;
        return res;
    }

    //public:

    LibApp::LibApp(const char* filename) {
        m_changed = false;

        strcpy(pubFileName, "\0");

        if (filename != nullptr)
            strcpy(pubFileName, filename);

	for(int i=0;i<SDDS_LIBRARY_CAPACITY;i++)
		publications[i]=nullptr;
        std::ifstream is{};
        is.open(filename);

        numOfPublications = 0;

        // while (!is.eof() ) {
        //     int libRef = -1,membership=-1;
        //     char shelfId[20], title[200];
        //     Date date{};
        //     char tabSpace = '\t';

        //     std::string  fileRead;
        //     std::getline(is, fileRead, '\t');
        //     libRef = convertStringToInt(fileRead);
        //     std::getline(is, fileRead, tabSpace);
        //     strcpy(shelfId, fileRead.c_str());
        //     std::getline(is, fileRead, tabSpace);
        //     strcpy(title, fileRead.c_str());
        //     std::getline(is, fileRead, tabSpace);
        //     membership = convertStringToInt(fileRead);
        //     is >> publications[numOfPublications]->m_date;

        //     strcpy(publications[numOfPublications]->m_shelfId, shelfId);
        //     strcpy(publications[numOfPublications]->m_title, title);
        //     publications[numOfPublications]->m_libRef = libRef;
        //     publications[numOfPublications]->m_membership = membership;

        //     this->numOfPublications++;

        //     tempLibRefNum = libRef;
        // }

        m_mainMenu.setTitle("Seneca Library Application");
        m_mainMenu << "Add New Publication";
        m_mainMenu << "Remove Publication";
        m_mainMenu << "Checkout publication from library";
        m_mainMenu << "Return publication to library";

        m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
        m_exitMenu << "Save changes and exit";
        m_exitMenu << "Cancel and go back to the main menu";

        pubType.setTitle("Choose the type of publication:");
        pubType << "Book";
        pubType << "Publication";
        load();

    }
    //~LibApp::LibApp(){}
    void LibApp::newPublication() {
        if (SDDS_LIBRARY_CAPACITY == numOfPublications) {
            std::cout << "Library is at its maximum capacity!\n";
            return;
        }

        std::cout << "Adding new publication to the library\n";
        //std::cout<<;
int ch = pubType.run();
            char typeChoice = (ch == 1) ? 'B' : 'P';
        Publication* pubTemp = nullptr;

        //char typeChoice = 'P';

        if (typeChoice == 'P')
            pubTemp = new Publication;
        else if (typeChoice == 'B')
            pubTemp = new Book;
        pubTemp->read(std::cin);
        if (std::cin.fail()) {
            std::cin.ignore();
            std::cout << "Aborted!";
            exit(101);
        }
	getchar();
        if (confirm("Add this publication to the library?")) {

            if (pubTemp) {
                m_changed = true;
                tempLibRefNum++;
                pubTemp->m_libRef = tempLibRefNum;
                publications[numOfPublications++] = pubTemp;
                m_changed = true;
                std::cout << "Publication added\n";
            }
            else {
                std::cout << "Failed to add publication!\n";
            }
        }
        else {
            std::cout << "Aborted!";
            exit(101);
        }
	//getchar();
        return;
    }
    void LibApp::removePublication() {
        std::cout << "Removing publication from the library\n";
        //std::cout<<;
        
        int refToDeleted=search(true,false);
        std::ofstream outfile(pubFileName);
        for( int i=0;i<numOfPublications;i++)
        {
            if(publications[i]->getRef()!=refToDeleted)
            {
                    outfile << publications[i]->type() << '\t' ;
        outfile<< publications[i]->getRef()<< '\t' ;
        outfile<< publications[i]->shelfId() << '\t' ;
        outfile<< publications[i]->title()<< '\t';
                        bool mFlag = (publications[i]->m_membership == 0);
                        if (mFlag) {
                            outfile << "0";
                        }
                        else {
                            outfile << publications[i]->m_membership;
                        }
                        outfile << '\t' << publications[i]->m_date ;
                if(publications[i]->type()=='B')
                {
                outfile<<"\t"<<publications[i]->returnAuthName();
                }
                outfile<<"\n";
            }
            else{
                std::cout<<*publications[i]<<"\n";
	publications[i]->setRef(0);
}
        }
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            std::cout << "Publication removed\n";
        }
	m_changed=true;
        return;
    }
    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            std::cout << "Publication checked out\n";
        }
    }
    void LibApp::run() {
        int ch = -1;
        do {

            ch = m_mainMenu.run();
            switch (ch)
            {
            case 1:
                this->newPublication(); break;
            case 2:
                this->removePublication(); break;
            case 3:
                this->checkOutPub(); break;
            case 4:
                this->returnPub(); break;
            default: std::cout << "invalid choice"; break;
            case 0:
            {
                int ch2 = -1;
                bool stopExecution = false;
                if (m_changed)
                {
                    ch2 = m_exitMenu.run();
                    switch (ch2)
                    {
                    case 1:
                        save();
                        stopExecution = true;
                        break;
                    case 2: break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?"))
                            stopExecution = true;
                        break;
                    }
                    if (stopExecution)
                    {
                        std::cout << "\n-------------------------------------------\nThanks for using Seneca Library Application";
                        ch = -2;
                    }
                }
                else {
                    std::cout << "\n-------------------------------------------\nThanks for using Seneca Library Application";
                    ch = -2;
                }
            }
            }
            std::cout << std::endl;
        } while (ch != -2);
    }
}