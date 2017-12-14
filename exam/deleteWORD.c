#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void delete(){
  FILE *input, *output;
  char c;
  char ptr1*, *ptr2;
  char *word="WORD";
  char buffer [2000];

  input=fopen("test.txt", "rt");
  output=fopen("output.txt", "wt");
  if (input==0 || output==0){
    exit(1);
  }

  fgets(buffer,1999,inFile);

  if(strstr(buffer, word)==null){
    q=fopen("output.txt", "wt");
    if (q==0){
      exit(1);
    }
    pointer=buffer;
    c=pointer;

    do{
      fputc(q, c);
      pointer++;
      c=pointer;
    }while(c!=null);
  }
  else(){


  }



}
int main(){
  dele
}
