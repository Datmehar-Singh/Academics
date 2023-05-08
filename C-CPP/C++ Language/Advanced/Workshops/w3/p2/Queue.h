#ifndef QUEUE_H_
#define QUEUE_H_

#include<iostream>
#include <typeinfo>
#include<string>
#include"Dictionary.h"

namespace sdds{
    const int arr_size=30;
    template<class T,int U>class Queue{
        T m_arr[arr_size]{};
        std::string m_type{};
        int m_capacity{};
        int m_size{};

        public:
        Queue();
        bool push(const T& item);
        T pop();
        int size();
        std::ostream& display(std::ostream&  os = std::cout );
        T operator[](int idx);
    };
    template<>class Queue <Dictionary, 100u>{
        Dictionary T{"Empty Term","Empty Substitute"};
    };

}
#endif