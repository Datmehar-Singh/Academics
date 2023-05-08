#include "iAccount.h"
namespace  sdds{
	class Account :public iAccount
	{
	private:
		double currBalance;
	
	public:
		Account(double amt){
            this->currBalance=(amt<=0)?0:amt;
        }
		virtual bool credit(double creditAmount)
        {
            currBalance+=creditAmount;
return true;
        }
		virtual bool debit(double debitAmount){
            currBalance-=debitAmount;
	return true;
        }
        virtual void monthEnd()=0;
		virtual void display(std::ostream&) const =0;
	protected:
		double balance() const {
            return currBalance;
        }
	};
}