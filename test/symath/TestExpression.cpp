#include "gtest/gtest.h"

#include "../../include/symath/Expression.hpp"
#include "../../include/symath/UnaryFunction.hpp"

TEST(TestSymath, test_expressions_and_operations_between_them) {
    using namespace symath;

    std::shared_ptr<Expression<int>> five = 
        std::make_shared<Expression<int>>(5);

    EXPECT_EQ(*five, 5);

    std::shared_ptr<Expression<int>> two = 
        std::make_shared<Expression<int>>(2);

    std::shared_ptr<Expression<int>> negateFive = 
        std::make_shared<Expression<int>>(five, UnaryFunction<int>::Negate);

    EXPECT_EQ(*negateFive, -5);

    std::shared_ptr<Expression<int>> negativeTwo = 
        std::make_shared<Expression<int>>(two, UnaryFunction<int>::Negate);

    std::shared_ptr<Expression<int>> addFiveAndTwo = 
        std::make_shared<Expression<int>>(five, two, BinaryFunction<int>::Add);

    EXPECT_EQ(*addFiveAndTwo, 7);

    std::shared_ptr<Expression<int>> addFiveAndNegatedTwo = 
        std::make_shared<Expression<int>>(five, negativeTwo, BinaryFunction<int>::Add);

    EXPECT_EQ(*addFiveAndNegatedTwo, 3);

    std::shared_ptr<Expression<int>> subtractTwoExpressions = 
        std::make_shared<Expression<int>>(addFiveAndTwo, addFiveAndNegatedTwo, BinaryFunction<int>::Subtract);

    EXPECT_EQ(*subtractTwoExpressions, 4);

    std::shared_ptr<Expression<int>> multiplyTwoExpressions =
        std::make_shared<Expression<int>>(two, addFiveAndTwo, BinaryFunction<int>::Multiply);

    EXPECT_EQ(*multiplyTwoExpressions, 14);

    std::shared_ptr<Expression<int>> divideTwoExpressions =
        std::make_shared<Expression<int>>(multiplyTwoExpressions, two, BinaryFunction<int>::Divide);

    EXPECT_EQ(*divideTwoExpressions, 7);
    
    
}