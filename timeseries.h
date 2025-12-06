#include <vector>
using namespace std;
#ifndef TIMESERIES_H
#define TIMESERIES_H

class TimeSeriesGenerator{
    private:
        int seed;
    public:
        virtual vector<double> generateTimeSeries(int)=0;
        static void printTimeSeries(const vector<double>);
        TimeSeriesGenerator():seed(0) {}
        TimeSeriesGenerator(int s):seed(s) {}   
        double euclidean_distance(const vector<double>,const vector<double>);
        double dtw(const vector<double>,const vector<double>,int,int);
};

#endif

