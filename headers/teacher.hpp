#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"

class Teacher
{
    public:
                        Teacher();

        void            backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput, float step = 0.2, float dx = 0.05);

    private:
        void            propError(Eigen::VectorXf xnPartialDerivative, float step);
        Eigen::VectorXf errorVector(Eigen::VectorXf output, Eigen::VectorXf desiredOutput, float dx);

    private:
        NeuralNetwork::Ptr  mNetwork;
        Functions::ErrorFun mErrorFun;
};

#endif // TEACHER_HPP
