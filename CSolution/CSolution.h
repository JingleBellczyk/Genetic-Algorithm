//
// Created by agabe on 17.01.2023.
//

#ifndef MINIPROJEKTTEP_CSOLUTION_H
#define MINIPROJEKTTEP_CSOLUTION_H


class CSolution {
private:
    double dBestAdaptation;
    int *piBestGenotype;
public:
    CSolution();

    void vSetSolution(double dBstAdp, int *piBstGen);

    double dGetBestAdaptation();

    int *dGetBestGenotype();
};

#endif //MINIPROJEKTTEP_CSOLUTION_H
