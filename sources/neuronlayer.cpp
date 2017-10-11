#include "headers/neuronlayer.hpp"

NeuronLayer::NeuronLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF)
: mPoids(Eigen::MatrixXf::Random(outputSize, inputSize+1))
, mActivationFun(activationF)
{}

Eigen::VectorXf NeuronLayer::process(Eigen::VectorXf inputs) const
{
    Eigen::VectorXf activationLevel = mPoids*processInput(inputs);;
    
    for(unsigned int i(0); i < activationLevel.size(); i++)
        activationLevel[i] = mActivationFun(activationLevel[i]);

    return activationLevel;
}

Eigen::VectorXf NeuronLayer::processInput(Eigen::VectorXf input) const
{
    Eigen::Map<Eigen::RowVectorXf> biaisedInput(input.data(), input.size()+1);
    biaisedInput(biaisedInput.size()-1) = -1.f;
    return biaisedInput;
}

std::ostream& operator<<(std::ostream& flux, NeuronLayer n)
{
    flux << n.mPoids;
    return flux;
}
