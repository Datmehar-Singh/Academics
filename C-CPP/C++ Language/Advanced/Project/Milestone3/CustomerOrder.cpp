//Student Name: Datmehar Singh
//Studnet ID: 108011214
//Student Email datmehar-singh@myseneca.ca
#include "CustomerOrder.h"

std::string trim(std::string str)
    {
        if (str.find_last_not_of(' ') == str.find_first_not_of(' '))
            return str;
        std::string res = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1);
		return res;
    }


namespace sdds{

size_t CustomerOrder::m_widthField=0;
CustomerOrder::CustomerOrder(){
	m_cntItem=0;
	m_lstItem=nullptr;
	
}
	CustomerOrder::CustomerOrder(const std::string& wholeLine){
		Utilities u{};
		m_cntItem=0;
		size_t next=0;
		bool more=true;
		m_lstItem=nullptr;
		m_name=trim(u.extractToken(wholeLine,next,more));
		m_product=trim
			(u.extractToken(wholeLine,next,more));
Item** arr=new Item*[10];
int i=0;
		while(more){

arr[i]=new Item{trim(u.extractToken(wholeLine,next,more))};
i++;
}
m_cntItem=i;
m_lstItem=new Item*[m_cntItem];
for(int j=0;j<i;j++)
{
m_lstItem[j]=arr[j];
//m_lstItem[j]->m_serialNumber=(size_t)j;
}
delete[] arr;

		
		if(CustomerOrder::m_widthField<u.getFieldWidth())
		CustomerOrder::m_widthField=u.getFieldWidth();
	}
		CustomerOrder::CustomerOrder(const CustomerOrder&){
		throw std::string("");


		}
			CustomerOrder::CustomerOrder( CustomerOrder&& c)noexcept{
				m_name=c.m_name;
				m_product=c.m_product;
				m_cntItem=c.m_cntItem;

				m_lstItem=c.m_lstItem;
c.m_lstItem=nullptr;
c.m_cntItem=0;
				
			}
			CustomerOrder& CustomerOrder::operator=(CustomerOrder&& c) noexcept{
if(this==&c) return c;
				for(size_t i=0;i<m_cntItem;i++)
{
delete m_lstItem[i];}
delete[] m_lstItem;
				m_name=std::move(c.m_name);
				m_product=std::move(c.m_product);
				m_cntItem=c.m_cntItem;
				m_lstItem=c.m_lstItem;
c.m_cntItem=0;
c.m_lstItem=nullptr;
				return *this;
				
			}
			CustomerOrder::~CustomerOrder(){
				if(m_lstItem!=nullptr)
				for(size_t i=0;i<m_cntItem;i++)
					{
						if(m_lstItem[i]!=nullptr)
						delete m_lstItem[i];
					}
				if(m_lstItem)
				delete[] m_lstItem;
			}
			bool CustomerOrder::isOrderFilled() const{
				for(size_t i=0;i<m_cntItem;i++)
					{
						if(m_lstItem[i]->m_isFilled==false) return false;
					}			
				return true;
				}
			bool CustomerOrder::isItemFilled(const std::string& itemName) const{
				for(size_t i=0;i<m_cntItem;i++)
					{
						if(m_lstItem[i]->m_isFilled==false && m_lstItem[i]->m_itemName==itemName) return false;
					}			
				return true;
			}
	void CustomerOrder::fillItem(Station& station, std::ostream& os){
				

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (trim(m_lstItem[i]->m_itemName) == station.getItemName() && m_lstItem[i]->m_isFilled==false)
			{
				if (station.getQuantity() > 0)
				{
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();

					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
					i=100000;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
				}
			}
		}
			}
			void CustomerOrder::display(std::ostream& os) const{
				/*CUSTOMER_NAME - PRODUCT
[SERIAL] ITEM_NAME - STATUS
[SERIAL] ITEM_NAME - STATUS
...*/
				os<<trim(m_name)<<" - "<<trim(m_product)<<"\n";
				for(size_t i=0;i<m_cntItem;i++)
					{
						
				os<<"["<<std::right<<std::setfill('0')<<std::setw(6)<<m_lstItem[i]->m_serialNumber<<"] ";
						os<<std::setfill(' ')<<std::left<<std::setw(m_widthField)<<trim(m_lstItem[i]->m_itemName);
						os<<std::setfill(' ')<<" - ";
						os<<((m_lstItem[i]->m_isFilled)?"FILLED":"TO BE FILLED");
						os<<"\n";
					}
				return;
			}
}