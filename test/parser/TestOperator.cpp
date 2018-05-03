#include "gtest/gtest.h"

#include "../../include/parser/Operator.hpp"

TEST(TestParser, operator_type_correctly_set_from_char) {
    Operator add('+');
    Operator sub('-');
    Operator mul('*');
    Operator div('/');
    Operator exp('^');
    Operator lpr('(');
    Operator rpr(')');

    EXPECT_EQ(add.type, Operator::Type::Addition);
}