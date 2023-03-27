#include <iostream>
#include <random>

#include "CGeneticAlgorithm/CGeneticAlgorithm.h"

void testWithGivenSeed(std::string sFileName, int iPopulationSize, double dCrosProb, double dMutProb,
                       int iIterNum, unsigned long ulSeed) {

    CProblem *pcKnapsackProblem = new CKnapsackProblem;
    if (pcKnapsackProblem->bReadInstanceFromFile(sFileName)) {
        CRandomNumberGenerator *pcRanNumGen = new CRandomNumberGenerator(ulSeed);

        CGeneticAlgorithm *pcGenAlg = new CGeneticAlgorithm(pcKnapsackProblem, iPopulationSize,
                                                            dCrosProb, dMutProb, iIterNum, pcRanNumGen);

        pcGenAlg->vStartGeneticAlgorithm();

        for (int i = 0; i < pcKnapsackProblem->iGetISize(); i++) {
            std::cout << (pcGenAlg->piGetBestSolution()->dGetBestGenotype())[i];
        }
        std::cout << " " << pcGenAlg->piGetBestSolution()->dGetBestAdaptation();
        delete pcGenAlg;
        delete pcRanNumGen;
    }
    delete pcKnapsackProblem;
}

void test(std::string sFileName, int iPopulationSize, double dCrosProb, double dMutProb, int iIterNum) {

    CProblem *pcKnapsackProblem = new CKnapsackProblem;
    if (pcKnapsackProblem->bReadInstanceFromFile(sFileName)) {
        CRandomNumberGenerator *pcRanNumGen = new CRandomNumberGenerator();
        std::cout << pcRanNumGen->getSeed() << "\n";

        CGeneticAlgorithm *pcGenAlg = new CGeneticAlgorithm(pcKnapsackProblem, iPopulationSize,
                                                            dCrosProb, dMutProb, iIterNum, pcRanNumGen);

        pcGenAlg->vStartGeneticAlgorithm();

        for (int i = 0; i < pcKnapsackProblem->iGetISize(); i++) {
            std::cout << (pcGenAlg->piGetBestSolution()->dGetBestGenotype())[i];
        }
        std::cout << " " << pcGenAlg->piGetBestSolution()->dGetBestAdaptation();
        delete pcGenAlg;
        delete pcRanNumGen;
    }
    delete pcKnapsackProblem;
}

int main() {
    std::string sFileName = ".\\CProblem\\InstancjaProblemu.txt";

    testWithGivenSeed(sFileName, 100, 0.6, 0.1, 100, 1104690266);
    std::cout << "\n";
    test(sFileName, 100, 0.6, 0.1, 100);
    return 0;
}
