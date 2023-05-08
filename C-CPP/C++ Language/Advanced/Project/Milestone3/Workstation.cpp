//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca

#include"Workstation.h"

namespace sdds{
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;
        Workstation::Workstation(const std::string& filename):Station(filename){}
        Workstation::~Workstation(){
           // if (m_pNextStation!=nullptr)
{
               // delete m_pNextStation;
                //m_pNextStation=nullptr;
            }
	//delete m_pNextStation;
        }

        void Workstation::fill(std::ostream& os){
				
				if(m_orders.size() ){
                m_orders.front().fillItem(*this,os);
            }
        }
        bool Workstation::attemptToMoveOrder(){
		if (!m_orders.empty())
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0)
			{
				if (m_pNextStation != nullptr)
				{
					(*m_pNextStation) += std::move(m_orders.front());
				}
				else
				{
					if (m_orders.front().isOrderFilled())
					{
						g_completed.push_back(std::move(m_orders.front()));
					}
					else
					{
						g_incomplete.push_back(std::move(m_orders.front()));
					}
				}
				m_orders.pop_front();
				return true;
			}
		return false;
        }
        void Workstation::setNextStation(Workstation* station){
            m_pNextStation=station;
        }
        Workstation* Workstation::getNextStation() const{
            return m_pNextStation;
        }
        void Workstation::display(std::ostream& os) const{
            //const Workstation* temp=this;
            // while(temp!=nullptr)
            // {
			//os<<m_orders.size();
                if(getNextStation()!=nullptr)
                os<<this->Station::getItemName()<<" --> "<<getNextStation()->Station::getItemName();
                else
                os<<this->Station::getItemName()<<" --> End of Line";

                os<<"\n";
            //     temp=temp->getNextStation();                
            // }
        }
        Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
			
            m_orders.push_back(std::move(newOrder));
            return *this;
        }
}

//./main Stations1.txt Stations2.txt CustomerOrders.txt AssemblyLine.txt