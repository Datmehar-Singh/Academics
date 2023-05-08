#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
EmployeeWage* eObj=nullptr;
		for(size_t i=0;i<emp.size();i++)
			{
				for(size_t j=0;j<sal.size();j++)
					{
						if(emp[i].id==sal[j].id)
						{
							eObj=new EmployeeWage(emp[i].name,sal[j].salary);
								eObj->rangeValidator();
							if(activeEmp.luhn(emp[i].id)){
							activeEmp+=eObj;
								}
					delete eObj;
						}
					}
			}
delete eObj;
		
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for(size_t i=0;i<emp.size();i++)
			{
				for(size_t j=0;j<sal.size();j++)
					{
						if(emp[i].id==sal[j].id)
						{
							std::shared_ptr<EmployeeWage> eObj(new EmployeeWage(emp[i].name,sal[j].salary));
								eObj->rangeValidator();
							if(activeEmp.luhn(emp[i].id)){
								

								
							activeEmp+=eObj;
								}
						}
					}
			}
		

		return activeEmp;
	}
}