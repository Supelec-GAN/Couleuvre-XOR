#include "headers/neuronelayer.hpp"

NeuroneLayer::NeuroneLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF)
: mPoids(Eigen::MatrixXf::Random(outputSize, inputSize))
, mActivationFun(activationF)
{
}

Eigen::VectorXf NeuroneLayer::process(Eigen::VectorXf inputs) const
{
    Eigen::VectorXf activationLevel = mPoids*inputs;
    
    for(unsigned int i(0); i < activationLevel.size(); i++)
        activationLevel[i] = mActivationFun(activationLevel[i]);

    return activationLevel;
}

std::ostream& operator<<(std::ostream& flux, NeuroneLayer n)
{
    flux << n.mPoids;
    return flux;
}
