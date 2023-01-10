#ifndef CALCULATOR_H
#define CALCULATOR_H
template <typename T>
class calculator
{

public:
    const float pi = 3.14;
    T *result;
    calculator() = default;
    calculator(T, T);
    calculator(const calculator &);
    calculator &operator=(const calculator &other);
    calculator(calculator &&);
    calculator &operator=(calculator &&);
    ~calculator();

    T add();

private:
    T *a;
    T *b;
};

#endif