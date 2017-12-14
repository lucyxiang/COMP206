#include<stdio.h>
#include<stdlib.h>

void findRecord(char *filename, char *name, char record[]){
  char temp;
  char *pointerToRecord = record;
  char *tempName = name;
  int counter=0;
  char *entry = calloc(256,sizeof(char));
  int nameExist=0;

  FILE *f = fopen(filename, "r"); //opens csv file
  if (f==NULL){
    printf("%s is empty or does not exist \n", filename);
    printf("Program Exited \n");
    exit(1); //terminates with error if file is empty
  }
  while(fscanf(f, "%s", entry)==1){
     while (*entry == *tempName && tempName != '\0'){ //checking if current entry matches input name
       if(*(entry+1) == ',' && *(tempName+1)== '\0'){ //if vaule at current inidice of entry and name is ',', set temp to ','
        temp=*(entry+1);
      }
      entry++, tempName++, counter++;
    }
    if(temp == ','){ //if current entry matches input name, temp will be ','
      while(*(entry-counter) != '\0'){
        *pointerToRecord=*(entry-counter);
        entry++, pointerToRecord++;
        nameExist=1; //set boolean nameExist to 1
      }
      temp='0'; //reset temp so it doesn't stay as ','
    }
  }
  if(nameExist==0){ //is nameExist is false or 0, show error message and *name=NULL signals main to return 0
    printf("%s does not exist in %s \n",name,filename );
    printf("Program Exited \n");
    *name=NULL;
  }
}

void replace(char *name, char *newname, char record[]){
  int counterNewName=0;
  int counterName=0;
  char *pointerToRecord = record;
  int counter=0;

  for(; *(name+counterName) != '\0'; counterName++){} //counter number of char is name
  for(; *(newname+counterNewName) != '\0'; counterNewName++){} //counter number of char is newname

  if(counterNewName>counterName){ //if newname is longer than original name
    while (*(record) != '\0') {
      record++,counter++;
    }
    for(int i=counter-counterName+1; i>0; i--){ //from end of record, shift content back to accomedate new longer name
      *(record+counterNewName-counterName)=*(record);
      record--;
    }
    for(int i=0; i<counterNewName; i++){ //from front of record array, insert newname over (old) name
      *(pointerToRecord+i)=*(newname+i);
    }
  }
  if(counterName>counterNewName){ //if newname shorter than old name
    for(int i=0; i<counterNewName; i++){ //from front of recrod array, insert newname
      *(pointerToRecord+i)=*(newname+i);
    }
    while(*(record+counterName) != '\0'){ //front end of newname, shift up content by overwriting (old) name
      *(record+counterNewName)=*(record+counterName);
      record++;
    }
    while(*(record+counterNewName) != '\0'){ //put in \0 in remaining array indicies that was previouly occupied by old content
      *(record+counterNewName)='\0';
      record++;
    }
  }

  if(counterName==counterNewName){ //write newname over old name
    for(int i=0; i<counterNewName; i++){
      *(pointerToRecord+i)=*(newname+i);
    }
  }
}


void saveRecord(char *filename, char *name, char record[]){
  FILE *f = fopen(filename, "r"); //opens cvs file
  if (f==NULL){ //if file is empty, exit
    printf("%s is empty or does not exist \n", filename);
    printf("Program Exited \n");
    exit(1);
  }
  FILE *fReplica = fopen("replica.csv", "w"); //create and open flie replica.csv

  char *contactName= calloc(256,sizeof(char));
  char *age= calloc(256,sizeof(char));
  char *phoneNumber= calloc(256,sizeof(char));
  char ch;
  char temp;
  int counter=0;
  char *entry = malloc(sizeof(char)*256);

  while(fscanf(f, "%s", entry)==1){ //scanf each line of file to variable entry
     while (*entry == *name && *name != '\0'){ //checks if current line corresponds to name
        temp=*(entry+1);
        entry++, name++, counter++;
      }
      if(temp == ','){ //if this is name's entry, write  content from record array into second file
      fprintf(fReplica,"\n%s",record); //called replica.csv
      temp=0;
    }
    else{
      fprintf(fReplica, "\n%s", entry); //write the line read into second file, replica.csv
    }
  }
  fclose(f);
  fclose(fReplica); //close both files
  remove(filename);
  rename("replica.csv", filename); //rename replica.csv to filenme

  f = fopen(filename, "r"); //prints out contents of new file
  ch = getc(f);
  while (ch != EOF){
    printf("%c ", ch);
    ch = getc(f);
  }
  printf("Done");
}

int main (void){

char *name; //create variables
name = calloc(256,sizeof(char)); //malloc space for user inputs

char *newname;
newname = calloc(256,sizeof(char));

char *filename;
filename = calloc(256,sizeof(char));
char record[1000];

if(name==NULL)printf("Name is null, program exited \n");
if(filename==NULL)printf("Filename is null, program exited \n");
if(newname==NULL)printf("Newname is null, program exited \n");

printf("Enter the filename: ");
scanf("%s", filename);

printf("Enter the name you want to replace: ");
scanf("%s", name);

printf("Enther the new name: ");
scanf("%s", newname);


findRecord(filename, name, record);
if(*name==NULL){ //if *name is NULL, name does not exist in file, program terminates
  return 0;
}
replace(name, newname, record);

saveRecord(filename, name, record);

return 0;
}
