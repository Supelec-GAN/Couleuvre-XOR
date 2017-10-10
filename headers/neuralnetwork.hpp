#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <vector>

#include "neuronlayer.hpp"

class NeuralNetwork : public std::vector<NeuronLayer>
{
    public:
	
	/// Constructeur permettant d'initialiser une réseau neuronal vide
	NeuralNetwork();
	
    /// Constructeur permettant d'initialiser un réseau neuronal complet
    /**
     * \param nbLayer le nombre de couches du réseau
	 * \param nbInputs ne nombre d'entrées du réseau
     * \param arrayNbNeuronsPerLayer la liste du nombre de neurone par couche (nbLayer éléments)
     * \param arrayActivationFunctionPerLayer la liste des fonctions d'activation de chaque couche (nbLayer éléments)
	 */
	NeuralNetwork(unsigned int nbLayer, unsigned int nbInputs, std::vector<unsigned int> arrayNbNeuronsPerLayer, std::vector<std::function<float(float)>> arrayActivationFunctionPerLayer);
	
	/// Constructeur permettant d'initialiser un réseau neuronal avec la fonction par défaut
	/**
	 * \param nbLayer le nombre de couches du réseau
	 * \param nbInputs ne nombre d'entrées du réseau
	 * \param arrayNbNeuronsPerLayer la liste du nombre de neurone par couche (nbLayer éléments)
	 */
	NeuralNetwork(unsigned int nbLayer, unsigned int nbInputs, std::vector<unsigned int> arrayNbNeuronsPerLayer);


    Eigen::VectorXf process(Eigen::VectorXf input) const;
    
};

#endif // NEURALNETWORK_HPP
