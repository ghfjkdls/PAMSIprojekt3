#include <iostream>
#include "lista.h"
#include "graflista.h"
#include "grafmacierz.h"

int main() {
	graflist graf;
	int menu=0, *tab, ver1, ver2, vert, value, dens, edge;



	std::cout<<"podaj ilosc wierzcholkow i gestosc grafu"<<std::endl;
	std::cin>>vert>>dens;
	graf.create(vert, dens);


	while(menu!=99){
		std::cout<<"1-tablica wierzholkow krawedzi"<<std::endl;
		std::cout<<"2-przeciwlegly wierzcholek v wzldem e"<<std::endl;
		std::cout<<"3-czy 2 wierzcholki sa sasiednie"<<std::endl;
		std::cout<<"4-zastapienie elementu w wierzcholu"<<std::endl;
		std::cout<<"5-zastapienie elementu w krawedzi"<<std::endl;
		std::cout<<"6-dodaj wierzcholek"<<std::endl;
		std::cout<<"7-dodaj krawedz"<<std::endl;
		std::cout<<"8-usun wierzcholek"<<std::endl;
		std::cout<<"9-usun krawedz"<<std::endl;
		std::cout<<"10-wyswietl krawedzie przylegajace do wierzcholka"<<std::endl;
		std::cout<<"11-wyswietl graf"<<std::endl;
		std::cout<<"99-wyjdz"<<std::endl;
		std::cin>>menu;
		switch(menu){

			case 1:
				std::cout<<"podaj numer krawedzi"<<std::endl;
				std::cin>>vert;
				tab=graf.endverticle(vert);
				std::cout<<tab[0]<<"    "<<tab[1]<<std::endl;
				break;

			case 2:
				std::cout<<"podaj krawedz i wierzcholek"<<std::endl;
				std::cin>> edge>> vert;
				std::cout<<graf.opposite(vert, edge)<<std::endl;
				break;

			case 3:
				std::cout<<"podaj klucze 2 wierzcholkow"<<std::endl;
				std::cin>>ver1>>ver2;
				if(graf.areadjacent(ver1, ver2)==1) std::cout<<"sa sasiednie"<<std::endl;
				else 		std::cout<<"nie sa sasiednie"<<std::endl;
				break;

			case 4:
				std::cout<<"podaj wierzcholek i nowa wartosc"<<std::endl;
				std::cin>>vert>>value;
				graf.replacevert(vert, value);
				break;

			case 5:
				std::cout<<"podaj krawedz i nowa wartosc"<<std::endl;
				std::cin>>edge>>value;
				graf.replaceedge(edge, value);
				break;

			case 6:
				std::cout<<"podaj wartosc"<<std::endl;
				std::cin>>value;
				graf.insertvert(value);
				break;

			case 7:
				std::cout<<"podaj wierzcholii krawedzi i  wartosc"<<std::endl;
				std::cin>>ver1>>ver2>>value;
				graf.insertedge(ver1, ver2, value);
				break;

			case 8:
				std::cout<<"podaj wierzcholek"<<std::endl;
				std::cin>>vert;
				graf.removevert(vert);
				break;

			case 9:
				std::cout<<"podaj krawedz"<<std::endl;
				std::cin>>edge;
				graf.removeedge(edge);
				break;

			case 10:
				std::cout<<"podaj wierzcholek"<<std::endl;
				std::cin>>vert;
				graf.incidentedges(vert);
				break;

			case 11:
				graf.display();
				break;

			default: std::cout<<"podano zla wartosc"<<std::endl;
		}

	}



    return 0;
}
