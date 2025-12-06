
#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H
#include <vector>
using namespace std;
class TimeSeriesDataSet{
    private:
        bool znormalize;
        bool IsTrain;
        vector<vector<double>> data;

        vector<double> labels;
        int maxLength;
        int numberOfSamples;
    public:
        TimeSeriesDataSet(bool bool1, bool bool2) 
            : znormalize(bool1), IsTrain(bool2), maxLength(0), numberOfSamples(0) {}
        void addTimeSeries(const vector<double>&,int); 
        int getNumberOfSamples() const;
        vector<double> getTimeSeries(int index) const;
        double getLabel(int index) const;   
};

#endif