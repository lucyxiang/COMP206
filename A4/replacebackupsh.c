#include<stdio.h>
#include<stdlib.h>

void findRecord(char *filename, char *name, char record[]){
  char temp;
  char *pointerToRecord = record;
  int counter=0;
  char *tempName = name;
  char *entry = calloc(256,sizeof(char));

  FILE *f = fopen(filename, "r");
  if (f==NULL){
    printf("Erro, exited");
    exit(1); //terminates with error
  }
  while(fscanf(f, "%s", entry)==1){
     while (*entry == *name && *name != '\0'){
        temp=*(entry+1);
        entry++, name++, counter++;
        }

        if(temp == ','){
          while(*(entry-counter) != '\0'){
          *pointerToRecord=*(entry-counter);
          entry++, pointerToRecord++;
        }
          temp='0';
          printf("%s\n",record );
        }
        }
}

void replace(char *name, char *newname, char record[]){
  int counterNewName=0;
  int counterName=0;
  char *pointerToRecord = record;
  int counter=0;

  for(; *(name+counterName) != '\0'; counterName++){}
  for(; *(newname+counterNewName) != '\0'; counterNewName++){}

  if(counterNewName>counterName){
    while (*(record) != '\0') {
      record++,counter++;
    }
    for(int i=counter-counterName+1; i>0; i--){
      *(record+counterNewName-counterName)=*(record);
      printf("%c", *(record+counterNewName));
      printf("%c\n", *(record));
      record--;
    }
    for(int i=0; i<counterNewName; i++){
      *(pointerToRecord+i)=*(newname+i);
  }
}

 if(counterName>counterNewName){
  for(int i=0; i<counterNewName; i++){
    *(pointerToRecord+i)=*(newname+i);
}
  while(*(record+counterName) != '\0'){
    *(record+counterNewName)=*(record+counterName);
    record++;
  }
  while(*(record+counterNewName) != '\0'){
    *(record+counterNewName)='\0';
    record++;
  }
}

if(counterName==counterNewName){
  for(int i=0; i<counterNewName; i++){
    *(pointerToRecord+i)=*(newname+i);
}
}
}


void saveRecord(char *filename, char *name, char record[]){
  FILE *f = fopen(filename, "r");
  FILE *fReplica = fopen("replica.csv", "w");
  if (f==NULL) exit(1); //terminates with error

  char *contactName= calloc(256,sizeof(char));
  char *age= calloc(256,sizeof(char));
  char *phoneNumber= calloc(256,sizeof(char));
  char ch;
  char temp;
  int counter=0;
  char *entry = malloc(sizeof(char)*256);

  while(fscanf(f, "%s", entry)==1){
     while (*entry == *name && *name != '\0'){
        temp=*(entry+1);
        entry++, name++, counter++;
        }

        if(temp == ','){
          fprintf(fReplica,"\n%s",record);
          temp=0;
        }
          else{
            fprintf(fReplica, "\n%s", entry);

          }
        }
  fclose(f);
  fclose(fReplica);
  remove(filename);
  rename("replica.csv", filename);

  f = fopen(filename, "r");
      ch = getc(f);
  while (ch != EOF)
   {
       printf("%c ", ch);
       ch = getc(f);
   }

  printf("DONEE");
}

int main (void){

char *name;
name = calloc(256,sizeof(char));

char *newname;
newname = calloc(256,sizeof(char));

char *filename;
filename = calloc(256,sizeof(char));
char record[1000*4];

if(name==NULL)printf("Error1");
if(filename==NULL)printf("Error2");
if(newname==NULL)printf("Error3");

printf("Filename: ");
scanf("%s", filename);

printf("Name: ");
scanf("%s", name);

printf("Newname: ");
scanf("%s", newname);


findRecord(filename, name, record);

replace(name, newname, record);

saveRecord(filename, name, record);

return 0;
}
