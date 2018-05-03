#pragma once

struct Operator {
    Operator(const char c);

    const enum Type {
        Addition,
        Subtraction,
        Multiplication,
        Division,
        Exponentiation,
        LeftParenthesis,
        RightParenthesis
    } type;

    const char asciiSymbol;

    static Type charToOperatorType(const char c);
};

bool operator > (const Operator& lhs, const Operator& rhs);
bool operator == (const Operator& lhs, const Operator& rhs);