#include "neurone.hpp"

Neurone::Neurone(int inputSize)
: mPoids(inputSize)
, mActivation([] (float x) {return x;})
{
    for(size_t i(0); i < inputSize; i++)
        mPoids[i] = 1;
}

float Neurone::process(Eigen::VectorXf input) const
{
    float activation((mPoids.transpose()*input).value());
    return mActivation(activation);
}

std::ostream& operator<<(std::ostream& flux, Neurone n)
{
    flux << n.mPoids;
    return flux;
}


