#include<stdlib.h>
#ifndef LISTH
#define LISTH
struct NODE{ //structure of a linked list with data and pointer to next node
  int data;
  struct NODE* next;
};
#endif

void newList();
int addNode(int);
void prettyPrint();
