#ifndef QUEUE_H_
#define QUEUE_H_

#include<iostream>
#include<string>
#include"Dictionary.h"

namespace sdds{
    const int arr_size=30;

    template<class T,int u>class Queue{
        T m_arr[arr_size]{};
        std::string m_type{};
        unsigned int m_capacity{};
        unsigned int m_size{};

        public:
        Queue();
        bool push(const T& item);
        T pop();
        int size();
        std::ostream& display(std::ostream& = std::cout );
        T operator[](int);
    };
    template<>class Queue <Dictionary, 100u>{
        Dictionary T{"Empty Term","Empty Substitute"};
    };

}
#endif