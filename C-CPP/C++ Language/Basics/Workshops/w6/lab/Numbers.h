#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(Numbers &n);
      Numbers& operator=(Numbers& n);
      double average()const;
      double max()const;
      double min()const;
      int numberCount() const;
      bool load();
      void save();
      Numbers& operator+=(double);
      std::ostream& display(std::ostream& ostr) const;
      friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
      friend std::istream& operator>>(std::istream& istr, Numbers& N);
      ~Numbers();
   };
}
#endif // !SDDS_NUMBERS_H_

