#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
  char word[20];
  char file1[20];
  char file2[20];

  FILE *input, *output;
  char buffer[100];

  if(argc!=4)exit(1);

  strcpy(word, argv[1]);
  strcpy(file1, argv[2]);
  strcpy(file2, argv[3]);

  input = fopen(file1, "rt");
  output = fopen(file2, "wt");
  if (input==NULL || output==NULL)exit(1);

  fgets(buffer, 99, input);
  do{
    if(strstr(buffer, word)==0){
      fputs(buffer, output);
    }
    fgets(buffer,99,input);
  }while(!feof(input));

  fclose(input);
  fclose(output);

  return 0;
}
