#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* encrypte(char *message, int key){
  char *letter;
  letter = message;

  for (int i=0; i<strlen(message); i++){
    if(*letter >=97 && *letter <=122){
      *letter = (*letter - 97 - key + 26)%26 + 97;
      //printf("%s\n", letter);
    }
    else if (*letter >=65 && *letter <=90){
      *letter = (*letter - 65 - key + 26)%26 + 65;
    }
    letter++;
  }
  //printf("%s\n", message);
  return message;
}

int main(){
  char buffer[100];
  char* message;
  char* encryptedMessage;
  char* decryptedMessage;
  int key;
  int negKey;

  printf("Message: ");
  scanf("%s", buffer);
  printf("Key: ");
  scanf("%d", &key);

  message=buffer;
  printf("Original message: %s\n", buffer);

  encryptedMessage=encrypte(message, key);
  printf("Encripted message: %s\n", encryptedMessage);

  negKey=key*(-1);
  decryptedMessage=encrypte(encryptedMessage, negKey);
  printf("decryptedMessage: %s\n", decryptedMessage);
}
