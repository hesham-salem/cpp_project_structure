#include <calculator.h>
template <typename T>
calculator<T>::calculator(T a_, T b_) : a{new T(a_)}, b{new T(b_)}, result{new T}
{
}
template <typename T>
calculator<T>::calculator(const calculator &other) : calculator(*(other.a), *(other.b))
{
}
template <typename T>
calculator<T> &calculator<T>::operator=(const calculator<T> &other)
{
    *(this->a) = *(other.a);
    *(this->b) = *(other.b);
    return *this;
}
template <typename T>
calculator<T>::calculator(calculator &&other) : a{other.a}, b{other.b}
{

    other.a = nullptr;
    other.b = nullptr;
}
template <typename T>
calculator<T> &calculator<T>::operator=(calculator<T> &&other)
{
    this->a = other.a;
    this->b = other.b;
    other.a = nullptr;
    other.b = nullptr;
    return *this;
}
template <typename T>
calculator<T>::~calculator()
{
    delete a;
    delete b;
    delete result;
}

/// @brief add function
/// @return return int value
//
template <typename T>
T calculator<T>::add()
{
    *(this->result) = *a + *b;
    return *(this->result);
}
template class calculator<int>;
template class calculator<float>;