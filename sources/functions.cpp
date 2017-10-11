#include "headers/functions.hpp"

#include <cmath>

Functions::ActivationFun Functions::sigmoid(float lambda)
{
    return [] (float x) {return 1.f/(1.f + exp(-lambda*x));};
}

Functions::ActivationFun Functions::heavyside(float gapAbscissa)
{
    return [] (float x) {return (x < gapAbscissa) ? 0 : 1;};
}
