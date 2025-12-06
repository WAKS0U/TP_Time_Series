#include "timeseries.h"
using namespace std;
#include <iostream>
#include <math.h>
#include <tgmath.h> 
void TimeSeriesGenerator::printTimeSeries(const std::vector<double> ts) {
    for (const auto& value : ts) {
        cout << value << " ";
    }
    cout << endl;
}

double TimeSeriesGenerator::euclidean_distance(const vector<double> s1,const vector<double> s2){
    double sum = 0;
    size_t n = min(s1.size(), s2.size()); 
    
    for(size_t i = 0; i < n; i++){
        sum += pow(s1[i] - s2[i], 2);
    }
    return sqrt(sum);
}

double TimeSeriesGenerator::dtw(const vector<double> s1,const vector<double> s2,int len1,int len2){
    vector<vector<double>> matrix(len1 + 1, vector<double>(len2 + 1, 0.0));

    matrix[0][0]=0;
    for (int i = 1; i < len1; i++)
        matrix[i][0]=INFINITY;
    for (int i = 1; i < len1; i++)
        matrix[0][i]=INFINITY;
    for (int i = 1; i < len1; i++){
        for (int j = 1; j < len1; j++){
            double d=pow(s1[i-1] - s2[j-1], 2);
            double min=fmin(matrix[i][j-1],matrix[i-1][j]);
            matrix[i][j]=d+fmin(min,matrix[i-1][j-1]);
        }
    }    
     return sqrt(matrix[len1][len2]);         
}