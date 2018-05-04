#pragma once

#include <stack>

#include "Expression.hpp"
#include "BinaryFunction.hpp"
#include "UnaryFunction.hpp"

namespace symath {
    template <typename T>
    class ExpressionBuilder {
    public:
        void push(const Expression<T>& expr);
        void push(const UnaryFunction<T>& unaryFunction);
        void push(const BinaryFunction<T>& binaryFunction);

        void step();
        void handleBinaryFunction();
    public:
        enum class TermType {
            Expression,
            UnaryFunction,
            BinaryFunction
        };
    private:
        std::stack<TermType> termTypeStack;
        std::stack<UnaryFunction<T>> unaryFunctions;
        std::stack<BinaryFunction<T>> binaryFunctions;
        std::stack<Expression<T>> expressionStack;
    };

    template <typename T>
    void ExpressionBuilder<T>::push(const Expression<T>& expr) {
        termTypeStack.push(TermType::Expression);
        expressionStack.push(expr);
    }

    template <typename T>
    void ExpressionBuilder<T>::push(const UnaryFunction<T>& unaryFunction) {
        termTypeStack.push(TermType::UnaryFunction);
        unaryFunctions.push(unaryFunction);
    }

    template <typename T>
    void ExpressionBuilder<T>::push(const BinaryFunction<T>& binaryFunction) {
        termTypeStack.push(TermType::BinaryFunction);
        binaryFunctions.push(binaryFunction);
    }

    template <typename T>
    void ExpressionBuilder<T>::step() {
        if (termTypeStack.top() == ExpressionBuilder::TermType::BinaryFunction) {
            termTypeStack.pop();
            handleBinaryFunction();
        }
    }

    template <typename T>
    void ExpressionBuilder<T>::handleBinaryFunction() {
        BinaryFunction<T> binFunc = binaryFunctions.top();
        binaryFunctions.pop();
    }
}