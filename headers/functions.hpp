#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <functional>

class Functions
{
    public:
        using ActivationFun = std::function<float(float)>;

        static ActivationFun sigmoid(float lambda);
        static ActivationFun heavyside(float gapAbscissa);
};

#endif // FUNCTIONS_HPP
