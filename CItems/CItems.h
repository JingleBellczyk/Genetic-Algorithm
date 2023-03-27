//
// Created by agabe on 17.01.2023.
//

#ifndef MINIPROJEKTTEP_CITEMS_H
#define MINIPROJEKTTEP_CITEMS_H


class CItems {
private:
    int iItemsNumber;
    double *pdItemsWeights;
    double *pdItemsValues;
public:
    CItems(int iItmNum, double *pdItmWei, double *pdItmVal);

    ~CItems();

    int iGetItemsNumber();

    double iGetItemWeightIndex(int iIndex);

    double iGetItemValueIndex(int iIndex);
};


#endif //MINIPROJEKTTEP_CITEMS_H
