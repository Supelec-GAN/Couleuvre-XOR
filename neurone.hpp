#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <functional>
#include <memory>

class Neurone
{
    public:
        using Ptr = std::unique_ptr<Neurone>;

    public:
                Neurone(int inputSize);

        float process(Eigen::VectorXf input) const;

        friend std::ostream& operator<<(std::ostream& flux, Neurone n);

    private:
        Eigen::VectorXf mPoids;
        std::function<float(float)> mActivation;
};

#endif // NEURONE_HPP
