// Name: Datmehar Singh
// Seneca Student ID: 108011214
// Seneca email: datmehar-singh@myseneca.ca
// Date of completion: 18 march 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"Station.h"
#include"Utilities.h"



namespace sdds {

   //class variables
   size_t Station:: m_widthField = 0;
   size_t Station:: id_generator = 0;


   Station::Station(const std::string& str) : m_id{ static_cast<int>(++Station::id_generator) } {
      size_t next_pos = 0;
      Utilities tokenUtils;
      bool moreToken{ true };
      //this constructor uses a utilities  object defined to extracts each token from the record and populates the Station
      try {
         this->m_name = tokenUtils.extractToken(str, next_pos, moreToken);
         //we use std::stoul (string to unsigned integer long) specialy when we working with unsigned values.
         this->m_serialNumber = std::stoul(tokenUtils.extractToken(str, next_pos, moreToken));
         this->m_currentItemNum = std::stoul(tokenUtils.extractToken(str, next_pos, moreToken));

         Station::m_widthField = Station::m_widthField > tokenUtils.getFieldWidth() ? m_widthField : tokenUtils.getFieldWidth();

         this->m_description = tokenUtils.extractToken(str, next_pos, moreToken);
      }
      catch (std::logic_error& err) {
         std::cout << err.what() << std::endl;
      }
   }
   
   const std::string& Station::getItemName() const
   {
      // TODO: insert return statement here
     // return std::string(this->m_name);
      return this->m_name;
   }

   size_t Station::getQuantity() const
   {//return remaining quantity from the string first
      return size_t(this->m_currentItemNum);
   }

   size_t Station::getNextSerialNumber()
   {
      return size_t(this->m_serialNumber++);
   }

   void Station::updateQuantity()
   {  // Should not drop bellow zero and substract 1 from the available quantity
     // this->m_currentItemNum = m_currentItemNum < 0 ? 0 : m_currentItemNum - 1;
         if (m_currentItemNum > 0) {
            this->m_currentItemNum--;
         }
   }
   

   void Station::display(std::ostream& os, bool full) const
   {
      if (!full)  // the second parameter is false
      {
         os.setf(std::ios::right);
         os.fill('0');
         os.width(3);
       //  os << this->m_id << " | ";
         os << m_id << " | ";
         os.unsetf(std::ios::right);

         os.setf(std::ios::left);
         os.fill(' ');
         os.width(this->m_widthField);
         os << this->m_name << "  | ";
         os.unsetf(std::ios::left);

         os.setf(std::ios::right);
         os.fill('0');
         os.width(6);
         os << this->m_serialNumber;
         os << " | "<<std::endl;
         os.unsetf(std::ios::right);
      }
      else  // full is true
      {
         os.setf(std::ios::right);
         os.fill('0');
         os.width(3);
         os << this->m_id << " | ";
         os.unsetf(std::ios::right);

         os.setf(std::ios::left);
         os.fill(' ');
         os.width(this->m_widthField);
         os << this->m_name << "  | ";
         os.unsetf(std::ios::left);

         os.setf(std::ios::right);
         os.fill('0');
         os.width(6);
         os << this->m_serialNumber;
         os << " | ";
         os.unsetf(std::ios::right);

         os.setf(std::ios::right);
         os.fill(' ');
         os.width(4);
         os << this->m_currentItemNum;
         os << " | ";
         os.unsetf(std::ios::right);

         os.setf(std::ios::left);
         os.width(6);
         os << this->m_description;
         os << std::endl;
         os.unsetf(std::ios::left);

      }
   }

}