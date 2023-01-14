#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>
template <typename T>
class calculator
{

public:
    const float pi = 3.14;

    calculator() = default;
    calculator(T, T);
    calculator(const calculator &);
    calculator &operator=(const calculator &other);
    calculator(calculator &&);
    calculator &operator=(calculator &&);
    ~calculator();

    T add();
    inline T get_result() const
    {
        return *result;
    }

private:
    std::unique_ptr<T> a{};
    std::unique_ptr<T> b;
    std::unique_ptr<T> result;
};

#endif