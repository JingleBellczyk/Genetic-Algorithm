//
// Created by agabe on 17.01.2023.
//

#include "CSolution.h"

CSolution::CSolution() {
    dBestAdaptation = 0;
    piBestGenotype = nullptr;
}

void CSolution::vSetSolution(double dBstAdp, int *piBstGen) {
    dBestAdaptation = dBstAdp;
    piBestGenotype = piBstGen;
}

double CSolution::dGetBestAdaptation() {
    return dBestAdaptation;
}

int *CSolution::dGetBestGenotype() {
    return piBestGenotype;
}