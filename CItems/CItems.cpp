//
// Created by agabe on 17.01.2023.
//

#include "CItems.h"

CItems::CItems(int iItmNum, double *pdItmWei, double *pdItmVal) {
    iItemsNumber = iItmNum;
    pdItemsWeights = pdItmWei;
    pdItemsValues = pdItmVal;
}

CItems::~CItems() {
    delete pdItemsValues;
    delete pdItemsWeights;
}

int CItems::iGetItemsNumber() {
    return iItemsNumber;
}

double CItems::iGetItemWeightIndex(int iIndex) {
    return pdItemsWeights[iIndex];
}

double CItems::iGetItemValueIndex(int iIndex) {
    return pdItemsValues[iIndex];
}