#pragma once

namespace math {
    template <typename T>
    struct Rational {
        Rational();
        Rational(const T val);
        Rational(const T num, const T den);

        T operator() () const;

        const T numerator;
        const T denominator;
    };

    template <typename T>
    Rational<T>::Rational() 
    : numerator(0), numerator(1) {;}

    template <typename T>
    Rational<T>::Rational(const T val)
    : numerator(val), denominator(1) {;}

    template <typename T>
    Rational<T>::Rational(const T num, const T den)
    : numerator(num), denominator(den) {;}

    template <typename T>
    T Rational<T>::operator() () const {
        return numerator / denominator;
    }
}