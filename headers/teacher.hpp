#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"

class Teacher
{
    public:
        Teacher();

        void backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput) const;

    private:
        void propError(float error) const;

    private:
        NeuralNetwork::Ptr  mNetwork;
        Functions::ErrorFun mErrorFun;
};

#endif // TEACHER_HPP
