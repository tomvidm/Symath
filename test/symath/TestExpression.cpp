#include "gtest/gtest.h"

#include "../../include/symath/Expression.hpp"
#include "../../include/symath/UnaryFunction.hpp"

TEST(TestSymath, expression_contruction_works) {
    using namespace symath;

    std::shared_ptr<Expression<int>> five = std::make_shared<Expression<int>>(5);
    std::shared_ptr<Expression<int>> two = std::make_shared<Expression<int>>(2);
    std::shared_ptr<Expression<int>> negateFive = std::make_shared<Expression<int>>(five, UnaryFunction<int>::Negate);
    std::shared_ptr<Expression<int>> negativeTwo = std::make_shared<Expression<int>>(two, UnaryFunction<int>::Negate);
    std::shared_ptr<Expression<int>> addFiveAndTwo = std::make_shared<Expression<int>>(five, two, BinaryFunction<int>::Add);
    std::shared_ptr<Expression<int>> addFiveAndNegatedTwo = std::make_shared<Expression<int>>(five, negativeTwo, BinaryFunction<int>::Add);
    std::shared_ptr<Expression<int>> subtractTwoExpressions = std::make_shared<Expression<int>>(addFiveAndTwo, addFiveAndNegatedTwo, BinaryFunction<int>::Subtract);

    EXPECT_EQ(five->calculate(), 5);
    EXPECT_EQ(negateFive->calculate(), -5);
    EXPECT_EQ(addFiveAndTwo->calculate(), 7);
    EXPECT_EQ(addFiveAndNegatedTwo->calculate(), 3);
    EXPECT_EQ(subtractTwoExpressions->calculate(), 4);
}