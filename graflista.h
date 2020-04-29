#ifndef GRAFLISTA_H_
#define GRAFLISTA_H_

#define SIZE 3

#include "lista.h"
#include <iostream>
#include "vertlist.h"
#include "edgelist.h"
#include <fstream>

class graflist{
	int *parent=new int[SIZE];
	int **primarray=new int*[SIZE];
	list **tab = new list*[SIZE];
	int verticles, edges, maxsize=SIZE;
	list *nood;
	vertlist vlist;
	matlist edlist;
public:
	void create(int vert, int dens);
	void display();
	int *endverticle(int edge);
	int opposite(int verticle, int edge);
	bool areadjacent(int ver1, int ver2);
	void replacevert(int vert, int value);
	void replaceedge(int edge, int value);
	void insertvert(int value);
	void insertedge(int vert1, int vert2, int value);
	void removeedge(int edge);
	void removevert(int vert);
	void incidentedges(int vert);
	void fileread(std::ifstream &file, int name);
	void edgesort();
	matlist kruskal();
	int findset(int i);
	int minKey(int key[], bool mstSet[]);
	void displayprim(int parent[]);
	void prim();
	int **primmatrixmake();
};

int graflist::minKey(int key[], bool mstSet[])
{
    int min = 100000, min_index;

    for (int v = 0; v < verticles; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void graflist::displayprim(int parent[])
{
    std::cout<<"Edge \t\t\tWeight\n";
    for (int i = 1; i < verticles; i++)
        std::cout<<parent[i]<<" - "<<i<<" \t\t\t"<<primarray[i][parent[i]]
															  <<std::endl;
}


void graflist::prim()
{	int big=1000;
    int parent[big], key[big];

    bool set[big];

    for (int i = 0; i < big; i++)
        key[i] = big, set[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < big - 1; count++) {

        int u = minKey(key, set);
        set[u] = true;
        for (int v = 0; v < big; v++)
            if (primarray[u][v] && set[v] == false && primarray[u][v] < key[v])
                parent[v] = u, key[v] = primarray[u][v];
    }

   // displayprim(parent);
}

int **graflist::primmatrixmake(){
	int  *elem;
	int **array= new int*[verticles];
	primarray=array;
	for(int i=0; i<verticles; i++)
				primarray[i]= new int[verticles];
	for(int i=0; i<verticles; i++)
		for(int j=0; j<verticles; j++) primarray[i][j]=0;

	for(int i=0; i<edges/2; i++){
		elem=edlist.returnelem(i);
		primarray[elem[0]][elem[1]]=elem[2];
		primarray[elem[1]][elem[0]]=elem[2];
	}
	return primarray;
}


matlist graflist::kruskal(){
	int i, urep, vrep;
	matlist temp;
	int *helptab, *elem;

	int *tablica=new int [verticles];
	parent=tablica;

	for (int i = 0; i < verticles; i++)
	    parent[i] = i;
	for (i = 0; i < edlist.size(); i++) {
		helptab=endverticle(i);
		urep=findset(helptab[0]);
		vrep=findset(helptab[1]);
		if (urep != vrep) {
			elem=edlist.returnelem(i);
			temp.insertback(elem[0], elem[1], elem[2]);
			parent[urep] = parent[vrep];
		}
	}return temp;
}

int graflist::findset(int i){
	 if (i == parent[i])
	        return i;
	 else
		return findset(parent[i]);
}


void graflist::edgesort(){
	matlist temp;
	int big, place, *elem, check;
	int used[edges/2];
	for(int j=0; j<edges/2; j++){
		big=999999999;
		for(int i=0; i<edges/2; i++){
			check=0;
			if(edlist.returnvalue(i)<big){
				for(int z=0; z<j+1; z++){
					if(used[z]==i) check=1;
				}
				if(check==0){
					big=edlist.returnvalue(i);
					place = i;
				}
			}
		}elem=edlist.returnelem(place);
		temp.insertback(elem[0], elem[1], elem[2]);
		used[j]=place;

	}//for(int i=0; i<edges/2; i++)std::cout<<used[i]<<"  ";
	edlist=temp;

}


void graflist::fileread(std::ifstream &file, int name){
	int filesize=0, c;
	file.open(std::to_string(name));
	while(file>>c) filesize++;
	file.close();
	 //  std::cout<<filesize;

	file.open(std::to_string(name));
	int inpt [filesize][3];
	file>>inpt[0][0];
	file>>inpt[0][1];
	for(int i=1;i<filesize/3+1;i++)
		for(int j=0; j<3; j++) {
			file>>inpt[i][j];
		}
	file.close();
	//std::cout<<inpt[0][0]<<"  "<<inpt[0][1]<<std::endl;
	//for(int i=1;i<filesize/3+1;i++) std::cout<<inpt[i][0]<<" "<<inpt[i][1]<<" "<<inpt[i][2]<<std::endl;
	verticles=inpt[0][0];
	edges=2*inpt[0][1];
	list **newtab = new list *[verticles];
		maxsize=verticles;
		tab=newtab;
		for(int i=0; i<verticles; i++) tab[i]=NULL;
		for(int i=0; i<verticles; i++){
			nood= new list;
			tab[i]=nood;
		}
		for(int i=1; i<edges/2+1; i++){
					tab[inpt[i][0]]->insertback(inpt[i][1]);
					tab[inpt[i][1]]->insertback(inpt[i][0]);
				}
		for(int i=1; i<filesize/3+1; i++)
			 edlist.insertback(inpt[i][0], inpt[i][1], inpt[i][2]);
		for(int i=0; i<verticles;i++){
			vlist.insertback(i,1);
		}

}



void graflist::incidentedges(int vert){
	int counter=0;
	int *arr;
	int tab[edges];
	if(vert>verticles ){
		std::cout<<"wykroczono poza zakres tablicy"<<std::endl;
		return ;
	}
	for(int i=0; i<edges/2; i++){
		arr=endverticle(i);
		if(arr[0]==vert){
			tab[counter]=i;
			counter++;
		}if(arr[1]==vert){
			tab[counter]=i;
			counter++;
		}
	}std::cout<<"krawedzie przylegajace do zadanego wierzholka"<<std::endl;
    for(int i=0; i<counter; i++) std::cout<<tab[i]<<"   "<<std::endl;

	return;
}


void graflist::removevert(int vert){
	int *arr;
	int counter=0, i=0;
	if(vert>verticles -1){
		std::cout<<"wykroczono poza zakres tablicy"<<std::endl;
		return ;
	}if(vert==0){
		vlist.deletefront();
	}
	vlist.deletepos(vert+1);
	while(counter<edges/2 - (1+i*2)){
		arr=endverticle(counter);
		//std::cout<<counter<<"   "<<arr[0]<<"   "<<arr[1]<<std::endl;
			if(arr[0]==vert){
				removeedge(counter);
				counter--;
				i++;
			}if(arr[1]==vert){
				removeedge(counter);
				counter--;
				i++;
			}
			counter++;
	}
	verticles--;
	for(int i=vert; i<verticles; i++) tab[i-1]=tab[i];
}


void graflist::removeedge(int edge){
	int *arr;
	if(edge>edges ){
		std::cout<<"wykroczono poza zakres tablicy"<<std::endl;
		return ;
	}arr=endverticle(edge);
	if(edge==0){
		edlist.deletefront();
		std::cout<<arr[0]<<"  "<<arr[1]<<std::endl;
		if(tab[arr[0]]->size()==1) tab[arr[0]]->deletefront();
		else{
			for(int i=0; i<tab[arr[0]]->size(); i++)
				if(tab[arr[0]]->returndata(i)==arr[1]) tab[arr[0]]->deletepos(i+1);
		}
		if(tab[arr[0]]->size()==1) tab[arr[0]]->deletefront();
		else{
		for(int i=0; i<tab[arr[1]]->size(); i++)
			if(tab[arr[1]]->returndata(i)==arr[0]) tab[arr[1]]->deletepos(i+1);
		}
		return;
	}edlist.deletepos(edge+1);
	std::cout<<arr[0]<<"  "<<arr[1]<<std::endl;
	if(tab[arr[0]]->size()==1) tab[arr[0]]->deletefront();
	else{
		for(int i=0; i<tab[arr[0]]->size(); i++)
			if(tab[arr[0]]->returndata(i)==arr[1]) tab[arr[0]]->deletepos(i+1);
	}
	if(tab[arr[0]]->size()==1) tab[arr[0]]->deletefront();
	else{
	for(int i=0; i<tab[arr[1]]->size(); i++)
		if(tab[arr[1]]->returndata(i)==arr[0]) tab[arr[1]]->deletepos(i+1);
	}
}



void graflist::insertedge(int vert1, int vert2, int value){
	for(int i=0; i<tab[vert1]->size(); i++){
		if(tab[vert1]->returndata(i)==vert2){
			std::cout<<"ta krawedz juz istnieje"<<std::endl;
			return;
		}
	}
	edges=edges+2;
	tab[vert1]->insertback(vert2);
	tab[vert2]->insertback(vert1);
	edlist.insertback(vert1, vert2, value);
}

void graflist::insertvert(int value){
	std::cout<<verticles<<std::endl;
	if(verticles>=maxsize-1){
	    std::cout<<"powiekszam"<<std::endl;
	    maxsize++;
	    list **newtab = new list*[maxsize];
	    for(int i=0;i<verticles;i++){
	       newtab[i]=tab[i];
	     }
	    tab=newtab;
	}
	    verticles++;
	    tab[verticles-1]=NULL;
	    nood= new list;
	    tab[verticles-1]=nood;
	    vlist.insertback(verticles-1,value);
		std::cout<<verticles<<std::endl;

}

void graflist::replaceedge(int edge, int value){
	int *tab;
	if(edge>edges ){
		std::cout<<"wykroczono poza zakres tablicy"<<std::endl;
		return ;
	}
	tab=endverticle(edge);
	if(edge==0){edlist.deletefront();
		edlist.insertfront(tab[0],tab[1],value);
		return;
	}

	edlist.deletepos(edge);
	edlist.insertpos(edge, tab[0],tab[1], value);
}


void graflist::replacevert(int vert, int value){
	if(vert>verticles ){
		std::cout<<"wykroczono poza zakres tablicy"<<std::endl;
		return ;
	}
	if(vert==0){vlist.deletefront();
		vlist.insertfront(0,value);
		return;
	}

	vlist.deletepos(vert+1);
	vlist.insertpos(vert, vert, value);
}



bool graflist::areadjacent(int ver1, int ver2){
	if(ver1>verticles || ver2>verticles){
		std::cout<<"wykroczono poza zakres tablicy"<<std::endl;
		return false;
	}
	for(int i=0; i<tab[ver1]->size(); i++){
		if(tab[ver1]->returndata(i)==ver2) return true;
	}
	return false;
}


int graflist::opposite(int verticle, int edge){
	int *arr;
	arr=endverticle(edge);
	if(arr[0]==verticle) return arr[1];
    if(arr[1]==verticle) return arr[0];
    std::cout<<"krawedz nie nalezy do wierzcholka"<<std::endl;

	return -99;
}

int *graflist::endverticle(int edge){
	static int arr[2];
	int *temp;
	temp=edlist.returnelem(edge);
	arr[0]=temp[0];
	arr[1]=temp[1];
   return arr;
}

void graflist::create(int vert, int dens){
	int counter=0, x, y, *arr,exist;

	if(dens<25 || dens>100){
		std::cout<<"zla wartosc gestosci grafu";
		return;
	}verticles=vert;
	edges=dens*vert*(vert-1)/100;

	list **newtab = new list *[verticles];
	maxsize=verticles;
	tab=newtab;
	for(int i=0; i<verticles; i++) tab[i]=NULL;
//tworzenie krawedzi zeby byl spojny
	for(int i=0; i<verticles-1; i++){
		if(i==0){
			nood= new list;
			nood->insertback(i+1);
			tab[i]=nood;
			counter++;
		}else{
		nood= new list;
		nood->insertback(i+1);
		nood->insertback(i-1);
		tab[i]=nood;
		counter=counter+2;
		}
	}nood= new list;
	nood->insertback(verticles-2);
	tab[verticles -1]=nood;
	counter++;
	//dodawanie kraedzi zeby gestosc sie zgadzala
	while(counter<edges){
		x=rand() % verticles;
		y=rand() % verticles;
		for(int i=0; i<tab[x]->size(); i++){
			if(tab[x]->returndata(i)==y){
				i=tab[x]->size();
			}
			else{
				if(i==tab[x]->size()-1){
					tab[x]->insertback(y);
					tab[y]->insertback(x);
					counter=counter+2;
					i=tab[x]->size();
				}
			}
		}
	}
	//dodawanie wartosci krawedziom
	for(int i=0; i<verticles; i++){
		for(int j=0; j<tab[i]->size(); j++){
			exist=0;
			for(int z=0; z<edlist.size(); z++){
				arr=endverticle(z);
				if(arr[0]==tab[i]->returndata(j) && arr[1]==i) exist=1;
			}if(exist==0){
				edlist.insertback(i, tab[i]->returndata(j), rand()%1000);
			}
		}
	}
	//nadawanie wierzcholkom wartosci
	for(int i=0; i<verticles;i++){
		vlist.insertback(i,rand() % 1000);
	}

}

void graflist::display(){
	for(int i=0; i<verticles; i++){
		std::cout<<"element listy "<< i<<":   ";
		tab[i]->display();
		std::cout<<std::endl;
	}vlist.display();
	edlist.display();
}

#endif
