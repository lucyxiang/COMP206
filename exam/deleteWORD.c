#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void delete(){
  FILE *input, *output;
  char *word="WORD";
  char buffer [100];

  input=fopen("input.txt", "rt");
  output=fopen("output.txt", "wt");
  if (input==0 || output==0){
    exit(1);
  }

  fscanf(input, "%s", buffer);
  do{
    if(strstr(buffer, word)==NULL){
      fputs(buffer, output);
      printf("%s \n",buffer );
    }
  fscanf(input, "%s", buffer);
  }while(!feof(input));

  fclose(input);
  fclose(output);

}

int main(){
  delete();
  return 0;
}
