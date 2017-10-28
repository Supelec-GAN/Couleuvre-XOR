#ifndef STATSCOLLECTOR_HPP
#define STATSCOLLECTOR_HPP

#include "headers/errorcollector.hpp"

#include <vector>

namespace Stats
{

class StatsCollector
{
    public:
        StatsCollector(unsigned int nbExperiments);

        ErrorCollector& operator[](unsigned int teachIndex);

    private:
        std::vector<ErrorCollector> mErrorStats;
};

}

#endif // STATSCOLLECTOR_HPP
