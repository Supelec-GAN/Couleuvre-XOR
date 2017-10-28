#include "headers/datacollector.hpp"

#include <algorithm>

DataCollector::DataCollector(std::string csvName, bool isErrorSet)
:csv(csvName + ".csv")
{
    if (isErrorSet)
    {
        addDataType("Numero de batch");
        addDataType("Erreur moyenne");
        addDataType("Ecart-type");
        addDataType("Intervalle de confiance 95%");
    }
}


void DataCollector::addDataType(std::string type)
{
    mDataVector.push_back(std::pair<std::string, std::vector<float>>(type, {}));
}


void DataCollector::addData(DataSet dataSet)
{
    (*this)["Numero de batch"].push_back(dataSet.getSample());
    (*this)["Erreur moyenne"].push_back(dataSet.getData().mean);
    (*this)["Ecart-type"].push_back(dataSet.getData().deviation);
    (*this)["Intervalle de confiance 95%"].push_back(dataSet.getData().confRange);
}

void DataCollector::addProcessedData(DataSet dataSet)
{
    (*this)["Numero de batch"].push_back(dataSet.getSample());
    (*this)["Erreur moyenne"].push_back(dataSet.getData().mean);
    (*this)["Ecart-type"].push_back(dataSet.getData().deviation);
    (*this)["Intervalle de confiance 95%"].push_back(dataSet.getData().confRange);
}

void DataCollector::addRawData(std::string key, DataSet dataSet)
{
    (*this)[key].insert((*this)[key].end(), dataSet.getRawData().begin(), dataSet.getRawData().end());
}

void DataCollector::exportData()
{
    std::for_each(mDataVector.begin(), mDataVector.end(), [&] (std::pair<std::string, std::vector<float>> data) {csv << data.first;});
    csv << endrow;
    int max(0);
    for (auto i = mDataVector.begin(); i != mDataVector.end(); ++i)
        if (i->second.size() > max)
            max = i->second.size();
    for (int i = 0; i < max; ++i)
    {
        std::for_each(mDataVector.begin(), mDataVector.end(), [&] (std::pair<std::string, std::vector<float>> data) {if (i < data.second.size()) csv << data.second[i];});
        csv << endrow;
    }
}


std::vector<float>& DataCollector::operator[] (std::string key)
{
    auto it(std::find_if(mDataVector.begin(), mDataVector.end(), [&] (std::pair<std::string, std::vector<float>> x) {return x.first == key;}));
    if (it == mDataVector.end())
    {
        std::cout << "Non existing value (now added) : " << key << std::endl;
        addDataType(key);
        return (*this)[key];
    }
    else
        return it->second;
}
