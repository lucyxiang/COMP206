void saveRecord(char *filename, char *name, char record[]){
  FILE *f = fopen(filename, "r");
  FILE *fReplica = fopen("replica.csv", "w+");
  if (f==NULL) exit(1); //terminates with error
  int counter=0;

  while (fgets(buffer, sizeof(buffer), f) !=NULL){
    fprintf(fReplica, "%s", buffer);
  }

  while(!feof(f)){
    fscanf(f, "%s", entry);
     while (*entry == *name){
          temp=*(entry);
        entry++, name++, counter++;
        }

        if(temp == ','){
          record=entry;
          printf("%s\n",record );
          break;
          }


          if(counterNewName>counterName){
            while (*(record) != '\0') {
              record++,
            }
            while(*(record+counter) != *(newname+counterNewName)){
              *(record+counter+counterNewName)=*(record+counter);
              record--;
            }
            for(; counter<counterNewName; counter++){
              *(pointerToRecord+counter)=*(newname+counter);
          }
        }




          while (*newname != '\0') {
                *pointerToRecord=*newname;
                pointerToRecord++, newname++;
            }

            /*for(; counter<counterNewName; counter++){
              *(pointerToRecord+counter)=*(newname+counter);
          }*/
          }
          else{

          }
          record=pointerToRecord;
