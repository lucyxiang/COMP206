#include "list.h"
#include<stdlib.h>
#include<stdio.h>

int main(){
  int num=1; //initialize int num
  newList(); //create new list

  while(num > 0){ //takes in user input int if int > 0
      printf("Enter a postivie integer numeber (n>0) \n");
      scanf("%d", &num);
      if(num>0)addNode(num);
    }

prettyPrint(); //prints

  return 0;
}
