
using namespace std;
#ifndef KNN_H
#define KNN_H
#include <string>
#include <vector>
#include "timeseriesdataset.h"

class Knn{
    private:
        int k;
        string similarity_measure;
    public:
        double evaluate(TimeSeriesDataSet trainData, TimeSeriesDataSet testData, std::vector<int> ground_truth); ;
        Knn(int n,string titre):k(n),similarity_measure(titre) {}  
};
#endif