#include "headers/neuronalnetwork.hpp"

NeuronalNetwork::NeuronalNetwork()
{

}

Eigen::VectorXf NeuronalNetwork::process(Eigen::VectorXf input) const
{
    for(auto itr = begin(); itr != end(); ++itr)
        input = (*itr).process(input);

    return input;
}
