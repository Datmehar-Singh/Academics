#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
//if(m_numbers!=nullptr)
//delete[] m_numbers;


	//delete[] m_filename;
	m_filename=new char[20];
      setFilename(filename);
      m_numCount = numberCount();
this->m_numbers=new double[m_numCount+1];
	   std::cout<<"m_numCount is "<<m_numCount;
	   bool load=this->load();
	  // std::cout<<"Load is "<<load;
	   
      if (m_numCount == 0 || !load) {
		 // std::cout<<"enterwed";
         // delete[] m_numbers;
         // delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   
   Numbers::Numbers(Numbers &n)
   {
	   
	  // std::cout<<"copy called";
	   // if(this->m_filename!=nullptr)
		   // delete [] this->m_filename;


	this->setEmpty();
	   this->m_filename=new char[20];
	      strcpy(m_filename,n.m_filename);
	   

      (this->m_numbers)=(n.m_numbers);
      this->m_isOriginal=false;
      this->m_numCount=n.m_numCount;
   }

   Numbers& Numbers::operator=(Numbers& n)
   {
	   //if(m_numbers)
      //delete[] this->m_numbers;
      this->m_numbers=new double[n.m_numCount];
	   //std::cout<<"= called";
      for(int i=0;i<n.m_numCount;i++)
      {
         this->m_numbers[i]=n.m_numbers[i];
      }

	   m_numCount=n.m_numCount;
      return *this;
   }
   
   Numbers::~Numbers() {
      save();
	    if(m_numbers && m_numbers!=nullptr)
      delete[] m_numbers;
	   

if(m_filename)
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
	    //if(m_filename!=nullptr)
       //delete[] m_filename;

     // m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   
   int Numbers::numberCount() const
   {
      int counter=0;
      char line[20];
      std::ifstream fptr;

      fptr.open(this->m_filename);
      if (fptr.is_open()) {
		  //std::cout<<"opened";
         while (fptr>>line) {//.getline(line, 20)
			 //std::cout<<line;
            counter++;
         }
      }
	   //std::cout<<"counter is "<<counter;
      fptr.close();
      return counter;
   }

   bool Numbers::load(){
      int counter=0;
      if(!this->m_numCount) return false;

	//if(m_numbers) 
//delete[] m_numbers;
	//if(!m_numbers)
      //this->m_numbers=new double[this->m_numCount];
      std::ifstream fptr;

      fptr.open(this->m_filename);
      if(fptr.is_open())
      {
         while(fptr>>this->m_numbers[counter++]){;}
      }
	  // std::cout<<m_numCount<<"=="<<counter;
	fptr.close();
      if(m_numCount==counter-1) return true;
	
      return false;
   }
   void Numbers::save()
   {
      if(this->m_numbers==nullptr) return;

      std::ofstream fptr;
	if(m_filename)
      fptr.open(m_filename);
      if(fptr.is_open() && m_numbers)
      {
         for(int i=0;i<m_numCount;i++)
         {
            fptr<<m_numbers[i]<<"\n";
         }
      }
      fptr.close();
   }

   Numbers& Numbers::operator+=(double val)
   {
      double* tempArr=new double[m_numCount+1];
      int i=0;

      for(i=0;i<m_numCount;i++)
      {
         tempArr[i]=m_numbers[i];
      }
      tempArr[i]=val;

	    //if(m_numbers)
       delete[] m_numbers;

//m_isOriginal=false;


      m_numbers=tempArr;
      m_numCount++;
/*for(i=0;i<m_numCount-1;i++)
      {
         m_numbers[i]=tempArr[i];
      }*/


      this->sort();
	delete[] tempArr;
      return *this;
   }

   ostream& Numbers::display(ostream& ostr) const
   {
      if(!m_numCount) 
      {
         ostr<<"Empty list";
         return ostr;
      }
      ostr<<"=========================\n";
      if(m_isOriginal)
         ostr<<m_filename<<"\n";
      else ostr<<"*** COPY ***\n";
      for(int i=0;i<m_numCount-1;i++)
      {
         ostr<<m_numbers[i]<<", ";
      }
      ostr<<m_numbers[m_numCount-1];
      ostr<<"\n-------------------------\n";
      ostr<<"Total of "<<m_numCount<<" number(s)\n";
      ostr<<"Largest number:  "<<this->max();
      ostr<<"\nSmallest number: "<<this->min();
      ostr<<"\nAverage :        "<<this->average();
      ostr<<"\n=========================";
	   //m_isOriginal=false;
      return ostr;
	   }
      /*
      =========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3
Average :        17.972
=========================
      
   }*/


   ostream& operator<<(ostream& os, const Numbers& N)
   {
	  // std::cout<<"<< called";
	  // N.m_isOriginal=false;
      return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N){
      double temp=0.0;
	   bool isPresent =false;
      istr>>temp;
	   //std::cout<<temp<<'\n';
	   for(int i=0;i<N.m_numCount;i++)
		   {
			   if(N.m_numbers[i]==temp)
                 isPresent=true;


		   }
	   if(!isPresent)
      N+=temp;
      return istr;
   }
   
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }


   
}




