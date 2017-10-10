#ifndef NEURONALNETWORK_HPP
#define NEURONALNETWORK_HPP

#include <list>

#include "neuronlayer.hpp"

class NeuronalNetwork : public std::list<NeuronLayer>
{
    public:
        NeuronalNetwork();

        Eigen::VectorXf process(Eigen::VectorXf input) const;
};

#endif // NEURONALNETWORK_HPP
