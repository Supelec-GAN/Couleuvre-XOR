#include "headers/neuronlayer.hpp"

//*************CONSTRUCTEUR*************
//**************************************

NeuronLayer::NeuronLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF)
: mPoids(Eigen::MatrixXf::Random(outputSize, inputSize+1))
, mActivationFun(activationF)
, mBufferActivationLevel(Eigen::MatrixXf::Zero(outputSize, 1))
, mBufferInput(Eigen::MatrixXf::Zero(inputSize+1, 1))
{}


//*************PROPAGATION**************
//**************************************

Eigen::VectorXf NeuronLayer::process(Eigen::VectorXf inputs)
{
    mBufferActivationLevel = Eigen::VectorXf(mPoids*processInput(inputs));;
    Eigen::VectorXf output = mBufferActivationLevel;

    for(unsigned int i(0); i < output.size(); i++)
        output[i] = mActivationFun(output[i]);

    return output;
}

Eigen::VectorXf NeuronLayer::processInput(Eigen::VectorXf input)
{
    mBufferInput = Eigen::Map<Eigen::VectorXf>(input.data(), input.size()+1);
    mBufferInput(mBufferInput.size()-1) = -1.f;

    return mBufferInput;
}


//***********RETROPROPAGATION***********
//**************************************


Eigen::VectorXf NeuronLayer::backProp(Eigen::VectorXf xnPartialDerivative, float step)
{
    Eigen::VectorXf ynPartialDerivative = fnDerivativeMatrix()*xnPartialDerivative;

    Eigen::MatrixXf wnPartialDerivative = ynPartialDerivative*(mBufferInput.transpose());

    mPoids -= step*wnPartialDerivative;

    return mPoids.transpose()*ynPartialDerivative;
}

Eigen::MatrixXf NeuronLayer::fnDerivativeMatrix() const
{
    auto fnDerivated = [this] (float x, float dx)
                        {
                            return (mActivationFun(x+dx) - mActivationFun(x))/dx;
                        };

    Eigen::VectorXf fnDerivativeMat(mBufferActivationLevel.size());
    for(auto i(0); i < mBufferActivationLevel.size(); ++i)
        fnDerivativeMat(i) = fnDerivated(mBufferActivationLevel(i), 0.05);

    return Eigen::MatrixXf(fnDerivativeMat.asDiagonal());
}

//*************AUXILIAIRES**************
//**************************************

std::ostream& operator<<(std::ostream& flux, NeuronLayer n)
{
    flux << n.mPoids;
    return flux;
}
