#include "app/app.h"

int main(void)
{
    print("hello");
    calculator _calculator2(5, 5);
    _calculator2.add();
    print("the result is before :{} \n", *(_calculator2.result));

    {
        // calculator _calculator = _calculator2;
        printf(" app other.result %p \n", _calculator2.result);

        calculator _calculator(std::move(_calculator2));
        //_calculator2.add();

        *(_calculator.result) = 80;
        print("the result is :{} \n", *(_calculator.result));
    }

    // print("_calculator2.result : {} \n ", *(_calculator2.result));
}
