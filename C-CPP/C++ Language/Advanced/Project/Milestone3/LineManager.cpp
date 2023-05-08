//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca
#include "LineManager.h"

namespace sdds{
    LineManager::LineManager(){m_firstStation=nullptr;}
        LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations){
            std::ifstream fptr(file);
            std::ifstream fptrCopy(file);
            std::string ws{},nws{},tempFullLine;
			// m_cntCutomerOrder
            while( !fptr.eof() )
            {
				std::getline(fptrCopy,tempFullLine);
				
				if(((int)tempFullLine.rfind("|")==-1)){
                std::getline(fptr , ws);
					}
				else {
                	std::getline(fptr , ws,'|'); 
					std::getline(fptr,nws);
					}
                Workstation* tempStation=nullptr;
                Workstation* tempNextStation=nullptr;

                std::for_each(stations.begin(), stations.end(), [&tempStation,ws](Workstation* station){
                    if(station->getItemName()==ws)
                    tempStation=station;
                });
                std::for_each(stations.begin(), stations.end(), [&tempNextStation,nws](Workstation* station){
                    if(station->getItemName()==nws)
                    tempNextStation=station;
                });
                if(tempStation && tempNextStation  && tempNextStation!=tempStation) {
                    tempStation->setNextStation(tempNextStation);
                    m_activeLine.push_back(tempStation);
                }else if(tempStation) {
					
                    tempStation->setNextStation(nullptr);
                    m_activeLine.push_back(tempStation);
                }
                else{
                    std::cerr<<"\n\n\n\nWORKSTATION NOT FOUND\n\n\n\n";
                }

            }
			for(size_t i=0;i<m_activeLine.size();i++)
				{
					bool flag=true;
					for(size_t j=0;j<m_activeLine.size();j++){
						if(m_activeLine[i]==m_activeLine[j]->getNextStation()){
							flag=false;
						}
					}
					if(flag){
						m_firstStation=m_activeLine[i];
						break;
					}
				}
			
            // m_firstStation=m_activeLine[0];
        }
        LineManager::~LineManager(){}

        void LineManager::reorderStations(){
            std::vector<Workstation*> temp{};

            Workstation* tempPtr=m_firstStation;

            while(tempPtr)
            {
                temp.push_back(tempPtr);
                tempPtr=tempPtr->getNextStation();
            }
            for(size_t i=0;i<temp.size();i++)
            {
                m_activeLine[i]=temp[i];
            }
            return;
        }

bool LineManager::run(std::ostream& os)
	{
		static int counter=1;
		os << "Line Manager Iteration: " << counter++ << '\n';
		
		// Move order from pending to first station
		if (!g_pending.empty())
		{
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		for(size_t i=0;i<m_activeLine.size();i++)
		{ m_activeLine[i]->fill(os);
			}
	for(size_t i=0;i<m_activeLine.size();i++)
		{
			(m_activeLine[i])->attemptToMoveOrder();
		}

		return g_completed.size() + g_incomplete.size() == 5;

	}

        void LineManager::display(std::ostream& os) const{
            for(auto it = m_activeLine.begin(); it != m_activeLine.end(); ++it){
                (*it)->display(os);
            }
            return;
        }
}

/*
bool run(std::ostream& os) – this modifier performs one iteration of operations on all of the workstations in the current assembly line by doing the following:

keeps track of the current iteration number (use a local variable)
inserts into stream os the iteration number (how many times this function has been called by the client) in the format Line Manager Iteration: COUNT<endl>
moves the order at the front of the g_pending queue to the m_firstStation and remove it from the queue. This function moves only one order to the line on a single iteration.
for each station on the line, executes one fill operation
for each station on the line, attempts to move an order down the line
return true if all customer orders have been filled or cannot be filled, otherwise returns false.

*/