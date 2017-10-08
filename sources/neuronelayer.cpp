#include "headers/neuronelayer.hpp"

NeuroneLayer::NeuroneLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF)
: mPoids(Eigen::MatrixXf::Random(outputSize, inputSize))
, mActivationFun(activationF)
{
    std::cout << mPoids << std::endl;
}

Eigen::VectorXf NeuroneLayer::process(Eigen::VectorXf inputs) const
{
    Eigen::VectorXf activationLevel = mPoids*inputs;
    for(unsigned int i(0); i < activationLevel.size(); i++)
        activationLevel[i] = mActivationFun(activationLevel[i]);

    return activationLevel;
}
