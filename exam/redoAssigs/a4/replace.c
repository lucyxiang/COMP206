#include<stdlib.h>
#include<stdio.h>
//#define debug

void FindRecord(char *filename, char *name, char record[]){
  char recordLine [100];
  char *ptr1, *ptr2;

  FILE *phonebook;
  phonebook= fopen(filename, "rt");
  if (phonebook==NULL){
    printf("Problem with opening %s\n", filename);
    exit(1);
  }

  do{
    fgets(recordLine,99, phonebook);
    ptr1=recordLine;
    ptr2=name;
    int i=0;

    while(*(ptr1+i)==*(ptr2+i) && (*(ptr1+i)!=',' || *(ptr2+i)!=EOF)){
      i++;
      if(*(ptr1+i)==',' && *(ptr2+i)==0){
        while (*ptr1!=EOF){
          *record=*ptr1;
          record++;
          ptr1++;
        }
        fclose(phonebook);
        return;
      }
    }
  }while(!feof(phonebook));
  fclose(phonebook);
  printf("%s cannot be found in %s\n",name, filename);
  exit(1);
}

void Replace(char *name, char *newname, char record[]){
  char *ptr1, *ptr2;
  int nameLength=0;
  int newnameLength=0;

  ptr1=name;
  while(*ptr1!=0){
    ptr1++;
    nameLength++;
  }

  ptr1=newname;
  while(*ptr1!=0){
    ptr1++;
    newnameLength++;
  }

  ptr1=record;
  while(*ptr1!='\0'){
    ptr1++;
  }
  ptr1=ptr1-nameLength+newnameLength;

  while(ptr1!=record){
    *ptr1=*(ptr1+nameLength-newnameLength);
    #ifdef debug
    printf("%d\n",record);
    printf("%d\n",ptr1);
    #endif
    ptr1--;
  }

  ptr1=record;
  ptr2=newname;
  while(*ptr2!=0){
    *ptr1=*ptr2;
    #ifdef debug
    printf("%c\n", *ptr1);
    printf("%c\n", *ptr2);
    #endif

    ptr1++;
    ptr2++;
  }
  return;
}

void SaveRecord(char *filename, char *name, char record[]){
  char recordLine [100];
  char *ptr1, *ptr2;

  FILE *phonebook, *newPhonebook;
  phonebook= fopen(filename, "rt");
  newPhonebook=fopen("newPhonebook.csv", "wt");
  if (phonebook==NULL || newPhonebook==NULL){
    printf("Problem with opening %s\n", filename);
    exit(1);
  }

  do{
    fgets(recordLine,99, phonebook);
    ptr1=recordLine;
    ptr2=name;
    int i=0;

    while(*(ptr1+i)==*(ptr2+i) && (*(ptr1+i)!=',' || *(ptr2+i)!=EOF)){
      i++;
      if(*(ptr1+i)==',' && *(ptr2+i)==0){
        fputs(record, newPhonebook);
        fgets(recordLine,99,phonebook);
      }
    }
    fputs(recordLine,newPhonebook);
  }while(!feof(phonebook));

  fclose(phonebook);
  fclose(newPhonebook);

  if(remove(filename)!=0)exit(1);
  if(rename("newPhonebook.csv", filename)!=0) exit(1);
  return;
}

int main(){
  char name[100];
  char newname[100];
  char record [1000];
  char filename[]="phonebook.csv";

  printf("Name: ");
  scanf("%s", name);

  printf("Newname: ");
  scanf("%s", newname);

  FindRecord("phonebook.csv", name, record);
  printf("%s\n", record);
  Replace(name, newname, record);
  printf("%s\n", record);
  SaveRecord(filename, name, record);

  exit (0);;
}
