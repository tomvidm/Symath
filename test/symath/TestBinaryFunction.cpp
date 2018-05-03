#include "gtest/gtest.h"

#include "../../include/symath/Expression.hpp"
#include "../../include/symath/BinaryFunction.hpp"

TEST(TestSymath, binary_functions_works) {
    using namespace symath;

    const BinaryFunction<int>& none = BinaryFunction<int>::None;
    const BinaryFunction<int>& add = BinaryFunction<int>::Add;

    EXPECT_EQ(none(5 ,2), 5);
    EXPECT_EQ(add(5, 2), 7);
}