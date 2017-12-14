#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>


void producer(){

  char c=48; //ascii '0'
  char num;
  FILE *q;
  FILE *r; //TURN
  FILE *p; //DATA

  q=fopen("mydata.txt", "r");
  if(q==NULL){
    printf("Cannot open mydata.txt");
    exit(1);
    }

  while(!feof(q)){
    r= fopen("TURN.txt", "r");
    if(r==NULL){
      printf("Cannot open TURN.txt in producer 1! \n");
      exit(1);
    }

    fseek(r, 0, SEEK_SET);
    num  = fgetc(r);

  //printf("%d \n", num );
    while(num==49){ //ascii '1'
      num=fgetc(r);
    }

  //printf("%d is num at strat of prod \n", atoi(&num) );
    if(num==48){ //ascii for '0'
      fclose(r);

      c=fgetc(q); //char from mydata

      p=fopen("DATA.txt", "r+");
        if(p==NULL){
          printf("Cannot open DATA.txt \n");
          exit(1);
        }

      fprintf(p, "%c", c); //prints char from mydata to DATA
      fclose(p);

      r=fopen("TURN.txt", "w+"); //recreate TURN.txt and populate with '1'
      if(r==NULL){
        printf("Cannot recreate TURN.txt in producer 2 \n");
        exit(1);
      }

      fseek(r, 0, SEEK_SET);
      fprintf(r, "1"); //print 1 in DATA to signal consumer wwwwwwwwwHER HER HERE
      fclose(r);
    //printf("%d is the character being transferred \n",c );
    }
    if(c==10 || c==-1){
      break;
    }
  }

  r=fopen("TURN.txt", "w+"); //recreate TURN.txt and populate with '1'
  if(r==NULL){
    printf("Cannot recreate TURN.txt in producer 2 \n");
    exit(1);
  }

  fseek(r, 0, SEEK_SET);
  fprintf(r, "9"); //print 1 in DATA to signal consumer wwwwwwwwwHER HER HERE
  fclose(r);
  printf("prod done \n");
}
