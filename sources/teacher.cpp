#include "headers/teacher.hpp"

Teacher::Teacher()
: mNetwork(nullptr)
, mErrorFun(Functions::l2Norm())
{

}

void Teacher::backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput) const
{
    propError(mErrorFun(input, desiredOutput));
}

void Teacher::propError(float error) const
{

}
