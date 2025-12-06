#include "timeseriesdataset.h"
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;



double calculateMean(const vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}
double calculateStdDev(const vector<double>& data, double mean) {
    if (data.size() <= 1) return 0.0;
    double sq_sum = 0.0;
    for (double val : data) {
        sq_sum += (val - mean) * (val - mean);
    }
    return sqrt(sq_sum / data.size());
}

void TimeSeriesDataSet::addTimeSeries(const vector<double>& series, int label) {
    vector<double> seriesToAdd = series;
    if (znormalize) {
        double mean = calculateMean(seriesToAdd);
        double std_dev = calculateStdDev(seriesToAdd, mean);
        if (std_dev > 1e-9) { 
            for (double &val : seriesToAdd) {
                val = (val - mean) / std_dev;
            }
        }
    }
    data.push_back(seriesToAdd);
    labels.push_back((double)label);
    numberOfSamples++;
    if (seriesToAdd.size() > maxLength) {
        maxLength = seriesToAdd.size();
    }
}


int TimeSeriesDataSet::getNumberOfSamples() const {
    return numberOfSamples;
}

vector<double> TimeSeriesDataSet::getTimeSeries(int index) const {
    if (index >= 0 && index < data.size()) {
        return data[index];
    }
    return {};
}

double TimeSeriesDataSet::getLabel(int index) const {
    if (index >= 0 && index < labels.size()) {
        return labels[index];
    }
    return -1.0; 
}