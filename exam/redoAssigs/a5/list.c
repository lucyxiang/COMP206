#include<stdio.h>
#include"list.h"
#define TRUE 1
#define FALSE 0

static struct NODE* head;

void newList(){
  head=NULL;
  return;
}


int addNode(int value){
  struct NODE* tmp=(struct NODE*) malloc(sizeof(struct NODE));
  if(tmp==NULL){
    return FALSE;
  }
  tmp->data=value;
  tmp->next=head;
  head=tmp;

  return TRUE;
}


void prettyPrint(){
  struct NODE* tmp=head;
  while(tmp!=NULL){
    printf("%d\n", tmp->data);
    tmp=tmp->next;
  }
  return;
}
