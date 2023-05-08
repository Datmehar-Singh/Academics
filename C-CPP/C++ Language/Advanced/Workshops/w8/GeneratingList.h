#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool luhn(const std::string& SIN) const
{
    int n = SIN.length();
 
    int sum = 0, alternate = false;
    for (int i = n - 1; i >= 0; i--) {
 
        int digit = SIN[i] - '0';
 
        if (alternate == true)
            digit = digit * 2;
 
        // We add two digits to handle
        // cases that make two digits after
        // doubling
        sum += digit / 10;
        sum += digit % 10;
 
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}
	

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
void operator+=(std::shared_ptr<T> obj){
	list.push_back(*obj);
}
		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* obj)
{
	list.push_back(*obj);
}

		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
