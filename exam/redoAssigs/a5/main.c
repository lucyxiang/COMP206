#include<stdio.h>
#include"list.h"

void newList();
int addNode(int);
void prettyPrint();

int main(){
  int value=1;
  newList();

  printf("Input a positive value: ");
  scanf("%d", &value);
  while(value>=0){
    if(addNode(value)==0) exit(1);
    printf("Input a positive value: ");
    scanf("%d", &value);
  }
  prettyPrint();
  return 0;
}
