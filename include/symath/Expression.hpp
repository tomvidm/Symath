#pragma once

#include <memory>
#include <string>

#include "UnaryFunction.hpp"
#include "BinaryFunction.hpp"

namespace symath {
    enum class ExpressionType {
        Unset,
        UnaryFunction,  // -2, sin(pi), conj(2)
        BinaryFunction, // 2 + 3, 
        Variable,       // x, y, z
        Constant        // 2, 5, pi, e
    };

    template <typename T>
    class Expression {
    public:
        using shared = std::shared_ptr<Expression<T>>;
    public:
        Expression();
        Expression(const T& val);
        Expression(const Expression<T>& other); // TODO: Copy constructor does not copy all. (How to copy const values inside union?)
        Expression(Expression<T>::shared expr, const UnaryFunction<T>& func);
        Expression(Expression<T>::shared expr1, Expression<T>::shared expr2, const BinaryFunction<T>& func);
        ~Expression();

        const ExpressionType getExpressionType() const;
        const T calculate() const;
    protected:
        union {
            struct {
                std::shared_ptr<Expression<T>> arg;
                const UnaryFunction<T>& function;
            } unary;
            struct {
                std::shared_ptr<Expression<T>> arg1;
                std::shared_ptr<Expression<T>> arg2;
                const BinaryFunction<T>& function;
            } binary;
            T variableValue;
            const T constantValue;
        };
        ExpressionType type;

        bool hasCachedValue;
        T cachedValue;
    private:
        void setCached(const T& value);
    };

    template <typename T>
    Expression<T>::Expression(Expression<T>::shared expr, const UnaryFunction<T>& func)
    : unary{expr, func},
      type(ExpressionType::UnaryFunction),
      hasCachedValue(false) {  
        ;
    }

    template <typename T>
    Expression<T>::Expression(Expression<T>::shared expr1, Expression<T>::shared expr2, const BinaryFunction<T>& func)
    : binary{expr1, expr2, func}, 
      type(ExpressionType::BinaryFunction),
      hasCachedValue(false) {
        ;
    }

    template <typename T>
    const ExpressionType Expression<T>::getExpressionType() const {
        return type;
    }

    template <typename T>
    const T Expression<T>::calculate() const {
        if (hasCachedValue) {
            return cachedValue;
        } else {
            switch (type) {
                case ExpressionType::UnaryFunction:
                    // Precalculate and store to cachedValue variable,
                    // then return it.
                    return unary.function(unary.arg->calculate());
                case ExpressionType::BinaryFunction:
                    // Precalculate and store to cachedValue variable,
                    // then return it.
                    return binary.function(binary.arg1->calculate(), 
                                           binary.arg2->calculate());
                case ExpressionType::Variable:
                    return variableValue;
                case ExpressionType::Constant:
                    return constantValue;
                default:
                    return T();
            }
        }
    }

    template <typename T>
    void Expression<T>::setCached(const T& value) {
        hasCachedValue = true;
        cachedValue = value;
    }

    template <typename T>
    Expression<T>::Expression()
    : type(ExpressionType::Unset) {
        ;
    }

    template <typename T>
    Expression<T>::Expression(const T& val)
    : variableValue(val),
      type(ExpressionType::Constant),
      hasCachedValue(false) {
          ;
    }
    template <typename T>
    Expression<T>::Expression(const Expression<T>& other)
    : 
      type(other.type),
      hasCachedValue(other.hasCachedValue) {

    }
/*
    template <typename T>
    Expression<T>::Expression(const Expression<T>::shared& otherPtr);
 */
    template <typename T>
    Expression<T>::~Expression() {
        switch (type) {
            case ExpressionType::UnaryFunction:
                unary.arg.~shared_ptr();
                break;
            case ExpressionType::BinaryFunction:
                binary.arg1.~shared_ptr();
                binary.arg2.~shared_ptr();
                break;
            default:
                break;  
        }
    }

    template <typename T>
    bool operator == (const Expression<T>& lhs, const T rhs) {
        return lhs.calculate() == rhs;
    }

    template <typename T>
    bool operator == (const T lhs, const Expression<T>& rhs) {
        return lhs.calculate() == rhs;
    }

    template <typename T>
    bool operator == (const Expression<T>& lhs, const Expression<T>& rhs) {
        return lhs.calculate() == rhs.calculate();
    }
}
