#include <fmt/core.h>
using namespace fmt;
class calculator
{
private:
    int *a;
    int *b;

public:
    int *result;
    calculator(int, int);
    int add();

    ~calculator();
};
