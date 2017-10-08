#ifndef NEURONELAYER_HPP
#define NEURONELAYER_HPP

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <functional>
#include <memory>

class NeuroneLayer
{
    public:
        NeuroneLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF = [] (float x) {return x;});

        Eigen::VectorXf process(Eigen::VectorXf inputs) const;

    public:
        friend std::ostream& operator<<(std::ostream& flux, NeuroneLayer nl);

    private:
        Eigen::MatrixXf                 mPoids;
        std::function<float(float)>     mActivationFun;
};

#endif // NEURONELAYER_HPP
