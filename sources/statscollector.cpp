#include "headers/statscollector.hpp"

#include <stdexcept>

Stats::StatsCollector::StatsCollector(unsigned int nbExperiments, const std::string& CSVFileName)
: mErrorStats(nbExperiments)
, mCSV(CSVFileName + ".csv")
{}

Stats::ErrorCollector& Stats::StatsCollector::operator[](unsigned int teachIndex)
{
    if(teachIndex >= mErrorStats.size())
        throw std::logic_error("StatsCollector::operator[] - Erreur : Indice d'apprentissage trop grand");

    return  mErrorStats[teachIndex];
}

void Stats::StatsCollector::exportData(bool mustProcessData)
{
    if(!mustProcessData)
        throw std::logic_error("Not implemented yet");

    mCSV << "Teach index" << "Mean" << "Deviation" << "Confidence Range" << endrow;
    for (unsigned int index{0}; index < mErrorStats.size(); ++index)
    {
        ErrorCollector::StatisticData data{mErrorStats[index].processData()};

        mCSV << index << data.mean << data.deviation << data.confidenceRange << endrow;
    }
}
