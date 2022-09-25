#include "../include/calculator/calculator.h"
void calculator::init()
{
    this->a = new int;
    this->b = new int;
    this->result = new int;
}
calculator::calculator(int a, int b)
{
    init();
    *(this->a) = a;
    *(this->b) = b;
}
calculator::calculator(calculator &other)
{
    init();

    *(this->a) = *(other.a);
    *(this->b) = *(other.b);
}
calculator &
calculator::operator=(const calculator &other)
{
    init();
    *(this->a) = *(other.a);
    *(this->b) = *(other.b);
}
/// @brief add function
/// @return return int value
int calculator::add()
{
    *(this->result) = *a + *b;
    return *(this->result);
}

calculator::~calculator()
{
    delete a, b, result;
}