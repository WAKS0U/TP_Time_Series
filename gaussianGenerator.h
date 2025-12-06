#include "timeseries.h"
using namespace std;
#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_h

class GaussianGenerator:public TimeSeriesGenerator{
    private:
        double mean;
        double stdi;
        double boxMuller();
    public:
            vector<double> generateTimeSeries(int) override;
            GaussianGenerator();
            GaussianGenerator(int seed,double mean,double stdi);
            double getMean();
            double getStdi();
            
};

#endif