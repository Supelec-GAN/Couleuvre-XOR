#include <iostream>

#include "headers/neuronlayer.hpp"
#include "headers/neuralnetwork.hpp"


using namespace std;

int main()
{
<<<<<<< HEAD
   NeuronLayer inputLayer(2,2, Functions::sigmoid(10.f));
   NeuronLayer outputLayer(2,1, Functions::sigmoid(10.f));

   NeuralNetwork::Ptr network(new NeuralNetwork(std::vector<NeuronLayer>({{inputLayer, outputLayer}})));

   Teacher teacher(network);

   std::default_random_engine generator;
   std::normal_distribution<float> distribution(0.f,1.f);

   Eigen::VectorXf input(2);
   Eigen::VectorXf desiredOutput(1);

   for(size_t i(0); i < 1000; i++)
   {
       input(0)  = distribution(generator);
       input(1)  = distribution(generator);
       desiredOutput(0) = (input(0) >= 0 && input(1) >= 0) ? 1 : 0;
       std::cout << "Input no : " << i << "\n";
       std::cout << "Entrée : " << input.transpose() << "\n";
       std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
       std::cout << "Poids : " << *(network->begin()) << "\n";
       teacher.backProp(input, desiredOutput);
   }

   for(size_t i(0); i < 100; i++)
   {
       input(0) = distribution(generator);
       input(1) = distribution(generator);
       desiredOutput(0) = (input(0) >= 0 && input(1) >= 0) ? 1 : 0;
       std::cout << "Input test no : " << i << "\n";
       std::cout << "Entrée : " << input << "\n";
       std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
       std::cout << "Sortie : " << network->process(input) << "\n";
   }

   return 0;
=======
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
>>>>>>> parent of b12e33e... Essai d'utilisation d'un réseau de neurones en 1D -> c'est une réussite
}
