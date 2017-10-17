#include <iostream>
#include <random>

#include "headers/neuronlayer.hpp"
#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"
#include "headers/teacher.hpp"


using namespace std;

int main()
{
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
}
