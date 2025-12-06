#include "timeseries.h"
#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

class StepGenerator:public TimeSeriesGenerator{
    public:
        vector<double> generateTimeSeries(int) override;
    private:
        int saut();
};
#endif