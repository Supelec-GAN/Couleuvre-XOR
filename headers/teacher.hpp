#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"

class Teacher
{
    public:
        Teacher();

        void backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput, float step) const;

    private:
        void propError(float error, float step) const;

    private:
        NeuralNetwork::Ptr  mNetwork;
        Functions::ErrorFun mErrorFun;
};

#endif // TEACHER_HPP
