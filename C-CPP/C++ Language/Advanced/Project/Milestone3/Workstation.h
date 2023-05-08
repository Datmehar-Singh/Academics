//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca

#ifndef WORKSTATION_H_
#define WORKSTATION_H_

#include"CustomerOrder.h"
#include"Station.h"
#include <deque>


namespace sdds{

    extern std::deque<CustomerOrder> g_pending;
extern std::deque<CustomerOrder> g_completed;
extern std::deque<CustomerOrder> g_incomplete;


    class Workstation:public Station{
        std::deque<CustomerOrder> m_orders{};
        Workstation* m_pNextStation{nullptr};

        public:
        Workstation(const std::string& filename);
        ~Workstation();

        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif
