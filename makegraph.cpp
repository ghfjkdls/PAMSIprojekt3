#include <iostream>
#include <fstream>

int main(int argc,char **argv){
  std::ofstream file;
  int size=0,edges=0;
  float dens;
  int counter=0;
  int  x, y, check, tabsize;

  for (int i=1; i<argc; i++){
    if (argv[i][0] != '-') return 1;
    switch (argv[i][1]) {
    case 'n':{
      i++;
      sscanf(argv[i],"%d",&size);
    } break;
    case 'd':{
      i++;
      sscanf(argv[i],"%f",&dens);
    }break;
  }}
  std::cout<<size<<std::endl;
  std::cout<<dens<<std::endl;
  edges=size*(size-1)*dens/200;
  std::cout<<edges<<std::endl;
  tabsize=size;
  int exx[edges], exy[edges];
  for(int i=0; i<size-2; i++){
    exx[i]=i;
    exy[i]=i+2;
  }
  for(int i=0;i<1;i++){
    file.open(std::to_string(i));
    file<<size<<"  "<<edges<<std::endl;
  	file<<"0"<<" "<<"1"<<" "<<rand()%1000<<std::endl;
    counter++;
    for(int i=1;i<size;i++){// tworzenie spojnych krawedzi w grafie
      file<<i-1<<" "<<i+1<<" "<<rand()%1000<<std::endl;
      counter++;
    }
    for(int i=counter; i<edges; i++){// tworzenie krawedzi aby graf sie zgadzal
      x=rand()%size;
      y=rand()%size;
      check=0;
      for(int j=0; j<tabsize; j++){
        if(x==exx[i] && y==exy[i])check=1;
      }if(check==0){
        file<<x<<" "<<y<<" "<<rand()%1000<<std::endl;
        exx[tabsize]=x;
        exy[tabsize]=y;
        tabsize++;
        counter++;
      }
    }
    file.close();
  }
  return 0;
}
