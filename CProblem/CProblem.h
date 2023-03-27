#ifndef MINIPROJEKTTEP_CPROBLEM_H
#define MINIPROJEKTTEP_CPROBLEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include "../CItems/CItems.h"

class CProblem {
public:
    virtual int iGetISize() = 0;

    virtual double dCalculateAdaptation(int *piGenotype) = 0;

    virtual bool bReadInstanceFromFile(std::string sFileName) = 0;

    virtual ~CProblem() {}
};

class CKnapsackProblem : public CProblem {
private:
    double knapsackCapacity;
    CItems *pcItems;
public:
    CKnapsackProblem();

    int iGetISize() override;

    double dCalculateAdaptation(int *piGenotype) override;

    ~CKnapsackProblem();

    bool bReadInstanceFromFile(std::string fileName) override;
};

#endif //MINIPROJEKTTEP_CPROBLEM_H
