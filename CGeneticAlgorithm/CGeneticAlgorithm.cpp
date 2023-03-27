//
// Created by agabe on 04.01.2023.
//
#include "CGeneticAlgorithm.h"

CGeneticAlgorithm::CGeneticAlgorithm(CProblem *pcProblem, int iPopulationSize, double dCrossingProbability,
                                     double dMutationProbability, int iIterationNumber,
                                     CRandomNumberGenerator *randomNumberGenerator) {
    iCurrentIterationNumber = 0;
    this->pcProblem = pcProblem;

    this->iPopulationSize = iPopulationSize;
    if (iPopulationSize % 2 == 1) {
        iPopulationSize++;
    }

    this->dCrossingProbability = dCrossingProbability;
    this->dMutationProbability = dMutationProbability;
    this->iIterationNumber = iIterationNumber;

    pcOddPopulation = new CIndividual[iPopulationSize];
    pcEvenPopulation = new CIndividual[iPopulationSize];

    pcCurrentPopulation = pcEvenPopulation;
    pcNotCurrentPopulation = pcOddPopulation;

    this->pcRandomNumberGenerator = randomNumberGenerator;
    pcSolution = new CSolution;
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    delete pcSolution;
    delete[] pcOddPopulation;
    delete[] pcEvenPopulation;
}

CSolution *CGeneticAlgorithm::piGetBestSolution() {
    return pcSolution;
}

void CGeneticAlgorithm::vStartGeneticAlgorithm() {
    vGenerateRandomPopulation();
    vRunGenerations();
}

void CGeneticAlgorithm::vRunGenerations() {
    while (iCurrentIterationNumber != iIterationNumber) {
        iCurrentIterationNumber++;
        vCalculateAdaptations();
        crossPopulation();
        vUpdatePopulations();
        vMutatePopulation();
    }
    vFindBestSolution();
}

void CGeneticAlgorithm::vFindBestSolution() {
    vCalculateAdaptations();

    double dBestAdaptation = pcCurrentPopulation[0].dGetAdaptation();
    int *piBestGenotype = pcCurrentPopulation[0].piGetGenotype();

    for (int i = 1; i < iPopulationSize; i++) {
        if ((pcCurrentPopulation[i]).dGetAdaptation() > dBestAdaptation) {
            dBestAdaptation = (pcCurrentPopulation[i]).dGetAdaptation();
            piBestGenotype = (pcCurrentPopulation[i]).piGetGenotype();
        }
    }
    pcSolution->vSetSolution(dBestAdaptation, piBestGenotype);
}

void CGeneticAlgorithm::vUpdatePopulations() {
    if (iCurrentIterationNumber % 2 == 0) {
        pcCurrentPopulation = pcEvenPopulation;
        pcNotCurrentPopulation = pcOddPopulation;
    } else {
        pcCurrentPopulation = pcOddPopulation;
        pcNotCurrentPopulation = pcEvenPopulation;
    }
}

void CGeneticAlgorithm::vCalculateAdaptations() {
    for (int i = 0; i < iPopulationSize; i++) {
        pcCurrentPopulation[i].vCountAdapatation(pcProblem);
    }
}

CIndividual *CGeneticAlgorithm::piChooseRandomInd() {
    return &pcCurrentPopulation[pcRandomNumberGenerator->generateNumberInt(0, iPopulationSize - 1)];
}

void CGeneticAlgorithm::crossPopulation() {
    int iNumberOfCrossing = iPopulationSize / 2;

    for (int i = 0; i < iNumberOfCrossing; i++) {

        CIndividual *pcChild1 = piChooseRandomInd();
        CIndividual *pcChild2 = piChooseRandomInd();

        pcChild1->vCrossIndividuals(pcChild2, &pcNotCurrentPopulation[2 * i], &pcNotCurrentPopulation[2 * i + 1],
                                    dCrossingProbability, pcProblem->iGetISize(), pcRandomNumberGenerator);
    }
}

void CGeneticAlgorithm::vMutatePopulation() {
    for (int i = 0; i < iPopulationSize; i++) {
        pcCurrentPopulation[i].vMutateIndividual(dMutationProbability, pcProblem->iGetISize(),
                                                 pcRandomNumberGenerator, piChooseRandomInd());
    }
}

void CGeneticAlgorithm::vGenerateRandomPopulation() {
    for (int i = 0; i < iPopulationSize; i++) {
        pcEvenPopulation[i] = CIndividual(piGenerateGenotype());
        pcOddPopulation[i] = CIndividual(new int[pcProblem->iGetISize()]);
    }
}

int *CGeneticAlgorithm::piGenerateGenotype() {
    int *piGenotype = new int[pcProblem->iGetISize()];
    for (int i = 0; i < pcProblem->iGetISize(); i++) {
        piGenotype[i] = pcRandomNumberGenerator->generateNumberInt(0, 1);
    }
    return piGenotype;
}

