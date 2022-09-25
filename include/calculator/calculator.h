//#include <fmt/core.h>
// using namespace fmt;
class calculator
{
private:
    int *a;
    int *b;

public:
    int *result;

    void init();

    calculator(int, int);
    calculator(calculator &);
    calculator &operator=(const calculator &other);
    int add();

    ~calculator();
};
