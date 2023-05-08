#include "Queue.h"

namespace sdds
{
    template <class T, int i>
    Queue<T,i>::Queue()
    {
        m_type = typeid(T).name();
        m_capacity = static_cast<unsigned int>(arr_size);
        m_size = 0;
    }
    template <class T, int i>
    bool Queue<T, i>::push(const T &item)
    {
        if (m_size == m_capacity)
            return false;

        m_arr[m_size] = item;
        m_size++;
        return true;
    }
    template <class T, int i>
    T Queue<T, i>::pop()
    {
        T removedElement{};
        if (size <= 0)
            return removedElement;
        T removeElement = m_arr[0];
        for (int i = 0; i < m_size; i++)
        {
            m_arr[i] = m_arr[i + 1];
        }
        m_size--;
        return removedElement;
    }
    template <class T, int i>
    int Queue<T, i>::size()
    {
        return m_size;
    }
    template <class T, int i>
    std::ostream &Queue<T, i>::display(std::ostream &os)
    {
        os << "----------------------\n";
        os << "| Dictionary Content |\n";
        os << "----------------------\n";
        for (int i = 0; i < m_size; i++)
        {

            os << m_arr[i] << "\n";
        }
        os << "----------------------\n";
        return os;
    }
    template <class T, int i>
    T Queue<T, i>::operator[](int idx)
    {
        if (idx > m_size)
        {
            T dummyObj{};
            return dummyObj;
        }
        return m_arr[idx];
    }
}
