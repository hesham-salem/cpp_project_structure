#include "app/app.h"

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

int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
