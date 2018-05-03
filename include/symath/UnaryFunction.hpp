#pragma once

namespace symath {
    enum class UnaryFunctionType {
        None,
        Negate
    };

    template <typename T>
    class UnaryFunction {
    public:
        T operator () (const T& arg) const;
    public:
        static UnaryFunction<T> None;
        static UnaryFunction<T> Negate;
    public:
        UnaryFunction(const UnaryFunctionType type);
    private:
        UnaryFunctionType functionType;
    };

    template <typename T>
    T UnaryFunction<T>::operator () (const T& arg) const {
        switch (functionType) {
            case UnaryFunctionType::None:
                return arg;
            case UnaryFunctionType::Negate:
                return -arg;
            default:
                return arg;
        }
    }

    template <typename T>
    UnaryFunction<T>::UnaryFunction(const UnaryFunctionType type) 
    : functionType(type) {
        ;
    }

    template <typename T>
    UnaryFunction<T> UnaryFunction<T>::None(UnaryFunctionType::None);

    template <typename T>
    UnaryFunction<T> UnaryFunction<T>::Negate(UnaryFunctionType::Negate);
}