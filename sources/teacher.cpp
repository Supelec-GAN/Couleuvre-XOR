#include <eigen3/Eigen/Dense>

#include "headers/teacher.hpp"


Teacher::Teacher(NeuralNetwork::Ptr network)
: mNetwork(std::move(network))
, mErrorFun(Functions::l2Norm())
{}

Teacher::Teacher(NeuralNetwork* network)
: mNetwork(network)
, mErrorFun(Functions::l2Norm())
{}

void Teacher::onlineBackProp(Eigen::VectorXf input, Eigen::VectorXf desiredOutput, float step, float dx)
{
	Eigen::VectorXf xnPartialDerivative = errorVector(mNetwork->process(input), desiredOutput, dx);
	
	onlinePropError(xnPartialDerivative, step);
}

void Teacher::onlinePropError(Eigen::VectorXf xnPartialDerivative, float step)
{
	for(auto itr = mNetwork->rbegin(); itr != mNetwork->rend(); ++itr)
	{
		xnPartialDerivative = itr->layerBackProp(xnPartialDerivative, step);
		itr->updateLayerWeights();
	}
}

void Teacher::miniBatchBackProp(Eigen::VectorXf input,Eigen::VectorXf desiredOutput, float step, float dx)
{
	Eigen::VectorXf xnPartialDerivative = errorVector(mNetwork->process(input), desiredOutput, dx);
	for(auto itr = mNetwork->rbegin(); itr != mNetwork->rend(); ++itr)
	{
		xnPartialDerivative = itr->layerBackProp(xnPartialDerivative, step);
	}
}

void Teacher::updateNetworkWeights()
{
	for(auto itr = mNetwork->rbegin(); itr != mNetwork->rend(); ++itr)
		itr->updateLayerWeights();
}
								 

Eigen::VectorXf Teacher::errorVector(Eigen::VectorXf output, Eigen::VectorXf desiredOutput, float dx)
{
	Eigen::VectorXf errorVect = Eigen::MatrixXf::Zero(output.size(), 1);
	
	for(unsigned int i(0); i < output.size(); ++i)
	{
		Eigen::VectorXf deltaX(Eigen::MatrixXf::Zero(output.size(), 1));
		deltaX(i) = dx;
		errorVect(i) = (mErrorFun(output + deltaX, desiredOutput) - mErrorFun(output, desiredOutput))/dx;
	}
	
	
	return errorVect;
}
