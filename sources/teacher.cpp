#include "headers/teacher.hpp"

Teacher::Teacher()
: mNetwork(nullptr)
, mErrorFun(Functions::l2Norm())
{

}

void Teacher::backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput, float step, float dx)
{
    Eigen::VectorXf deltaX = dx*Eigen::MatrixXf::Ones(desiredOutput.size(), 1);

    Eigen::VectorXf xnPartialDerivative = errorVector(mNetwork->process(input), desiredOutput, dx);

    propError(xnPartialDerivative, step);
}

void Teacher::propError(Eigen::VectorXf xnPartialDerivative, float step)
{
    for(auto itr = mNetwork->rbegin(); itr != mNetwork->rend(); ++itr)
    {
        xnPartialDerivative = itr->backProp(xnPartialDerivative, step);
    }
}

Eigen::VectorXf Teacher::errorVector(Eigen::VectorXf output, Eigen::VectorXf desiredOutput, float dx)
{
    Eigen::VectorXf errorVect = Eigen::MatrixXf::Zero(output.size(), 1);

    for(unsigned int i(0); i < output.size(); ++i)
    {
        Eigen::VectorXf deltaX(Eigen::MatrixXf::Zero(output.size(), 1));
        deltaX(i) = dx;
        errorVect(i) = (mErrorFun(output + deltaX, desiredOutput) - mErrorFun(output, desiredOutput))/dx;
    }

    return errorVect;
}
