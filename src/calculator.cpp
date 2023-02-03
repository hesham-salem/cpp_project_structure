#include <calculator.h>

template <typename T>
calculator<T>::calculator() : result{std::make_unique<T>()}
{
}
template <typename T>
calculator<T>::calculator(T result) : result{std::make_unique<T>(result)}
{
}
template <typename T>
calculator<T>::calculator(const calculator &other) : calculator(*(other.result))
{
}
template <typename T>
calculator<T> &calculator<T>::operator=(const calculator<T> &other)
{
    *(this->result) = *(other.result);
    return *this;
}
template <typename T>
calculator<T>::calculator(calculator &&other) : result{std::move(other.result)}
{
}
template <typename T>
calculator<T> &calculator<T>::operator=(calculator<T> &&other)
{
    result = std::move(other.result);
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
T calculator<T>::add(T a, T b)
{
    return *(this->result) = a + b;
}
template <typename T>
T calculator<T>::product(T a, T b)
{
    if ((a == 0) || (b == 0))
    {
        throw std::invalid_argument("one of two arguments is zero");
    }

    return *(this->result) = a * b;
}
template class calculator<int>;
template class calculator<float>;