#include "../../include/parser/Operator.hpp"

Operator::Operator(const char c)
: type(charToOperatorType(c)), asciiSymbol(c) {
    ;
}

Operator::Type Operator::charToOperatorType(const char c) {
    switch (c) {
        case '+': return Operator::Type::Addition;
        case '-': return Operator::Type::Subtraction;
        case '*': return Operator::Type::Multiplication;
        case '/': return Operator::Type::Division;
        case '^': return Operator::Type::Exponentiation;
        case '(': return Operator::Type::LeftParenthesis;
        case ')': return Operator::Type::RightParenthesis;
    }
}

bool operator > (const Operator& lhs, const Operator& rhs) {
    return lhs.type < rhs.type;
}

bool operator == (const Operator& lhs, const Operator& rhs) {
    return lhs.type == rhs.type;
}