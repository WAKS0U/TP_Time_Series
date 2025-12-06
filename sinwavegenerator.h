#include "timeseries.h"
#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

class SinWaveGenerator:public TimeSeriesGenerator{
    private:
        double A;
        double freq;
        double phase;
    public:
        vector<double> generateTimeSeries(int) override;
        SinWaveGenerator();    
};

#endif