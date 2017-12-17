#include <stdio.h>
#include <string.h>

int main (void){

char phrase [1000]; //initialize space for user input in array called phrase
char encryptPhrase[1000]; //initialize space for encryted phrase
char decryptPhrase[1000]; //initialize space for decrypted phrase
int key;

printf("Phrase: "); //prompt user for phrase to be encrypted
fgets(phrase, 999, stdin);  //accepts user input - use fgets since scanf only accepts one input without spcae

printf("Key: "); //prompt for key
scanf("%d", &key);

printf("Original phrase: %s", phrase);

int i=0; //counter used to sequencially traverse array
int length = strlen(phrase); //save length of input

while (i<length){  //while loop takes each character of input and shifts left by 'key' amount
  if(phrase[i]>=65 && phrase[i]<=90){ //encrypt is uppercase
    int letter = phrase[i] -'A';
    int newLetter='A' + ((letter - key%26)+26)%26;
    encryptPhrase[i]=newLetter;
  }

  else if(phrase[i]>=97 && phrase[i]<=122){ //encrypt lower case
    int letter= phrase[i] - 'a';
    int newLetter='a' + ((letter - key%26)+26)%26;
    encryptPhrase[i]=newLetter;
  }

  else{
    encryptPhrase[i]=phrase[i]; //if character was not a letter, place directly in encrypted phrase
  }
  i++;
}

printf("Encypted phrase: %s", encryptPhrase);

i=0; //reset i to 0

while (i<length){ //loop decrypts phrase
  if(encryptPhrase[i]>=65 && phrase[i]<=90){  //decrypts uppercaes letters
    int letter= encryptPhrase[i] - (int) 'A';
    int newLetter= (int) 'A' + ((letter + key%26)+26)%26;
    decryptPhrase[i]=newLetter;
  }

  else if(encryptPhrase[i]>=97 && encryptPhrase[i]<=122){ //decrypt lowercase
    int letter= encryptPhrase[i] - (int) 'a';
    int newLetter= (int) 'a' + ((letter + key%26)+26)%26;
    decryptPhrase[i]=newLetter;
  }
  else{
    decryptPhrase[i]=encryptPhrase[i];
  }
  i++;
}

printf("Decyrpted phrase: %s", decryptPhrase); //print decrypted phrase

return 0;
}
