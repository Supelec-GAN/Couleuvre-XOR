#include <iostream>
#include <random>
#include <eigen3/Eigen/Dense>

#include "headers/neuronlayer.hpp"
#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"
#include "headers/teacher.hpp"
#include "CSVFile.h"


using namespace std;

int main()
{
   srand(192786327);
   
   try 
   {
   csvfile csv("resultat.csv"); 
    
   NeuronLayer inputLayer(2,2, Functions::sigmoid(8.f));
   NeuronLayer innerLayer(2,2, Functions::sigmoid(8.f));
   NeuronLayer outputLayer(2,1, Functions::sigmoid(8.f));

   NeuralNetwork::Ptr network(new NeuralNetwork(std::vector<NeuronLayer>({{inputLayer, innerLayer, outputLayer}})));

   Teacher teacher(network);

   std::default_random_engine generator;
   std::uniform_real_distribution<float> distribution(-1.f,1.f);

   Eigen::VectorXf input(2);
   Eigen::VectorXf desiredOutput(1);

   csv << "nbApprentissage" << "erreur" << "nbReussite" << endrow;
   for(size_t i(0); i < 10000; i++)
   {
       input(0)  = distribution(generator);
       input(1)  = distribution(generator);
       desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
       /*std::cout << "Input no : " << i << "\n";
       std::cout << "Entrée : " << input.transpose() << "\n";
       std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
       std::cout << "Poids : \n" << *network << "\n";*/
       teacher.backProp(input, desiredOutput, 0.001);

       if ((i%10) == 0)
       {
            unsigned  int okcount(0);
            float errorMean(0);

            for(size_t j(0); j < 20; j++)
            {
                input(0) = distribution(generator) >= 0 ? 1 : 0;
                input(1) = distribution(generator) >= 0 ? 1 : 0;
                desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
                auto output(network->process(input));
                std::cout << "Input test no : " << j << "\n";
                std::cout << "Entrée : " << input << "\n";
                std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
                std::cout << "Sortie : " << output << "\n";
                auto ok((output-desiredOutput).squaredNorm() < 0.5 ? 1 : 0);
                if(ok == 0)
                    std::cout << "*********************************************************\n";
                okcount += ok;
                errorMean += (output-desiredOutput).squaredNorm();
            }
            csv << i << (errorMean/20) << okcount << endrow;
            std::cout << okcount;
        }
   }
   
   }
    
   catch (const std::exception& ex) 
   {
       std::cout << "Exception was thrown: " << ex.what() << std::endl;
   }
   return 0;
}
