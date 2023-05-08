#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <cstring>
#include <iostream>
#define MAX_CHAPTER_TITLE 20
namespace sdds {
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE+1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();
    public:
        Chapter();
        Chapter(const char* title_);
        Chapter(const char* title_, int chapter_num, int n_pages, int n_words);
        std::ostream& display(std::ostream&)const;
        operator int() {
			return this->m_num_pages;
		}
		operator double() {
			return this->m_num_words/(double)this->m_num_pages;
		}
		operator const char *()
		{
			return this->m_title;
		}
		void operator =(Chapter& c)
		{
			 strcpy(m_title, c.m_title);
       this->m_num_pages = c.m_num_pages;
       this->m_num_words = c.m_num_words;
        this->m_chapter_number = c.m_chapter_number;
    }
    int operator ++ ()
    {
        return this->m_num_pages+1;
    }
    int operator -- ()
    {
        return this->m_num_pages-1;
    }
	friend std::ostream& operator<<(std::ostream& output, const Chapter& obj);
		
    };
}
#endif


