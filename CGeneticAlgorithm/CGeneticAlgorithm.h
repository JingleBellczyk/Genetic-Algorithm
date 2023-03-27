//
// Created by agabe on 04.01.2023.
//

#ifndef MINIPROJEKTTEP_CGENETICALGORITHM_H
#define MINIPROJEKTTEP_CGENETICALGORITHM_H

#include "../CIndividual/CIndividual.h"
#include "../CSolution/CSolution.h"

class CGeneticAlgorithm {
private:
    CProblem *pcProblem;

    double dCrossingProbability;
    double dMutationProbability;
    int iIterationNumber;
    int iCurrentIterationNumber;

    CRandomNumberGenerator *pcRandomNumberGenerator;

    CIndividual *pcOddPopulation;
    CIndividual *pcEvenPopulation;
    CIndividual *pcCurrentPopulation;
    CIndividual *pcNotCurrentPopulation;

    int iPopulationSize;

    CSolution *pcSolution;
public:
    CGeneticAlgorithm(CProblem *pcProblem, int iPopulationSize, double dCrossingProbability,
                      double dMutationProbability, int iIterationNumber,
                      CRandomNumberGenerator *randomNumberGenerator);

    ~CGeneticAlgorithm();

    CSolution *piGetBestSolution();

    void vStartGeneticAlgorithm();

    void vRunGenerations();

    void vFindBestSolution();

    void vUpdatePopulations();

    void vCalculateAdaptations();

    CIndividual *piChooseRandomInd();

    void crossPopulation();

    void vMutatePopulation();

    void vGenerateRandomPopulation();

    int *piGenerateGenotype();
};

#endif //MINIPROJEKTTEP_CGENETICALGORITHM_H
