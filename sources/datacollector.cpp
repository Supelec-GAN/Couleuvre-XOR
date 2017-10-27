#include "headers/datacollector.hpp"

#include <algorithm>

DataCollector::DataCollector(std::string testName)
:csv(testName + ".csv")
{
    csv << "Nombre d'apprentissages" << "Erreur moyenne" << "Ecart-type" << "Intervalle de confiance 95%" << endrow;
}

void DataCollector::addData(DataSet dataSet)
{
    mDataVector.push_back(std::pair<int,Statistics::Data>(dataSet.getSample(), dataSet.getData()));
}

void DataCollector::exportData()
{
    std::for_each(mDataVector.begin(), mDataVector.end(), [&] (std::pair<int, Statistics::Data> data) {csv << data.first << data.second.mean << data.second.deviation << data.second.confRange << endrow;});
}
