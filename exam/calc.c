#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
  int num1;
  int num2;
  char operation[10];
  char *operationPointer;
  operationPointer = (char *)malloc(20*sizeof(char));

  if(argc !=4){
    printf("%d \n", argc);
    exit(1);
  }

  num1= atoi(argv[1]);
  strcpy(operation, argv[2]);
  strcpy(operationPointer, argv[2]);
  num2= atoi(argv[3]);

  if(strcmp(operationPointer, "+")==0){
    printf(" %d + %d = %d \n", num1, num2, (num1+num2));
  }
  else if(strcmp(operation, "-")==0){
    printf(" %d - %d = %d \n", num1, num2, (num1-num2));
  }
  else if(strcmp(operation, "*")==0){
    printf(" %d * %d = %d \n", num1, num2, (num1*num2));
  }
  else if(strcmp(operation, "/")==0){
    printf(" %d / %d = %d \n", num1, num2, (num1/num2));
  }
  else{
    printf(" %d %d %s\n", num1, num2, operation);
  }
  return 0;
}
