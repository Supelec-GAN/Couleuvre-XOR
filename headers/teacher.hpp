#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "headers/neuralnetwork.hpp"

class Teacher
{
    public:
        Teacher();

        void backProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput) const;

    private:
        void propError(float error) const;

    private:
        NeuralNetwork::Ptr mNetwork;
        std::function<float(Eigen::VectorXf, Eigen::VectorXf)> mErrorFun;
};

#endif // TEACHER_HPP
