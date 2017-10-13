#include "headers/teacher.hpp"

Teacher::Teacher(NeuralNetwork::Ptr network)
: mNetwork(network)
, mErrorFun(Functions::l2Norm())
{}

Teacher::Teacher(NeuralNetwork* network)
: mNetwork(network)
, mErrorFun(Functions::l2Norm())
{}

void Teacher::backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput, float step, float dx)
{
    Eigen::VectorXf xnPartialDerivative = errorVector(mNetwork->process(input), desiredOutput, dx);

    propError(xnPartialDerivative, step);
}

void Teacher::propError(Eigen::VectorXf xnPartialDerivative, float step)
{
    float epsilon = 0.02; //Paramètre à fixer

    auto max = xnPartialDerivative(0);
    for(auto i(1); i<xnPartialDerivative.size(); i++)
    {
        if (max < xnPartialDerivative(i))
           max = xnPartialDerivative(i);
    }

    if (max < epsilon)
    {
        for(auto itr = mNetwork->rbegin(); itr != mNetwork->rend(); ++itr)
        {
            xnPartialDerivative = itr->backProp(xnPartialDerivative, step);
        }
    }
}

Eigen::VectorXf Teacher::errorVector(Eigen::VectorXf output, Eigen::VectorXf desiredOutput, float dx)
{
    Eigen::VectorXf errorVect = Eigen::MatrixXf::Zero(output.size(), 1);

    Eigen::VectorXf deltaX(Eigen::MatrixXf::Zero(output.size(), 1));

    for(unsigned int i(0); i < output.size(); ++i)
    {
        deltaX((i-1)%output.size()) = 0;
        deltaX(i) = dx;
        errorVect(i) = (mErrorFun(output + deltaX, desiredOutput) - mErrorFun(output, desiredOutput))/dx;
    }

    return errorVect;
}
