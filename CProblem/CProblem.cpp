//
// Created by agabe on 04.01.2023.
//

#include "CProblem.h"

CKnapsackProblem::CKnapsackProblem() {
    knapsackCapacity = 0.0;
    pcItems = nullptr;
};

int CKnapsackProblem::iGetISize() {
    return pcItems->iGetItemsNumber();
}

double CKnapsackProblem::dCalculateAdaptation(int *piGenotype) {
    double dAdaptation = 0;
    double dCurrentWeight = 0;
    for (int i = 0; i < iGetISize(); i++) {
        dCurrentWeight += pcItems->iGetItemWeightIndex(i) * piGenotype[i];

        if (dCurrentWeight > knapsackCapacity) {
            return 0;
        }
        dAdaptation += ((double) piGenotype[i]) * pcItems->iGetItemValueIndex(i);
    }
    return dAdaptation;
}

CKnapsackProblem::~CKnapsackProblem() {
    delete pcItems;
}

bool bReadIntFromFile(std::ifstream *fin, int *piLoadVal) {
    std::string sLine;

    if (fin->peek() == EOF) {
        return false;
    }
    std::getline(*fin, sLine);
    *(piLoadVal) = std::stoi(sLine);
    if (*(piLoadVal) <= 0) {
        return false;
    }
    return true;
}

bool bReadDoubleFromFile(std::ifstream *fin, double *piLoadVal) {
    std::string sLine;

    if (fin->peek() == EOF) {
        return false;
    }
    std::getline(*fin, sLine);
    *(piLoadVal) = std::stod(sLine);
    if (*(piLoadVal) <= 0) {
        return false;
    }
    return true;
}

bool bReadTableFromFile(std::ifstream *fin, double *dColumn, int iSize, double dBound) {
    std::string sLine;

    for (int i = 0; i < iSize; i++) {
        if ((*fin).peek() == EOF) {
            return false;
        }
        std::getline((*fin), sLine);
        dColumn[i] = std::stod(sLine);
        if (dColumn[i] < 0 && dColumn[i] > dBound) {
            return false;
        }
    }
    return true;
}

bool CKnapsackProblem::bReadInstanceFromFile(std::string fileName) {
    std::ifstream *fin = nullptr;

    double *pdTmpWeights = nullptr;
    double *pdTmpValues = nullptr;

    double *piLoadDouble = nullptr;
    int *piLoadInt = nullptr;

    try {
        fin = new std::ifstream;
        //opening file
        (*fin).open(fileName);

        if (!(*fin)) {
            (*fin).close();
            delete fin;
            return false;
        }

        //loading capacity
        piLoadDouble = new double;
        if (!bReadDoubleFromFile(fin, piLoadDouble)) {
            delete piLoadDouble;
            (*fin).close();
            delete fin;
            return false;
        }
        double dCapacity = *(piLoadDouble);

        //loading items number
        piLoadInt = new int;
        if (!bReadIntFromFile(fin, piLoadInt)) {
            delete piLoadDouble;
            delete piLoadInt;
            (*fin).close();
            delete fin;
            return false;
        }
        int iItemsNumber = *(piLoadInt);

        //loading weights number
        if (!bReadIntFromFile(fin, piLoadInt)) {
            delete piLoadDouble;
            delete piLoadInt;
            (*fin).close();
            delete fin;
            return false;
        }
        int iWeightsNumber = *(piLoadInt);

        //loading weights table
        pdTmpWeights = new double[iWeightsNumber];
        if (!bReadTableFromFile(fin, pdTmpWeights, iWeightsNumber, (double) dCapacity)) {
            delete pdTmpWeights;
            delete piLoadDouble;
            delete piLoadInt;
            (*fin).close();
            delete fin;
            return false;
        }

        //loading values number
        if (!bReadIntFromFile(fin, piLoadInt)) {
            delete piLoadInt;
            delete pdTmpWeights;
            delete piLoadDouble;
            (*fin).close();
            delete fin;
            return false;
        }
        int iValuesNumber = *(piLoadInt);


        //loading values table
        pdTmpValues = new double[iValuesNumber];
        if (!bReadTableFromFile(fin, pdTmpValues, iValuesNumber, dCapacity)) {
            delete pdTmpWeights;
            delete pdTmpValues;
            delete piLoadDouble;
            delete piLoadInt;
            (*fin).close();
            delete fin;
            return false;
        }
        //creating pcItem
        knapsackCapacity = dCapacity;
        pcItems = new CItems(iItemsNumber, pdTmpWeights, pdTmpValues);
    } catch (...) {
        if (piLoadInt != nullptr) {
            delete piLoadInt;
        }
        if (piLoadDouble != nullptr) {
            delete piLoadDouble;
        }
        if (pdTmpWeights != nullptr) {
            delete pdTmpWeights;
        }
        if (pdTmpValues != nullptr) {
            delete pdTmpValues;
        }
        (*fin).close();
        if (fin != nullptr) {
            delete fin;
        }
        return false;
    }
    delete piLoadInt;
    delete piLoadDouble;
    (*fin).close();
    delete fin;
    return true;
}

