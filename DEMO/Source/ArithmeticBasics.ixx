export module ArithmeticBasics;

import <type_traits>;

namespace ZERO::Arithmetic
{
    template <typename T>
    constexpr T Square(T value)
    {
        static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type"); 
        return value * value;
    }

    template <typename... Args>
    constexpr auto Sum(Args&& ... args)
    {
        static_assert(sizeof...(Args) > 0); 
        return (args + ...);
    }

    template <typename T>
    constexpr T isEven = (T::value % 2 == 0);

    template <typename ...Args>
    constexpr auto CountEven(Args&& ...args)
    {
        static_assert(sizeof...(Args) > 0);
        return (... + isEven<Args>);
    }

    template<typename T>
    constexpr T Factorial(T n)
    {
        if constexpr (std::is_integral_v<T>)
        {
            if (n == 0)
                return 1;
            else
                return n * Factorial(n - 1);
        }
        else
        {
            static_assert(std::is_integral_v<T>, "T must be an integral type");
        }
    }
}