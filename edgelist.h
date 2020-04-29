#ifndef EDGELIST_H_
#define EDGELIST_H_


#include <iostream>

struct matelem{
  int begin, end, value;
  matelem *next;
};

class matlist{
    matelem *head, *tail;
    public:
    matlist(){
      head=NULL;
      tail=NULL;
    }
    int *returnelem(int number);
    void insertback(int begin, int end, int value);
    void insertfront(int begin, int end, int value);
    void display();
    void insertpos(int pos,int begin,int end, int value);
    void deletefront();
    void deleteback();
    void deletepos(int pos);
    int size();
    void displayfront();
    void displayback();
    int returnvalue(int number);
  };

int matlist::returnvalue(int number){
	int ret;
	matelem *temp=new matelem;
	temp=head;
	if(number<=size() && number>=0){
			  for(int i=0; i<number; i++){
			    temp=temp->next;
			  }
	}ret=temp->value;
	return ret;
}

int *matlist::returnelem(int number){
	static int arr[3];
	matelem *temp=new matelem;
	temp=head;

	if(number<=size() && number>=0){
		  for(int i=0; i<number; i++){
		    temp=temp->next;
		  }
	arr[0]=temp->begin;
	arr[1]=temp->end;
	arr[2]=temp->value;
	}else{
		std::cout<<"przekroczono zakres listy"<<std::endl;
	}
	return arr;
}


  void matlist::insertback(int begin,int end, int value){
      matelem *temp=new matelem;
      temp->begin=begin;
      temp->end=end;
      temp->value=value;
      temp->next=NULL;
      if(head==NULL){
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else{
        tail->next=temp;
        tail=temp;
      }
    }

  void matlist::insertfront(int begin,int end, int value){
    matelem *temp=new matelem;
    temp->begin=begin;
    temp->end=end;
    temp->value=value;
    temp->next=head;
    head=temp;
  }

  void matlist::insertpos(int pos, int begin,int end, int value){
    matelem *pre=new matelem;
    matelem *cur=new matelem;
    matelem *temp=new matelem;
    cur=head;
    for(int i=0;i<pos;i++){
      pre=cur;
      cur=cur->next;
    }
    temp->begin=begin;
    temp->end=end;
    temp->value=value;
    pre->next=temp;
    temp->next=cur;
}

int matlist::size(){
  int size=0;
  matelem *temp=new matelem;
  temp=head;
  while(temp!=NULL){
    temp=temp->next;
    size++;
  }
  return size;
}

void matlist::deletefront(){
  matelem *temp=new matelem;
  temp=head;
  head=head->next;
  delete temp;
}

void matlist::deleteback(){
  matelem *current=new matelem;
  matelem *previous=new matelem;
  current=head;
  while(current->next!=NULL){
    previous=current;
    current=current->next;
  } tail=previous;
  previous->next=NULL;
  delete current;
}

void matlist::deletepos(int pos){
  matelem *current=new matelem;
  matelem *previous=new matelem;
  current=head;
  for(int i=1;i<pos;i++){
    previous=current;
    current=current->next;
  } previous->next=current->next;
}

void matlist::display(){
  matelem *temp=new matelem;
  temp=head;
  std::cout<<"krawedzie"<<std::endl;
  while(temp!=NULL){
    std::cout<<temp->begin<<"   "<<temp->end<<"    "<<temp->value<<std::endl;
    temp=temp->next;
  }
}

void matlist::displayfront(){
  matelem *temp=new matelem;
  temp=head;
  std::cout<<temp->begin<<"   "<<temp->value<<std::endl;
}

void matlist::displayback(){
  matelem *temp=new matelem;
  temp=head;

  for(int i=1;i<size();i++) temp=temp->next;
  std::cout<<temp->begin<<"   "<<temp->value<<std::endl;
}


#endif /* LISTA_H_ */
