# Genetic-Algorithm
[ENG]
### Knapsack problem solved using a genetic algorithm
**The Genetic Algorithm** involves generating a population of individuals, where each individual has a genotype in the form of a binary array, which indicates whether the individual has a particular trait or not. Simulated creation of new generations of the population, which are offspring of crossed and mutated parents selected in earlier selection. This allows to obtain a population of the best individuals, i.e. the best solution to a given binary problem.

The project presents the operation of the algorithm on the example of a binary knapsack problem [1], but it can be used for other binary problems.

In the `ProblemInstance.txt` file, sample data is given in order:
knapsack capacity: 5, number of items: 4, weight array size: 4, weights: [4, 1, 3, 2], value array size: 4, values: [5, 1, 4, 3.5].
In the `main.cpp`  file, the parameters are parameterized:
- crossover probability
- mutation probability
- number of generations
- number of individuals in the population
For these data, the best individual (solution) is a knapsack with items marked with indexes [0, 0, 1, 1], i.e. the third and fourth items (with weights of 3 and 2 respectively), and the best value of the knapsack is 7.5.

[1] Binary Knapsack Problem:
- We have a knapsack of a certain capacity
- We have n items that we want to pack, each with a certain weight and value (each appears only once)
- Problem: we want to pack the knapsack in such a way that it has the highest possible value.

[PL]
### Problem plecakowy, rozwiązany przy pomocy algorytmu genetycznego

**Algorytm Genetyczny** polega na wygenerowaniu populacji osobników, gdzie każdy osobnik posiada genotyp w postaci tablicy zer i jedynek, które odpowiadają temu, czy osobnik posiada daną cechę czy nie. Symulowane jest tworzenie nowych pokoleń populacji, które są potomkami skrzyżowanych i zmutowanych rodziców, wybranych we wcześniejszej selekcji. Pozwala to otrzymać populację najlepszych osobników, czyli najlepsze rozwiązanie danego problemu binarnego.

Projekt przedstawia działanie algorytmu na przykładzie binarnego problemu plecakowego[1], jednak można go wykorzystać do innych problemów binarnych.

W pliku `ProblemInstance.txt` podane są kolejno przykładowe dane: 
pojemność plecaka: 5, liczba przedmiotów: 4, rozmiar tablicy wag: 4, wagi: [4, 1, 3, 2], rozmiar tablicy wartości: 4, wartości: [5, 1, 4, 3.5].
W pliku `main.cpp` parametryzowane są:
 - prawdopodobieństwo krzyżowania
 - prawdopodobieństwo mutacji
 - liczba pokoleń
 - liczba osobników w populacji

Dla tych danych najlepszym osobnikiem(rozwiązaniem) jest plecak z przedmiotami oznaczonych indeksami [0, 0, 1, 1] czyli przedmioty trzeci i czwarty (o wagach kolejno 3 i 2), a najlepsza wartość plecaka wynosi 7.5.


[1]Binarny problem plecakowy:
   - mamy plecak o określonej pojemności
   - mamy n przedmiotów, które chcemy spakować, każdy o określonej wadze i wartości(każdy występuje tylko raz)
   - problem : chcemy spakować plecak tak, aby miał on jak największą wartość
