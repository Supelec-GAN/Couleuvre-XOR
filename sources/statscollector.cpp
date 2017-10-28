#include "headers/statscollector.hpp"

#include <stdexcept>

namespace Stats
{

StatsCollector::StatsCollector(unsigned int nbExperiments, const std::string& CSVFileName)
: mErrorStats()
, mCSV(CSVFileName + ".csv")
{}

ErrorCollector& StatsCollector::operator[](unsigned int teachIndex)
{
    if(teachIndex >= mErrorStats.size())
        throw std::logic_error("StatsCollector::operator[] - Erreur : Indice d'apprentissage trop grand");

    return  mErrorStats[teachIndex];
}

}
