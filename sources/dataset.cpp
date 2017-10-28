#include "headers/dataset.hpp"

DataSet::DataSet(int sample, std::vector<float> dataVect)
:mRawData(dataVect)
,mSample(sample)
{
    processData();
}


void DataSet::addRawData(float data, bool process)
{
    mRawData.push_back(data);
    if (process)
        processData();
    else
        isProcessed = false;
}


void DataSet::addRawData(std::vector<float> dataVect)
{
    mRawData.insert(mRawData.end(), dataVect.begin(), dataVect.end());
    processData();
}


void DataSet::processData()
{
    mMedian = Statistics::processMedian(mRawData);
    mData = Statistics::processData(mRawData);
    isProcessed = true;
}

Statistics::Data DataSet::getData()
{
    if (!isProcessed)
        processData();
    return mData;
}
int DataSet::getSample()
{
    return mSample;
}

const std::vector<float>& DataSet::getRawData()
{
    return mRawData;
}
