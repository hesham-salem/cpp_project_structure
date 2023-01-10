#include "app.h"
using fmt::print;
using std::printf;
#include <vector>
int main(void)
{
    // print("hello \n");
    calculator<float> _calculator2(5, 5);
    //_calculator2.add();
    //  print("the result is before :{} \n", *(_calculator2.result));

    {
        calculator<float> _calculator(1, 2);
        //   auto _calculator3 = _calculator = _calculator2;
        //  printf(" app other.result %p \n", _calculator2.result);

        //   calculator _calculator(std::move(_calculator2));
        //_calculator3.add();

        _calculator.add();
        //   *(_calculator.result) = 80;
        print("the result is :{} \n", *(_calculator.result));
    }

    // print("_calculator2.result : {} \n ", *(_calculator2.result));
}
