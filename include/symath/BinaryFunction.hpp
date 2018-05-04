#pragma once

namespace symath {
    enum class BinaryFunctionType {
        None,
        Add,
        Subtract,
        Multiply,
        Divide,
        Power,
        ModularPower
    };

    template <typename T>
    class BinaryFunction {
    public:
        T operator () (const T& arg1, const T& arg2) const;
    public:
        static const BinaryFunction<T> None;
        static const BinaryFunction<T> Add;
        static const BinaryFunction<T> Subtract;
        static const BinaryFunction<T> Multiply;
        static const BinaryFunction<T> Divide;
    public:
        BinaryFunction(const BinaryFunctionType type);
    private:
        BinaryFunctionType functionType;
    };

    template <typename T>
    T BinaryFunction<T>::operator () (const T& arg1, const T& arg2) const {
        switch (functionType) {
            case BinaryFunctionType::None:
                return arg1;
            case BinaryFunctionType::Add:
                return arg1 + arg2;
            case BinaryFunctionType::Subtract:
                return arg1 - arg2;
            case BinaryFunctionType::Multiply:
                return arg1 * arg2;
            case BinaryFunctionType::Divide:
                return arg1 / arg2;
            default:
                return arg1;
        }
    }

    template <typename T>
    BinaryFunction<T>::BinaryFunction(const BinaryFunctionType type) 
    : functionType(type) {
        ;
    }

    template <typename T>
    const BinaryFunction<T> BinaryFunction<T>::None(BinaryFunctionType::None);

    template <typename T>
    const BinaryFunction<T> BinaryFunction<T>::Add(BinaryFunctionType::Add);

    template <typename T>
    const BinaryFunction<T> BinaryFunction<T>::Subtract(BinaryFunctionType::Subtract);

    template <typename T>
    const BinaryFunction<T> BinaryFunction<T>::Multiply(BinaryFunctionType::Multiply);

    template <typename T>
    const BinaryFunction<T> BinaryFunction<T>::Divide(BinaryFunctionType::Divide);
}