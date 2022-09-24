#include "../include/calculator/calculator.h"

calculator::calculator(int a, int b)
{
    this->a = new int;
    *(this->a) = a;
    this->b = new int;
    *(this->b) = b;
}
int calculator::add()
{
    *(this->result) = *a + *b;
    return *(this->result);
}

calculator::~calculator()
{
    print("deconstractor bye");
}