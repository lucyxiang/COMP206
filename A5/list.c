#include "list.h"
#include<stdlib.h>
#include<stdio.h>

//struct NODE* space; //initialize NODE* called space
static struct NODE *head; //initialize NODE* called header

void newList(){
  //space = (struct NODE*)malloc(sizeof(struct NODE*));
  //head = space;
  head = NULL; //points head to NULL
}


int addNode(int value){
struct NODE* temp = (struct NODE*) malloc(sizeof(struct NODE));
if(temp==NULL){ //error if malloc fail
  return 0; //return false = 0 for failure
  exit(1);
}
temp->data=value;
temp->next=head;
head=temp; //adds node to front of list
return 1; //return true = 1 for success
}

void prettyPrint(){ //prints linked list in reverse order
  while(head != NULL){ //traverse list and print until head is null aka at end of list
    printf("%d", head->data);
    head= head->next;
  }
}
