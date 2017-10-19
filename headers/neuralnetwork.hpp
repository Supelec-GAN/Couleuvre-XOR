#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include <list>
#include <vector>

#include "neuronlayer.hpp"
#include "headers/functions.hpp"

class NeuralNetwork : public std::list<NeuronLayer>
{
    public:
        using Ptr = std::shared_ptr<NeuralNetwork>;

    public:
	
        /// Constructeur permettant d'initialiser une réseau neuronal vide
        NeuralNetwork();
	
        /// Constructeur permettant d'initialiser un réseau neuronal complet
        NeuralNetwork(std::vector<unsigned int> layerSizes, std::vector<Functions::ActivationFun> activationFuns);
	
        /// Constructeur permettant d'initialiser un réseau neuronal avec la fonction par défaut
         NeuralNetwork(std::vector<unsigned int> layerSizes);

        /// Constructeur permettant d'initialiser le réseau neuronal avec un conteneur de neuronLayer
        /**
         *  \param Container un conteneur (vector, list...) de NeuronLayer
         *  \param layerList la liste des couches de neurones
         */
        template <typename Container>
        NeuralNetwork(Container layerList);

        Eigen::VectorXf process(Eigen::VectorXf input);


    public:
        /// Fonction utilitaire permettant d'afficher le réseau de neurones
        /**
         * Cette fonction affiche les matrices de poids des différents layers du réseau
         */
        friend std::ostream& operator<<(std::ostream& flux, NeuralNetwork network);

};

#include "headers/neuralnetwork.inl"

#endif // NEURALNETWORK_HPP
