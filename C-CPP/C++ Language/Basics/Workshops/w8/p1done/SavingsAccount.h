#include "Account.h"
#include<iomanip>

namespace sdds{
    class SavingsAccount : public Account{
        private:
        double interestRate;
        public:
        SavingsAccount(double balance, double interest):Account(balance)
        {
            this->interestRate=(interest<=0)?0.0:interest;
        }
        void monthEnd()
        {
            double intAmt=this->balance()*this->interestRate;
            this->credit(intAmt);
            return;
        }
        void display(std::ostream& os) const
        {
            os<<"Account type: Savings"<<"\n";
            os<<"Balance: $"<<std::fixed<<std::setprecision(2)<<this->balance()<<"\n";
            os<<"Interest Rate (%): "<<std::fixed<<std::setprecision(2)<<this->interestRate*100.0<<"\n";
        }
    };
}