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
    Eigen::Map<Eigen::RowVectorXf> mBufferInput(input.data(), input.size()+1);
    mBufferInput(mBufferInput.size()-1) = -1.f;

    return mBufferInput;
}


//***********RETROPROPAGATION***********
//**************************************


Eigen::VectorXf NeuronLayer::backProp(Eigen::VectorXf xnPartialDerivative)
{
    Eigen::VectorXf ynPartialDerivative = fnDerivativeMatrix(mBufferActivationLevel)*xnPartialDerivative;

    //Eigen::MatrixXf wnPartialDerivative = ynPartialDerivative
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
