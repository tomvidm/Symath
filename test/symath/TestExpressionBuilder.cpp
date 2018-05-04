#include "gtest/gtest.h"

#include "../../include/symath/Expression.hpp"
#include "../../include/symath/UnaryFunction.hpp"
#include "../../include/symath/BinaryFunction.hpp"
#include "../../include/symath/ExpressionBuilder.hpp"

TEST(TestSymath, test_expression_builder_stack_behaviour) {
    using namespace symath;
    ExpressionBuilder<int> builder;
    builder.push(Expression<int>(5));
    builder.push(Expression<int>(2));
    builder.push(BinaryFunction<int>::Add);

}