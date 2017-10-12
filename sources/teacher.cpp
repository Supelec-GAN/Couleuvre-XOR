#include "headers/teacher.hpp"

Teacher::Teacher()
: mNetwork(nullptr)
, mErrorFun(Functions::l2Norm())
{

}

void Teacher::backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput, float step) const
{
    propError(mErrorFun(input, desiredOutput), step);
}

void Teacher::propError(float error, float step) const
{

}
