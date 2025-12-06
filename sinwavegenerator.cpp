#include "sinwavegenerator.h"
#include "cmath"
vector<double> SinWaveGenerator::generateTimeSeries(int size){
    vector<double> serie;
    for(int i=0;i<size;i++){
        serie.push_back(A*sin(freq*i+phase));
    }
    return serie;
}

SinWaveGenerator::SinWaveGenerator() : A(1.0), freq(0.5), phase(0.0) {
}