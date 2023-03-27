//
// Created by agabe on 14.01.2023.
//

#include "CRandomNumberGenerator.h"

std::random_device CRandomNumberGenerator::rd;
std::mt19937 CRandomNumberGenerator::gen(rd());
unsigned long CRandomNumberGenerator::ulSeed;


CRandomNumberGenerator::CRandomNumberGenerator() {
    ulSeed = rd();
    gen.seed(ulSeed);
}

CRandomNumberGenerator::CRandomNumberGenerator(unsigned long ulSeed) {
    this->ulSeed = ulSeed;
    gen.seed(ulSeed);
}

unsigned long CRandomNumberGenerator::getSeed() {
    return ulSeed;
}

int CRandomNumberGenerator::generateNumberInt(int iMin, int iMax) {
    std::uniform_int_distribution<> distribInt(iMin, iMax);
    return distribInt(gen);
}

double CRandomNumberGenerator::generateNumberDouble(double dMin, double dMax) {
    std::uniform_real_distribution<> distrib(dMin, dMax);
    return distrib(gen);
}
