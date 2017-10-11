#include "headers/teacher.hpp"

Teacher::Teacher()
: mNetwork(nullptr)
, mErrorFun()
{

}

void Teacher::backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput) const
{
    propError(0.f);
}

void Teacher::propError(float error) const
{

}
