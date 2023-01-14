#include <calculator.h>
template <typename T>
calculator<T>::calculator(T a_, T b_) : a{std::make_unique<T>(a_)}, b{std::make_unique<T>(b_)}, result{std::make_unique<T>()}
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
calculator<T>::calculator(calculator &&other) : a{std::move(other.a)}, b{std::move(other.b)}
{
}
template <typename T>
calculator<T> &calculator<T>::operator=(calculator<T> &&other)
{
    a = std::move(other.a);
    b = std::move(other.b);
    return *this;
}
template <typename T>
calculator<T>::~calculator()
{
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