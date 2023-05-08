namespace sdds{
    class ChequingAccount:public Account{
        private:
        double transactionFee;
        double monthlyFee;

        public:
        ChequingAccount(double accBalance, const double transFee,const double monthlyFee): Account(accBalance)
	{
            transactionFee=(transFee>0.0)?transFee:0.0;
            this->monthlyFee=(monthlyFee>0.0)?monthlyFee:0.0;
        }

        bool credit(double cr)
        {
            bool res=Account::credit(cr-transactionFee);
            if(this->balance()>transactionFee)
            {
                return res && true;
            }
            else return res && false;
        }
        bool debit(double deb)
        {
            bool res=Account::debit(deb+transactionFee);

            if(this->balance()>transactionFee)
            {
                return res && true;
            }
            else return res && false;
        }

        void monthEnd()
        {
            this->Account::debit(monthlyFee);
        }
        void display(std::ostream& os) const
        {
            os<<"Account type: Chequing"<<"\n";
            os<<"Balance: $"<<std::fixed<<std::setprecision(2)<<this->balance()<<"\n";
            os<<"Per Transaction Fee: "<<std::fixed<<std::setprecision(2)<<transactionFee<<"\n";
            os<<"Monthly Fee: "<<std::fixed<<std::setprecision(2)<<this->monthlyFee<<"\n";
        }
    };
}