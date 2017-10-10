#include "headers/neuronalnetwork.hpp"

NeuronalNetwork::NeuronalNetwork(){}


NeuronalNetwork::NeuronalNetwork(unsigned int nbLayer, unsigned int nbInputs, std::vector<unsigned int> arrayNbNeuronsPerLayer, std::vector<std::function<float(float)>> arrayActivationFunctionPerLayer)
{
	this->push_back(NeuronLayer(nbInputs,
								arrayNbNeuronsPerLayer[0],
								arrayActivationFunctionPerLayer[0]
								)) ;
	
	for(unsigned int i=0; i < nbLayer - 1; ++i)
	{
		this->push_back(NeuronLayer(arrayNbNeuronsPerLayer[i],
									arrayNbNeuronsPerLayer[i+1],
									arrayActivationFunctionPerLayer[i+1]
									));
	}
}

NeuronalNetwork::NeuronalNetwork(unsigned int nbLayer, unsigned int nbInputs, std::vector<unsigned int> arrayNbNeuronsPerLayer)
{
	this->push_back(NeuronLayer(nbInputs,
								arrayNbNeuronsPerLayer[0]
								)) ;
	
	for(unsigned int i=0; i < nbLayer - 1; ++i)
	{
		this->push_back(NeuronLayer(arrayNbNeuronsPerLayer[i],
									arrayNbNeuronsPerLayer[i+1]
									));
	}
}


Eigen::VectorXf NeuronalNetwork::process(Eigen::VectorXf input) const
{
	for(auto itr = begin(); itr != end(); ++itr)
		input = (*itr).process(input);
	
	return input;
}

