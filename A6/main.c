#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
  FILE *r;

  void producer();
  void consumer();

  r= fopen("TURN.txt", "wt");
  if(r==NULL){
    printf("Problem opening TURN.txt \n");
    exit(1);
  }

  fprintf(r, "0");
  fclose(r);

  int pid=fork();

  if(pid==0){producer(); wait(NULL);} //parent
  if(pid!=0){consumer(); wait(NULL);} //child
  if(pid==-1){exit(1);} //wait for consumer to end

  return 0;
}
