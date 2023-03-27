//
// Created by agabe on 04.01.2023.
//
#include "CIndividual.h"

CIndividual::CIndividual() {
    piGenotype = nullptr;
    dAdaptation = 0.0;
}

CIndividual::CIndividual(int *piGen) {
    piGenotype = piGen;
}

CIndividual &CIndividual::operator=(CIndividual &&pcOther) {
    if (this == &pcOther) return *this;
    if (piGenotype != nullptr) {
        delete[] piGenotype;
    }
    piGenotype = pcOther.piGenotype;

    pcOther.piGenotype = nullptr;
    return *this;
}

CIndividual::~CIndividual() {
    if (piGenotype != nullptr) {
        delete[] piGenotype;
    }
}

double CIndividual::dGetAdaptation() {
    return dAdaptation;
}

int *CIndividual::piGetGenotype() {
    return piGenotype;
}

void CIndividual::vCountAdapatation(CProblem *pcProblem) {
    dAdaptation = pcProblem->dCalculateAdaptation(piGenotype);
}

void CIndividual::vPrintGen(int iSize) {
    for (int i = 0; i < iSize; i++) {
        std::cout << piGenotype[i] << " ";
    }
    std::cout << "\n";
}

/* different way to mutate */
/*
void CIndividual::vMutateIndividual(double dMutationProbability, int iGenotypeSize,
                                    CRandomNumberGenerator *piRandomNumberGenerator) {
    for (int i = 0; i < iGenotypeSize; i++) {
        if (piRandomNumberGenerator->generateNumberDouble(0.0, 1.0) < dMutationProbability) {
            piGenotype[i] = (piGenotype[i] + 1) % 2;
        }
    }
};
 */

void CIndividual::vMutateIndividual(double dMutationProbability, int iGenotypeSize,
                                    CRandomNumberGenerator *piRandomNumberGenerator, CIndividual* pcOther) {
    for (int i = 0; i < iGenotypeSize; i++) {
        if(piGenotype[i] != pcOther->piGenotype[i]) {
            if (piRandomNumberGenerator->generateNumberDouble(0.0, 1.0) < dMutationProbability) {
                piGenotype[i] = (piGenotype[i] + 1) % 2;
            }
        }
    }
};


void CIndividual::vCrossIndividuals(CIndividual *pcOther, CIndividual *pcChild1, CIndividual *pcChild2,
                                    double dCrossProb, int iGenotypeSize,
                                    CRandomNumberGenerator *piRandomNumberGenerator) {
    if (piRandomNumberGenerator->generateNumberDouble(0.0, 1.0) < dCrossProb) {
        int iPartitionIndeks = piRandomNumberGenerator->generateNumberInt(1, iGenotypeSize - 1); // -1

        memcpy(pcChild1->piGenotype, piGenotype, sizeof(int) * iPartitionIndeks);
        memcpy(pcChild1->piGenotype + iPartitionIndeks, pcOther->piGenotype + iPartitionIndeks,
               sizeof(int) * (iGenotypeSize - iPartitionIndeks));

        memcpy(pcChild2->piGenotype, pcOther->piGenotype, sizeof(int) * iPartitionIndeks);
        memcpy(pcChild2->piGenotype + iPartitionIndeks, piGenotype + iPartitionIndeks,
               sizeof(int) * (iGenotypeSize - iPartitionIndeks));
    } else {
        memcpy(pcChild1->piGenotype, piGenotype, sizeof(int) * iGenotypeSize);
        memcpy(pcChild2->piGenotype, pcOther->piGenotype, sizeof(int) * iGenotypeSize);
    }
}
