#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>

using namespace std;
namespace sdds {
void Book::init_book() {
  m_title[0] = '\0';
  m_author[0] = '\0';
  m_num_chapters = 0;
  m_num_pages = 0;
}

Book::Book() { init_book(); }

Book::Book(const char *title_) {
  init_book();
  strcpy(m_title, title_);
}

Book::Book(const char *title_, const char *author_, double price_) {
  init_book();
  strcpy(m_title, title_);
  strcpy(m_author, author_);
  m_price = price_;
}

// Print a book summary
void Book::summary() {
  cout.setf(ios::left);
  cout << "| ";
  cout.width(MAX_BOOK_TITEL);
  cout << m_title << " | ";
  cout.width(MAX_AUTHOR_NAME);
  cout << m_author << " | ";
  cout.width(3);
  cout << m_num_chapters << "  ";
  cout.width(4);
  cout << m_num_pages << " | ";
  cout.width(6);
  cout << m_price << " |" << endl;
}

int Book::add_chapter(Chapter *c) {
  this->m_chapters[m_num_chapters++] = *c;
  m_num_pages += int(*c);
  return m_num_chapters;
}

int Book::operator++(int) { return m_num_chapters + 1; }
Book::operator int() { return m_num_chapters; }
Book::operator bool() {
  int i = 0;
  if (m_title[0] != '\0' && m_author[0] != '\0' && m_num_chapters != 0)
    while (i < m_num_chapters) {
      if (int(m_chapters[i]) != 0)
        return true;
	i++;
    }
  return false;
}
Book::operator double() { return m_price; }
Book::operator const char *() { return m_title; }
void Book::operator+=(Chapter c) { add_chapter(&c); }

void Book::operator-=(double price) { m_price -= price; }

ostream &Book::display(std::ostream &o) const {
  o << "Title:'" << m_title << "'\n";
  o << "Author: '" << m_author << "'\n";
  for (int i = 0; i < m_num_chapters; i++)
    o << *(m_chapters + i) << std::endl;
  return o;
}
std::ostream& operator<<(std::ostream& output, const Book& obj)
        {
           return obj.display(output);
        }
} // namespace sdds