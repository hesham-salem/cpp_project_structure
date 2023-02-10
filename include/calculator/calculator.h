#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <memory>
#include <stdexcept>
#include <functional>
template <typename T>
class calculator
{

public:
    const float pi = 3.14;

    calculator();
    calculator(T);
    calculator(const calculator &);
    calculator &operator=(const calculator &other);
    calculator(calculator &&other);
    calculator &operator=(calculator &&otheer);
    ~calculator();

    T add(T first_no, T second_no);
    T product(T first_no, T second_no);
    T specify_operation(T first_no, T second_no, std::function<T(T, T)> const &func);
    inline T get_result() const
    {
        return *result;
    }
    inline T get_last_operation_value() const
    {
        return *last_operation_value;
    }

private:
    std::unique_ptr<T> last_operation_value;
    std::unique_ptr<T> result;
};

#endif