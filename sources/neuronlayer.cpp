#include "headers/neuronlayer.hpp"

//*************CONSTRUCTEUR*************
//**************************************

NeuronLayer::NeuronLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF)
: mPoids(Eigen::MatrixXf::Random(outputSize, inputSize+1))
, mActivationFun(activationF)
, mBufferActivationLevel(Eigen::MatrixXf::Zero(outputSize, 1))
{}


//*************PROPAGATION**************
//**************************************

Eigen::VectorXf NeuronLayer::process(Eigen::VectorXf inputs)
{
    mBufferActivationLevel = Eigen::VectorXf(mPoids*processInput(inputs));;
    Eigen::VectorXf output = mBufferActivationLevel;

    for(unsigned int i(0); i < mBufferActivationLevel.size(); i++)
        output[i] = mActivationFun(output[i]);

    return output;
}

Eigen::VectorXf NeuronLayer::processInput(Eigen::VectorXf input) const
{
    Eigen::Map<Eigen::RowVectorXf> biaisedInput(input.data(), input.size()+1);
    biaisedInput(biaisedInput.size()-1) = -1.f;
    return biaisedInput;
}


//***********RETROPROPAGATION***********
//**************************************


Eigen::VectorXf NeuronLayer::backProp(Eigen::VectorXf xnPartialDerivative)
{

}

Eigen::MatrixXf NeuronLayer::fnDerivativeMatrix(Eigen::VectorXf ynPartialDerivative) const
{
    auto fnDerivated = [this] (float x, float dx)
                        {
                            return (mActivationFun(x+dx) - mActivationFun(x))/dx;
                        };

    Eigen::VectorXf fnDerivativeMat(ynPartialDerivative.size());
    for(auto i(0); i < ynPartialDerivative.size(); ++i)
        fnDerivativeMat(i) = fnDerivated(ynPartialDerivative(i), 0.05);

    return Eigen::MatrixXf(fnDerivativeMat.asDiagonal());
}

//*************AUXILIAIRES**************
//**************************************

std::ostream& operator<<(std::ostream& flux, NeuronLayer n)
{
    flux << n.mPoids;
    return flux;
}
