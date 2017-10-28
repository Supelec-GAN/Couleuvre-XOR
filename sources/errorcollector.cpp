#include "headers/errorcollector.hpp"

#include <numeric>
#include <algorithm>
#include <math.h>

Stats::ErrorCollector::ErrorCollector()
: mErrors()
{

}

Stats::ErrorCollector::StatisticData Stats::ErrorCollector::processData() const
{
    StatisticData data;

    data.mean = std::accumulate(mErrors.begin(), mErrors.end(), 0.f)/(static_cast<float>(mErrors.size()));

    float deviation(0);
    std::for_each(mErrors.begin(), mErrors.end(), [&] (float x) {deviation += x*x;});
    data.deviation = sqrt(deviation/static_cast<float>(mErrors.size()) - pow(data.mean, 2));

    data.confidenceRange = 2*data.deviation/(sqrt(static_cast<float>(mErrors.size())));

    return data;
}

void Stats::ErrorCollector::addResult(float result)
{
    mErrors.push_back(result);
}
