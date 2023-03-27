cmake_minimum_required(VERSION 3.23)
project(MiniprojektTEP)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        MiniprojektTEP main.cpp
        CProblem/CProblem.cpp
        CProblem/CProblem.h
        CIndividual/CIndividual.cpp
        CIndividual/CIndividual.h
        CGeneticAlgorithm/CGeneticAlgorithm.cpp
        CGeneticAlgorithm/CGeneticAlgorithm.h
        CRandomNumberGenerator/CRandomNumberGenerator.cpp
        CRandomNumberGenerator/CRandomNumberGenerator.h
        CSolution/CSolution.cpp
        CSolution/CSolution.h
        CItems/CItems.cpp
        CItems/CItems.h
)
