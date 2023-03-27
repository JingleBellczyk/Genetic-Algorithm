# Genetic-Algorithm
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
