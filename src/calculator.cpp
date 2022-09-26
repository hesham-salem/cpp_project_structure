#include "../include/calculator/calculator.h"
#include <cstdio>

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
/// @warning try to avoid use it
//
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
calculator::calculator(calculator &&other)
{
    init();

    printf("other.result %p \n", other.result);

    this->a = other.a;
    this->b = other.b;
    other.a = nullptr;
    other.b = nullptr;
}
calculator &&
calculator::operator=(calculator &&other)
{
    init();
    this->a = other.a;
    this->b = other.b;
    other.a = nullptr;
    other.b = nullptr;
}
/// @brief add function
/// @return return int value
//
int calculator::add()
{
    *(this->result) = *a + *b;
    return *(this->result);
}

calculator::~calculator()
{
    delete a, b, result;
}