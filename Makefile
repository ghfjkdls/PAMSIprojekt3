grafonlist: grafonlist.cpp
	g++ -Wall grafonlist.cpp -o grafzaimplementowanynaliscie -I.

grafonmatrix: grafonmatrix.cpp
	g++ -Wall grafonmatrix.cpp -o grafzaimplementowanynamacierzy -I.

kruskallist: kruskallist.cpp
	g++ -Wall kruskallist.cpp -o algorytmkruskaladlagrafuzaimplementowanegonaliscie -I.

kruskalmatrix: kruskalmatrix.cpp
	g++ -Wall kruskalmatrix.cpp -o algorytmkruskaladlagrafuzaimplementowanegonamacierzy -I.

primlist: primlist.cpp
	g++ -Wall primlist.cpp -o algorytmprimadlagrafuzaimplementowanegonaliscie -I.

primmatrix: primmatrix.cpp
	g++ -Wall primmatrix.cpp -o algorytmprimaaladlagrafuzaimplementowanegonamacierzy -I.