#include <iostream>
#include "lista.h"
#include "graflista.h"
#include "grafmacierz.h"
#include <fstream>
#include "edgelist.h"



int main(){
	double start, stop, time;
	std::ifstream file;


	for(int i=0;i<100;i++){
		graflist *graf=new graflist;
		matlist *list=new matlist;
		graf->fileread(file, i);
		graf->primmatrixmake();
		start=clock();
		graf->prim();
		stop=clock();
		time= double(stop-start)/double(CLOCKS_PER_SEC);
		std::cout<<time<<std::endl;
		delete graf;
		delete list;
	}

	return 0;
}
