#include "calculator/calculator.h"
#include <gtest/gtest.h>
TEST(add_test, add_postive_numbers)
{
    calculator<float> _calculator;
    EXPECT_EQ(_calculator.add(2, 5), 7);
}
TEST(add_test, add_negative_numbers)
{
    calculator<float> _calculator;
    EXPECT_EQ(_calculator.add(-2, -5), -7);
}
TEST(add_test, zeros_input)
{
    calculator<float> _calculator;
    EXPECT_EQ(_calculator.add(0, 0), 0);
}
TEST(add_test, positive_no_and_negative_no)
{
    calculator<float> _calculator;

    EXPECT_EQ(_calculator.add(-2, 5), 3);
    EXPECT_EQ(_calculator.add(2, -5), -3);
}
TEST(add_test, positive_no_and_zero)
{
    calculator<float> _calculator;

    EXPECT_EQ(_calculator.add(-2, 0), -2);
    EXPECT_EQ(_calculator.add(0, -5), -5);
}
TEST(product_test, product_non_zero)
{
    calculator<float> _calculator;

    EXPECT_THROW(_calculator.product(0, 1), std::invalid_argument);
}
TEST(product_test, postive_2_arguments)
{
    calculator<float> _calculator;

    EXPECT_EQ(_calculator.product(2, 1), 2);
}
TEST(specify_operation_, add)
{
    calculator<int> _calculator;
    EXPECT_EQ(_calculator.specify_operation(2, 3, [](int a, int b)
                                            { return a + b; }),
              5);
}
TEST(specify_operation_, add_with_global_variable)
{
    calculator<int> _calculator;
    int a = 5;
    int b = 6;
    EXPECT_EQ(_calculator.specify_operation(2, 3, [&](int v, int c)
                                            { return a + b; }),
              11);
}
TEST(specify_operation_, lumba_with_name)
{
    calculator<int> _calculator;
    int a = 5;
    int b = 6;
    auto fun = [=](int v, int c)
    { return a + b; };
    EXPECT_EQ(_calculator.specify_operation(2, 3, fun), 11);
}
int fun(int v, int c)
{
    return v + c;
}
TEST(specify_operation_, function)
{
    calculator<int> _calculator;

    EXPECT_EQ(_calculator.specify_operation(6, 6, fun), 12);
}
TEST(specify_operation_, functor)
{
    class add
    {
    public:
        int operator()(int a, int b)
        {
            return a + b;
        }
    };
    calculator<int> _calculator;
    add _add;
    EXPECT_EQ(_calculator.specify_operation(2, 2, _add), 4);
}
int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
