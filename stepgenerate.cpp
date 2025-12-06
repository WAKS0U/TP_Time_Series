#include "stepgenerator.h"
#include "cmath"

int StepGenerator::saut(){
    return rand()%101;
}

vector<double> StepGenerator::generateTimeSeries(int size){
    vector<double> serie;
    int value=0;
    for(int i=0;i<size;i++){
        if(rand()%2==0){
            value=saut();
        }
        serie.push_back(value);
    }
    return serie;
}