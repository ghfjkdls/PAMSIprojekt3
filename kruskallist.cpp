#include <iostream>
#include "lista.h"
#include "graflista.h"
#include "grafmacierz.h"
#include <fstream>
#include "edgelist.h"



int main(){
	double start, stop, time;
	std::ifstream file;

	graflist *graf=new graflist;
	matlist *list=new matlist;
	graf->fileread(file, 0);
	graf->edgesort();
	start=clock();
	*list=graf->kruskal();
	stop=clock();
	//list->display();
	time= double(stop-start)/double(CLOCKS_PER_SEC);
	std::cout<<time<<std::endl;
	delete graf;
	delete list;
	return 0;
}
