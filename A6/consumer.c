#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void consumer(){
  FILE *q; //DATA.txt
  FILE *r; //TURN.txt
  char c; //char being prnited to screen
  char turn;  //'0' for producer and '1 for 'consumer'

do{
  do{
    r = fopen("TURN.txt", "rt");
    if(r==NULL){
      printf("Cannot open TURN.txt in consumer1 \n");
      exit(1);
    }

    turn = getc(r);
    fclose(r);

    if(turn =='9') break;
  }while(turn!='1');

  q = fopen("DATA.txt", "rt"); //\incase erro when opening
  c = fgetc(q);
  putchar(c); //prints to screen
  fclose(q);

  r=fopen("TURN.txt", "wt"); //delete and recreate TURN.txt and populate with '0'
  if(r==NULL){
    printf("Cannot recreate TURN.txt in producer 2 \n");
    exit(1);
  }
  fputc('0', r);
  fclose(r);

}while(turn!='9');
}
