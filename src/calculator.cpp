#include "../include/calculator/calculator.h"

calculator::calculator(int a, int b)
{
    this->a = new int;
    *(this->a) = a;
    this->b = new int;
    *(this->b) = b;
    this->result = new int;
}
calculator::calculator(calculator &other)
{
    this->a = new int;
    this->b = new int;

    *(this->a) = *(other.a);
    *(this->b) = *(other.b);
    this->result = new int;
}
calculator &
calculator::operator=(const calculator &other)
{
    this->a = new int;
    this->b = new int;

    *(this->a) = *(other.a);
    *(this->b) = *(other.b);
    this->result = new int;
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