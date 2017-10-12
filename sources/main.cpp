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
    vector<NeuronLayer> n;
    n.push_back(n1);
    n.push_back(n2);
    n.push_back(n3);

    NeuralNetwork network(n);

    // On créé un vecteur d'entrée de dimension 5x1 valant (1, 2, 3, 4, 5)
    Eigen::VectorXf input(5);
    input << 1,2,3,4,5;
    
    
    // On affiche la sortie du réseau de neurones
    cout << network.process(input) << endl << endl;
    return 0;
}
