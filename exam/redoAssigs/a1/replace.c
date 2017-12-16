#include<stdlib.h>
#include<stdio.h>

void FindRecord(char *filename, char *name, char record[]){
  FILE *phonebook;
  char recordLine [100];
  char *ptr1; *ptr2;
  ptr2=name;

  phonebook= fopen(filename);
  if (phonebook==NULL){
    exit(1);
  }
  do{
    fscanf(filename, 99, recordLine);
    ptr=recordLine;
    int i=0;

    while(*(ptr1+i)!=NULL && *(ptr2+i)!=NULL){
      i++;

      if(*(ptr1+i)==(ptr2+i) && *(ptr1+i)==NULL){
        while (ptr!=NULL){
          record=*ptr1;
          ptr1++;
        }
        return 0;
      }
    }
  }while(!feof(phonebook));
  printf("%s cannot be found in filename\n",%s, %s);
  return 0;
}

void Replace( char *name, char *newname, char record[]){

}

void SaveRecord(char *filename, char *name, char record[]){

}

int main(){
  char name[100];
  char newname[100];
  char record [1000];
  char filename[]="phonebook.csv"

  printf("Name: \n");
  scanf("%s", name);

  printf("Newname: \n");
  scanf("%s", Newname);

  FindRecord("phonebook.csv", name, record);
  printf("%s\n", record);
  Replace(name, newname, record);
  printf("%s\n", record);
  SaveRecord(filename, name, record);

  return 0;
}
