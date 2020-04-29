# PAMSIprojekt3

do tworzenia grafow do testowania algorytmow sluzy plik makegraph, ktory generuje 100 grafow nieskierowanych spojnych
uruchamia sie go w postaci ./[nazwaprogramu] -n [ilosc wierzcholkow] -d [gestosc grafu] gestosc grafu musi byc 
z zakresu25 - 100 a liczba elementow powyzej 10

do testowania implementacji grafow sluza pliki grafonlist.cpp , jest to graf zaimplementowany na liscie i grafonmatrix.cpp 
zaimplementowany na macierzy oba programy posiadaja menu.

do testowania algorytmu kruskala sluza pliki kruskallist.cpp, dla grafu opartego na liscieioraz kruskalmatrix.cpp 
dla grafu opartego na macierzy

do testowania algorytmu prima sluza pliki primmlist.cpp, dla grafu opartego na liscie oraz primmatrix.cpp 
dla grafu opartego na macierzy 

Uwaga podczas kompilacji pojawia sie ostrzezenie o nie uzywanej zmiennej parent[] w plikach grafmacierz.h i graflista.h 
wystepuje to poniewz wykomentowalem fragment kodu ktoruy sluzyj do wyswietlania listy krawedzi po uzyciu algoytmu prima
po wlaczeniu wywolania metody desplayprim nie pojawija sie zadne ostrzezenia.
