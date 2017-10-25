#include <iostream>
#include <random>
#include <eigen3/Eigen/Dense>
#include <time.h>

#include "headers/neuronlayer.hpp"
#include "headers/neuralnetwork.hpp"
#include "headers/functions.hpp"
#include "headers/teacher.hpp"
#include "headers/CSVFile.h"
#include "headers/dataset.hpp"
#include "headers/datacollector.hpp"


using namespace std;


int foo()
{
   unsigned  int ok(0);

   try
   {
   DataCollector dataCollector("resultat");

   std::vector<unsigned int> sizes{ {2,2,2,1} };
   std::vector<Functions::ActivationFun> funs{ {Functions::sigmoid(3.f), Functions::sigmoid(3.f), Functions::sigmoid(3.f)} };

   std::shared_ptr<NeuralNetwork> network(new NeuralNetwork(sizes, funs));

   Teacher teacher(network);

   std::default_random_engine generator;
   std::uniform_real_distribution<float> distribution(-1.f,1.f);

   Eigen::VectorXf input(2);
   Eigen::VectorXf desiredOutput(1);


   for(size_t i(0); i < 10000; i++)
   {
       input(0)  = distribution(generator);
       input(1)  = distribution(generator);
       desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
       teacher.backProp(input, desiredOutput, 0.1);

       if ((i%9999) == 0)
       {
            int okcount(0);
            float error(0);
            DataSet dataSet(i);
            for(size_t j(0); j < 1000; j++)
            {
                input(0) = distribution(generator);
                input(1) = distribution(generator);
                desiredOutput(0) = ((input(0) >= 0) ^ (input(1) >= 0)) ? 1 : 0;
                auto output(network->process(input));
                auto ok(sqrt((output-desiredOutput).squaredNorm()) < 0.5 ? 1 : 0);
                okcount+=ok;
                error = sqrt((output-desiredOutput).squaredNorm());
                dataSet.addRawData(error, false);
            }
            std::cout << okcount << endl;
            if (okcount > 750)
                ok = 1;
            dataSet.processData();
            dataCollector.addData(dataSet);
        }
   }
   dataCollector.exportData();
   }

   catch (const std::exception& ex)
   {
       std::cout << "Exception was thrown: " << ex.what() << std::endl;
   }
   return ok;
}

int main()
{
    srand(time(0));

    int ok(0);
    int okcount(0);
    for (int i=0; i < 100; i++)
        ok += foo();
    std::cout << ok << std::endl;
    return 0;
}

