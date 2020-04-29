

#ifndef LISTA_H_
#define LISTA_H_


#include <iostream>

struct elem{
  int data;
  elem *next;
};

class list{
    elem *head, *tail;
    public:
    list(){
      head=NULL;
      tail=NULL;
    }
    void insertback(int value);
    void insertfront(int value);
    void display();
    void insertpos(int pos, int value);
    void deletefront();
    void deleteback();
    void deletepos(int pos);
    int size();
    void displayfront();
    void displayback();
    int returndata(int number);
  };

	int list::returndata(int number){
		  elem *temp=new elem;
			temp=head;
			int x;

			if(number<=size() && number>=0){
				  for(int i=0; i<number; i++){
				    temp=temp->next;
				  }x=temp->data;
			}else{
				std::cout<<"przekroczono zakres listy"<<std::endl;
			}
			return x;
	}

  void list::insertback(int value){
      elem *temp=new elem;
      temp->data=value;
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

  void list::insertfront(int value){
    elem *temp=new elem;
    temp->data=value;
    temp->next=head;
    head=temp;
  }

  void list::insertpos(int pos, int value){
    elem *pre=new elem;
    elem *cur=new elem;
    elem *temp=new elem;
    cur=head;
    for(int i=0;i<pos;i++){
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
}

int list::size(){
  int size=0;
  elem *temp=new elem;
  temp=head;
  while(temp!=NULL){
    temp=temp->next;
    size++;
  }
  return size;
}

void list::deletefront(){
  elem *temp=new elem;
  temp=head;
  head=head->next;
  delete temp;
}

void list::deleteback(){
  elem *current=new elem;
  elem *previous=new elem;
  current=head;
  while(current->next!=NULL){
    previous=current;
    current=current->next;
  } tail=previous;
  previous->next=NULL;
  delete current;
}

void list::deletepos(int pos){
  elem *current=new elem;
  elem *previous=new elem;
  current=head;
  for(int i=1;i<pos;i++){
    previous=current;
    current=current->next;
  } previous->next=current->next;
}

void list::display(){
  elem *temp=new elem;
  temp=head;
  while(temp!=NULL){
    std::cout<<temp->data<<"    ";
    temp=temp->next;
  }
}

void list::displayfront(){
  elem *temp=new elem;
  temp=head;
  std::cout<<temp->data<<std::endl;
}

void list::displayback(){
  elem *temp=new elem;
  temp=head;

  for(int i=1;i<size();i++) temp=temp->next;
  std::cout<<temp->data<<std::endl;
}


#endif /* LISTA_H_ */
