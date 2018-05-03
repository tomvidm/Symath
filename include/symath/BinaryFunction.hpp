#pragma once

namespace symath {
    enum class BinaryFunctionType {
        None,
        Add,
        Subtract
    };

    template <typename T>
    class BinaryFunction {
    public:
        T operator () (const T& arg1, const T& arg2) const;
    public:
        static BinaryFunction<T> None;
        static BinaryFunction<T> Add;
        static BinaryFunction<T> Subtract;
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
    BinaryFunction<T> BinaryFunction<T>::None(BinaryFunctionType::None);

    template <typename T>
    BinaryFunction<T> BinaryFunction<T>::Add(BinaryFunctionType::Add);

    template <typename T>
    BinaryFunction<T> BinaryFunction<T>::Subtract(BinaryFunctionType::Subtract);
}