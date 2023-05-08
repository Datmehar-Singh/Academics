//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca
#ifndef LINE_MANAGER_H_
#define LINE_MANAGER_H_

#include "Workstation.h"
#include <vector>
#include <algorithm>
#include <string>
namespace sdds{
    class LineManager{
        std::vector<Workstation*> m_activeLine{};
        size_t m_cntCustomerOrder{};
        Workstation* m_firstStation{nullptr};

        public:
        LineManager();
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        ~LineManager();

        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}

#endif