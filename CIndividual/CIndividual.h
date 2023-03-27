//
// Created by agabe on 04.01.2023.
//
#include <random>
#include "../CProblem/CProblem.h"

#ifndef MINIPROJEKTTEP_CINDIVIDUAL_H
#define MINIPROJEKTTEP_CINDIVIDUAL_H

#include "../CRandomNumberGenerator/CRandomNumberGenerator.h"

class CIndividual {
private:
    int *piGenotype;
    double dAdaptation;
public:
    CIndividual();

    CIndividual(int *piGen);

    CIndividual &operator=(CIndividual &&pcOther);

    ~CIndividual();

    double dGetAdaptation();

    int *piGetGenotype();

    void vCountAdapatation(CProblem *pcProblem);

    void vPrintGen(int iSize);

    //void vMutateIndividual(double dMutationProbability, int iGenotypeSize, CRandomNumberGenerator *piRandomNumberGenerator);

    void vMutateIndividual(double dMutationProbability, int iGenotypeSize, CRandomNumberGenerator *piRandomNumberGenerator, CIndividual* pcOther);

    void vCrossIndividuals(CIndividual *pcOther, CIndividual *pcChild1, CIndividual *pcChild2,
                           double dCrossProb, int iGenotypeSize, CRandomNumberGenerator *piRandomNumberGenerator);
};

#endif //MINIPROJEKTTEP_CINDIVIDUAL_H
