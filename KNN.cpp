#include "KNN.h"
#include "timeseriesdataset.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

double euclidean_dist(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    size_t n = min(a.size(), b.size());
    for (size_t i = 0; i < n; i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

double dtw_dist(const vector<double>& a, const vector<double>& b) {
    return euclidean_dist(a, b); 
}


double Knn::evaluate(TimeSeriesDataSet trainData, TimeSeriesDataSet testData, std::vector<int> ground_truth) {
    int correct_predictions = 0;
    int test_size = testData.getNumberOfSamples(); 
    for (int i = 0; i < test_size; i++) {
        vector<double> test_sample = testData.getTimeSeries(i); 
        vector<pair<double, int>> distances;

        for (int j = 0; j < trainData.getNumberOfSamples(); j++) {
            vector<double> train_sample = trainData.getTimeSeries(j);
            int train_label = trainData.getLabel(j); 

            double dist = 0.0;
            if (similarity_measure == "dtw") {
                dist = dtw_dist(test_sample, train_sample);
            } else {
                dist = euclidean_dist(test_sample, train_sample);
            }

            distances.push_back({dist, train_label});
        }
        sort(distances.begin(), distances.end());

        map<int, int> class_counts;
        for (int n = 0; n < k && n < distances.size(); n++) {
            int label = distances[n].second;
            class_counts[label]++;
        }
        int predicted_label = -1;
        int max_votes = -1;
        
        for (auto const& [label, count] : class_counts) {
            if (count > max_votes) {
                max_votes = count;
                predicted_label = label;
            }
        }

        if (predicted_label == ground_truth[i]) {
            correct_predictions++;
        }
    }
    if (test_size == 0) return 0.0;
    return (double)correct_predictions / test_size;
}