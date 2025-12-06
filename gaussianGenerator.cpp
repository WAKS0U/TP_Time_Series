#include "gaussianGenerator.h"
#include "random"
#include "cmath"
double GaussianGenerator::boxMuller(){
    double U1=(rand()+1.0)/(RAND_MAX+2.0);
    double U2=(rand()+1.0)/(RAND_MAX+2.0);
    double Z=sqrt(-2*log(U1)*cos(2*M_PI*U2));
    return Z*stdi+mean;
}

double GaussianGenerator::getMean(){
    return mean;
}

double GaussianGenerator::getStdi(){
    return stdi;
}

vector<double> GaussianGenerator::generateTimeSeries(int size){
    vector<double> serie;
    for(int i=0;i<size;i++){
        serie.push_back(boxMuller());
    }
    return serie;
}

GaussianGenerator::GaussianGenerator() : mean(0.0), stdi(1.0) {
}

