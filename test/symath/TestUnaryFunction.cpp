#include "gtest/gtest.h"

#include "../../include/symath/Expression.hpp"
#include "../../include/symath/UnaryFunction.hpp"

TEST(TestSymath, unary_functions_works) {
    using namespace symath;

    const UnaryFunction<int>& none = UnaryFunction<int>::None;
    const UnaryFunction<int>& negate = UnaryFunction<int>::Negate;

    EXPECT_EQ(none(5), 5);
    EXPECT_EQ(negate(5), -5);
}