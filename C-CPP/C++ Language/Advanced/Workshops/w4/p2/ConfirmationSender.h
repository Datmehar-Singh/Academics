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
#ifndef CONFIRMATION_SENDER_H
#define CONFIRMATION_SENDER_H

#include "Reservation.h"

namespace sdds{
    class ConfirmationSender{
        private:
        Reservation** m_pReservations{};
        size_t m_size{};
        public:
        ConfirmationSender();
        ConfirmationSender& operator+=(const Reservation& res);

    ConfirmationSender(const ConfirmationSender &r);
    ConfirmationSender(ConfirmationSender&& r);
    
    ConfirmationSender &operator=(const ConfirmationSender &r);
    ConfirmationSender &operator=(ConfirmationSender &&r);


        bool search(const Reservation& r);
        size_t size(){return m_size;}
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os ,ConfirmationSender c);
        ~ConfirmationSender();
    };
}

#endif