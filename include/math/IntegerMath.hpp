#pragma once

namespace math {
    template <typename T>
    T iexp(T base, T exp) {
        T result = 1;
        while (exp > 0) {
            if (exp & 1) {
                result *= base;
            }
            exp >>= 1;
            base *= base;
        }
        return result;
    }

    template <typename T>
    T modexp(T base, T exp, T mod) {
        if (mod == 0) {
            return iexp<T>(base, exp);
        } else {
            T result = 1;
            while (exp) {
                if (exp & 1) {
                    result *= base;
                    base %= mod;
                }
                exp >>= 1;
                base *= base;
                base %= mod;
            }
            return result;
        }
    }
}
