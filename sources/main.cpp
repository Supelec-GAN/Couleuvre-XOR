#include <iostream>
#include <random>
#include <eigen3/Eigen/Dense>

#include "headers/neuronlayer.hpp"
#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"
#include "headers/teacher.hpp"


using namespace std;

int main()
{
   NeuronLayer inputLayer(2,3, Functions::sigmoid(10.f));
   NeuronLayer innerLayer(3,3, Functions::sigmoid(10.f));
   NeuronLayer outputLayer(3,1, Functions::sigmoid(10.f));

   NeuralNetwork::Ptr network(new NeuralNetwork(std::vector<NeuronLayer>({{inputLayer, innerLayer, outputLayer}})));

   Teacher teacher(network);

   std::default_random_engine generator;
   std::normal_distribution<float> distribution(0.f,1.f);

   Eigen::VectorXf input(2);
   Eigen::VectorXf desiredOutput(1);

   for(size_t i(0); i < 100000; i++)
   {
       input(0)  = distribution(generator);
       input(1)  = distribution(generator);
       desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
       /*std::cout << "Input no : " << i << "\n";
       std::cout << "Entrée : " << input.transpose() << "\n";
       std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
       std::cout << "Poids : \n" << *network << "\n";*/
       teacher.backProp(input, desiredOutput, 0.01);
   }

   unsigned int okcount(0);

   for(size_t i(0); i < 1000; i++)
   {
       input(0) = distribution(generator) >= 0 ? 1 : 0;
       input(1) = distribution(generator) >= 0 ? 1 : 0;
       desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
       auto output(network->process(input));
       std::cout << "Input test no : " << i << "\n";
       std::cout << "Entrée : " << input << "\n";
       std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
       std::cout << "Sortie : " << output << "\n";
       auto ok((output-desiredOutput).squaredNorm() < 0.5 ? 1 : 0);
       if(ok == 0)
           std::cout << "*********************************************************\n";
       okcount += ok;
   }

   std::cout << okcount;

   return 0;
}
