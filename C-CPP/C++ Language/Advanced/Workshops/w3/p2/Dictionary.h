#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include<iostream>
#include<string>
#include<iomanip>

namespace sdds{
    class Dictionary
    {
    std::string m_term{};
    std::string m_definition{};
    public:
    const std::string& getTerm() const { return m_term; }
    const std::string& getDefinition() const { return m_definition; }
    Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}
    Dictionary(){}
    friend std::ostream& operator<<(std::ostream& os,Dictionary d){
        os<<std::setw(20)<<std::right<<d.m_term<<": "<<d.m_definition;
        return os;
    }
    // TODO: Code the missing prototype functions and operators
    //       that the class needs in order to work with the Queue class.
    //       Implement them in the Dictionary.cpp file.
    };
}
#endif