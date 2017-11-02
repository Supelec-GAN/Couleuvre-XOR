#include "headers/utility.hpp"

#include <numeric>
#include <algorithm>
#include <math.h>


Statistics::Data Statistics::processData(const std::vector<float> &dataVect)
{
    Data data;
    data.mean = std::accumulate(dataVect.begin(), dataVect.end(), 0.f)/(static_cast<float>(dataVect.size()));
    float deviation(0);

    std::for_each(dataVect.begin(), dataVect.end(), [&] (float x) {deviation += pow(x, 2);});
    data.deviation = sqrtf(deviation/static_cast<float>(dataVect.size()) - powf(data.mean, 2));
    data.confRange = 2*data.deviation/(sqrt(static_cast<float>(dataVect.size())));
    return data;
}


float Statistics::processMedian(std::vector<float> dataVect)
{
    std::nth_element(dataVect.begin(), dataVect.begin() + dataVect.size()/2, dataVect.end());
    return dataVect[dataVect.size()/2];
}
