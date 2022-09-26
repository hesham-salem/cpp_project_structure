//#include <fmt/core.h>
// using namespace fmt;
class calculator
{
private:
    int *a;
    int *b;

public:
    int *result; // tee

    void init();
    calculator() = default;
    calculator(int, int);
    calculator(calculator &);
    calculator &operator=(const calculator &other);
    calculator(calculator &&);
    calculator &&operator=(calculator &&);
    int add();

    ~calculator();
};
