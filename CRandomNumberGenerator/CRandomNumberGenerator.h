//
// Created by agabe on 14.01.2023.
//

#ifndef MINIPROJEKTTEP_CRANDOMNUMBERGENERATOR_H
#define MINIPROJEKTTEP_CRANDOMNUMBERGENERATOR_H


#include <random>
#include <iostream>

class CRandomNumberGenerator {
public:
    static std::mt19937 gen;
    static std::random_device rd;
    static unsigned long ulSeed;

    CRandomNumberGenerator();

    CRandomNumberGenerator(unsigned long ulSeed);

    unsigned long getSeed();

    int generateNumberInt(int iMin, int iMax);

    double generateNumberDouble(double dMin, double dMax);
};

#endif //MINIPROJEKTTEP_CRANDOMNUMBERGENERATOR_H
