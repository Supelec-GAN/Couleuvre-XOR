#include <iostream>

#include "headers/neuronlayer.hpp"
#include "headers/neuralnetwork.hpp"


using namespace std;

int main()
{
    // On créé 3 couche de neurones différentes
    NeuronLayer n1(5, 5);
    NeuronLayer n2(5 ,4);
    NeuronLayer n3(4,3);

    // On créé le réseau correspondant à ces 3 couches à la suite
    NeuralNetwork network;
    network.push_back(n1);
    network.push_back(n2);
    network.push_back(n3);

    // On créé un vecteur d'entrée de dimension 5x1 valant (1, 2, 3, 4, 5)
    Eigen::VectorXf input(5);
    input << 1,2,3,4,5;
    
    
    // On affiche la sortie du réseau de neurones
    cout << network.process(input) << endl << endl;
	
	// Exemple 2
	std::vector<unsigned int> arrayNbNeuronsPerLayer = {5, 4, 3};
	NeuralNetwork neuralNetwork(3, 5, arrayNbNeuronsPerLayer);
	
	cout << neuralNetwork.process(input) << endl;


    return 0;
}
