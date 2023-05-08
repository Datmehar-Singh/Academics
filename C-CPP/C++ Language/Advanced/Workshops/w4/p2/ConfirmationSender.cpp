/*
*****************************************************************************
						Workshop 4 - Part 2
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include"ConfirmationSender.h"

namespace sdds{
    ConfirmationSender::ConfirmationSender(){
        m_pReservations=nullptr;
        m_size=0;
    }
    bool ConfirmationSender::search(const Reservation& r){
        for(int i=0;i<(int)size();i++){
            if(m_pReservations[i]==&r){
                return true;
            }
        }
        return false;
    }

    //_________________________________________________________________________________

    ConfirmationSender::ConfirmationSender(const ConfirmationSender &r)
    {
        delete[] this->m_pReservations;

        m_pReservations = new Reservation *[r.m_size];
        for (int i = 0; i < (int)r.m_size; i++)
        {
            m_pReservations[i] = const_cast<Reservation *>(r.m_pReservations[i]);
        }
        m_size = r.m_size;
    }
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& r)
    {
        delete[] this->m_pReservations;
        m_pReservations=r.m_pReservations;
        r.m_pReservations=nullptr;
        this->m_size=r.m_size;
        r.m_size=0;
    }
    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &r)
    {
        delete[] this->m_pReservations;

        m_pReservations = new Reservation *[r.m_size];
        for (int i = 0; i < (int)r.m_size; i++)
        {
            m_pReservations[i] = const_cast<Reservation *>(r.m_pReservations[i]);
        }
        m_size = r.m_size;
        return *this;
    }
    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&r) {
        if(this==&r) return *this;
        delete[] this->m_pReservations;
        m_pReservations=r.m_pReservations;
        r.m_pReservations=nullptr;
        this->m_size=r.m_size;
        r.m_size=0;
        return *this;
    }

    //________________________________________________________________________


        ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
            if(search(res)) return *this;

            Reservation** m_pReservationsCopy=nullptr;
            m_pReservationsCopy=new Reservation*[m_size+1];
            for(int i=0;i<(int)m_size;i++){
                m_pReservationsCopy[i]=m_pReservations[i];
            }
            m_pReservationsCopy[m_size++]=&(const_cast<Reservation&>(res));
            delete [] m_pReservations;
            m_pReservations=nullptr;
            m_pReservations=m_pReservationsCopy;
            return *this;
        }
        ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
            if(!search(res)) { return *this;}

            Reservation** m_pReservationsCopy=nullptr;
            m_pReservationsCopy=new Reservation*[m_size-1];

            int k=0;
            for(int i=0;i<(int)m_size;i++){
                if(m_pReservations[i]!=&res)
                    m_pReservationsCopy[k++]=m_pReservations[i];
            }
            delete [] m_pReservations;
            m_pReservations=nullptr;
            m_size--;
            m_pReservations=m_pReservationsCopy;
            return *this;
        }
        std::ostream& operator<<(std::ostream& os ,ConfirmationSender c){
            os<<"--------------------------\n";
            os<<"Confirmations to Send\n";
            os<<"--------------------------\n";
            if(c.m_size==0)
            {
                os<<"There are no confirmations to send!\n";
            }
            else{
                for(int i=0;i<(int)c.size();i++)
                    os<<*(c.m_pReservations[i]);
            }
            os<<"--------------------------\n";
            return os;
        }
        ConfirmationSender::~ConfirmationSender(){
            delete[] m_pReservations;
        }
}