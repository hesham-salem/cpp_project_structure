#include "calculator/calculator.h"
#include <gtest/gtest.h>

using type = calculator<int>;
calculator<int> _calculator;

class add_test : public ::testing::Test
{
public:
    void SetUp() override
    {
        std::cout << "hello form constructor " << std::endl;
    }
    void TearDown() override
    {
        std::cout << "hello form deconstuctor " << std::endl;
    }

protected:
    calculator<float> _calculator;
};

TEST_F(add_test, add_postive_numbers)
{
    EXPECT_EQ(_calculator.add(2, 5), 7);
}
TEST_F(add_test, add_negative_numbers)
{
    EXPECT_EQ(_calculator.add(-2, -5), -7);
}
TEST_F(add_test, zeros_input)
{
    EXPECT_EQ(_calculator.add(0, 0), 0);
}
TEST_F(add_test, positive_no_and_negative_no)
{

    EXPECT_EQ(_calculator.add(-2, 5), 3);
    EXPECT_EQ(_calculator.add(2, -5), -3);
}
TEST_F(add_test, positive_no_and_zero)
{

    EXPECT_EQ(_calculator.add(-2, 0), -2);
    EXPECT_EQ(_calculator.add(0, -5), -5);
}
TEST_F(add_test, initializer_list)
{
    EXPECT_EQ(_calculator.add({1, 2, 3, 4, 5}), 15);
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
TEST(test_calculator_base, rest_result)
{
    calculator<int> _calculator;
    _calculator.add(1, 2);
    EXPECT_EQ(_calculator.get_result(), 3);

    _calculator.reset_result();
    EXPECT_EQ(_calculator.get_result(), 0);
}
void calculator_reset(calculator_base &calc)
{
    calc.reset_result();
}
TEST(test_calculator_base, using_interface)

{
    calculator<int> _calculator;
    _calculator.add(1, 2);
    EXPECT_EQ(_calculator.get_result(), 3);
    calculator_reset(_calculator);
    EXPECT_EQ(_calculator.get_result(), 0);
}
TEST(storage_result, storage_result)
{
    _calculator.add(7, 5);
    _calculator.save_result();
}

int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
