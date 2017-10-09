#include "headers/neuronlayer.hpp"

NeuronLayer::NeuronLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF)
: mPoids(Eigen::MatrixXf::Random(outputSize, inputSize))
, mBiais(Eigen::MatrixXf::Zero(outputSize, 1))
, mActivationFun(activationF)
{
}

Eigen::VectorXf NeuronLayer::process(Eigen::VectorXf inputs) const
{
    Eigen::VectorXf activationLevel = mPoids*inputs - mBiais;;
    
    for(unsigned int i(0); i < activationLevel.size(); i++)
        activationLevel[i] = mActivationFun(activationLevel[i]);

    return activationLevel;
}

std::ostream& operator<<(std::ostream& flux, NeuronLayer n)
{
    flux << n.mPoids;
    return flux;
}
