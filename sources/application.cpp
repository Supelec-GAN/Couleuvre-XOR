#include "headers/application.hpp"
#include "headers/dataset.hpp"

#include <math.h>

Application::Application(NeuralNetwork::Ptr network, Batch teachingBatch, Batch testingBatch)
: mNetwork(network)
, mTeacher(mNetwork)
, mTeachingBatch(teachingBatch)
, mTestingBatch(testingBatch)
, mDataCollector()
, mTestCounter(0)
{}

Application::Application(   NeuralNetwork::Ptr network,
                            std::function<Eigen::VectorXf (Eigen::VectorXf)> modelFunction,
                            std::vector<Eigen::VectorXf> teachingInputs,
                            std::vector<Eigen::VectorXf> testingInputs)
: mNetwork(network)
, mTeacher(mNetwork)
, mDataCollector()
, mTestCounter(0)
{
    // Génère le batch d'apprentissage à partir des entrées et de la fonction à modéliser
    for(size_t i{0}; i < teachingInputs.size(); ++i)
        mTeachingBatch.push_back(Sample(teachingInputs[i], modelFunction(teachingInputs[i])));
    // Génère le batch d'apprentissage à partir des entrées et de la fonction à modéliser
    for(size_t i{0}; i < testingInputs.size(); ++i)
        mTestingBatch.push_back(Sample(testingInputs[i], modelFunction(testingInputs[i])));
}

void Application::runTeach(unsigned int nbTeachings)
{
    auto samples(generateBatch(nbTeachings));

    for(auto itr = samples.begin(); itr != samples.end(); ++itr)
        mTeacher.backProp(itr->first, itr->second);
}

void Application::runTest()
{
    DataSet errorSet(mTestCounter++);

    for(auto itr = mTestingBatch.begin(); itr != mTestingBatch.end(); ++itr)
    {
        auto output{mNetwork->process(itr->first)};
        auto error{sqrt((output - itr->second).squaredNorm())};

        errorSet.addRawData(error);
    }

    errorSet.processData();
    mDataCollector.addData(errorSet);
}

void Application::totalRun(unsigned int nbLoops, unsigned int nbTeachingsPerLoop)
{

    for(unsigned int i{0}; i < nbLoops; i++)
    {
        runTeach(nbTeachingsPerLoop);
        runTest();
    }

    mDataCollector.exportData();
}

Application::Batch Application::generateBatch(unsigned int batchSize) const
{
    std::uniform_int_distribution<> distribution(0, batchSize-1);
    std::mt19937 randomEngine((std::random_device())());

    Batch batch;

    for(unsigned int i{0}; i < batchSize; ++i)
        batch.push_back(mTeachingBatch[distribution(randomEngine)]);

    return batch;
}
