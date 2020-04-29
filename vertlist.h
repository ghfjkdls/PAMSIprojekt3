
#ifndef VERTLIST_H_
#define VERTLIST_H_


#include <iostream>

struct vertelem{
  int key, value;
  vertelem *next;
};

class vertlist{
    vertelem *head, *tail;
    public:
    vertlist(){
      head=NULL;
      tail=NULL;
    }
    void insertback(int key,int value);
    void insertfront(int key, int value);
    void display();
    void insertpos(int pos,int key, int value);
    void deletefront();
    void deleteback();
    void deletepos(int pos);
    int size();
    void displayfront();
    void displayback();
  };


  void vertlist::insertback(int key, int value){
      vertelem *temp=new vertelem;
      temp->key=key;
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

  void vertlist::insertfront(int key, int value){
    vertelem *temp=new vertelem;
    temp->key=key;
    temp->value=value;
    temp->next=head;
    head=temp;
  }

  void vertlist::insertpos(int pos, int key, int value){
    vertelem *pre=new vertelem;
    vertelem *cur=new vertelem;
    vertelem *temp=new vertelem;
    cur=head;
    for(int i=0;i<pos;i++){
      pre=cur;
      cur=cur->next;
    }
    temp->key=key;
    temp->value=value;
    pre->next=temp;
    temp->next=cur;
}

int vertlist::size(){
  int size=0;
  vertelem *temp=new vertelem;
  temp=head;
  while(temp!=NULL){
    temp=temp->next;
    size++;
  }
  return size;
}

void vertlist::deletefront(){
  vertelem *temp=new vertelem;
  temp=head;
  head=head->next;
  delete temp;
}

void vertlist::deleteback(){
  vertelem *current=new vertelem;
  vertelem *previous=new vertelem;
  current=head;
  while(current->next!=NULL){
    previous=current;
    current=current->next;
  } tail=previous;
  previous->next=NULL;
  delete current;
}

void vertlist::deletepos(int pos){
  vertelem *current=new vertelem;
  vertelem *previous=new vertelem;
  current=head;
  for(int i=1;i<pos;i++){
    previous=current;
    current=current->next;
  } previous->next=current->next;
}

void vertlist::display(){
  vertelem *temp=new vertelem;
  temp=head;
  std::cout<<"wierzholki"<<std::endl;
  while(temp!=NULL){
    std::cout<<temp->key<<"   "<<temp->value<<std::endl;
    temp=temp->next;
  }
}

void vertlist::displayfront(){
  vertelem *temp=new vertelem;
  temp=head;
  std::cout<<temp->key<<"   "<<temp->value<<std::endl;
}

void vertlist::displayback(){
  vertelem *temp=new vertelem;
  temp=head;

  for(int i=1;i<size();i++) temp=temp->next;
  std::cout<<temp->key<<"   "<<temp->value<<std::endl;
}


#endif /* LISTA_H_ */
