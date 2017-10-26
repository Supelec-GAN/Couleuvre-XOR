#include <iostream>
#include <random>
#include <eigen3/Eigen/Dense>

#include "headers/neuronlayer.hpp"
#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"
#include "headers/teacher.hpp"
#include "headers/CSVFile.h"


using namespace std;

int main()
{
   srand(192786327);
	//seed to keep the same random results, for debug

   try 
   {
   //Initialise variables
   float step(0.001);
   unsigned int trainingSetSize(10000);
   unsigned int convergenceStudySampleSize(20);
	   unsigned int convergenceStudyPeriod(10); //used to see how convergence is doing every <convergenceStudyPeriod> training iterations
	   
   std::vector<unsigned int> sizes{ {2,2,2,1} };
   std::vector<Functions::ActivationFun> funs{ {Functions::sigmoid(3.f), Functions::sigmoid(3.f), Functions::sigmoid(3.f)} };

   std::shared_ptr<NeuralNetwork> network(new NeuralNetwork(sizes, funs));

   std::cout << "network:" << "\n" <<(*network);

   Teacher teacher(network);

   std::default_random_engine generator;
   std::uniform_real_distribution<float> distribution(-1.f,1.f);

   Eigen::VectorXf input(2);
   Eigen::VectorXf desiredOutput(1);

   csvfile csv("resultat.csv");
   csv << "nbApprentissage" << "erreur" << "nbReussite" << endrow;
	   
   for(size_t i(0); i < trainingSetSize; i++)
   {
       input(0)  = distribution(generator);
       input(1)  = distribution(generator);
	   //input generation (one ligne per input??)
	   
       desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
	   //desiredOutput (to be generalised?) : here, XOR : ^ is xor in c++
	   
	   /*std::cout << "Input no : " << i << "\n";
       std::cout << "Entrée : \n" << input.transpose() << "\n"; //transposition for display
       std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
       std::cout << "Poids : \n" << *network << "\n"; */
	   
	   teacher.backProp(input, desiredOutput, step);

	   //Convergence study :
       if ((i%convergenceStudyPeriod) == 0)
	   //every <convergenceStudyPeriod> iterations, we look at how it's doing by doing <convergenceStudySampleSize> iteration tests
       {
            unsigned int okcount(0);
            float errorMean(0);

            for(size_t j(0); j < convergenceStudySampleSize; j++)
            {
                input(0) = distribution(generator);
                input(1) = distribution(generator);
				//input generation (one ligne per input again ?)
                desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
                auto output(network->process(input));
                std::cout << "Input test no :   " << j << "\n";
				std::cout << "Entrée :          " << input.transpose() << "\n"; //transposition for display
                std::cout << "Sortie attendue : " << desiredOutput(0) << "\n";
                std::cout << "Sortie :          " << output << "\n" ;
                auto ok((output-desiredOutput).squaredNorm() < 0.5 ? 1 : 0);
                if(ok == 0)
                    std::cout << "******************* not ok **************************************\n";
                okcount += ok;
                errorMean += (output-desiredOutput).squaredNorm();
				std::cout << "\n";
            }
            csv << i << (errorMean/20) << okcount << endrow; //csv export of the convergence study results
            std::cout << "okcount = " << okcount << "\n\n";
        }
   }
   
   }
    
   catch (const std::exception& ex)
	//exception handling
   {
       std::cout << "Exception was thrown: " << ex.what() << std::endl;
   }
   return 0;
}
