export module LogicalBasics;

namespace ZERO::Logical
{
    template<typename... Args>
    concept All = requires(Args... args)
    {
        { (args && ...) };
    };

    template<typename... Args>
    concept Any = requires(Args... args)
    {
        { (args || ...) };
    };
}
