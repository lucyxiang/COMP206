#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"userArray.h"

union user* buildUserArray (int totalUsers){
  union user* user_array;
  user_array = (union user *) calloc(totalUsers, (sizeof(union user)));
  if(user_array==NULL){
    printf("There was an error allocating memory \n");
    exit(1);
  }
  return user_array;
}

union user* populateUserArray(int totalUsers){
  FILE *inFile;
  char *ptr1, *ptr2;
  char line[100];
  union user* user_array;

  user_array= buildUserArray(totalUsers);
  inFile= fopen("user.csv", "rt");
  if(inFile==NULL){
    printf("Error while opening user.csv \n");
    exit(1);
  }

  for(int numUser=0; numUser<totalUsers; numUser++){
    union user* this_user=user_array+numUser;

    fgets(line,99,inFile);
    ptr1=strtok(line, ",");

    if(strcmp(ptr1, "S")!=0){
      ptr1=strtok(NULL, ",");
      this_user->member.user_name = ptr1;
      ptr1=strtok(NULL, ",");
      this_user->member.password = ptr1;
      ptr1=strtok(NULL, ",");
      this_user->member.group_name = ptr1;

      printf("%d. Member's username is %s\n", numUser, this_user->member.user_name);
      printf("%d. Member's password is %s\n", numUser,this_user->member.password);
      printf("%d. Member's group name is %s\n", numUser,this_user->member.group_name);
    }
    if(strcmp(ptr1, "M")!=0){
      ptr1=strtok(NULL, ",");
      this_user->system_operator.user_name = ptr1;
      ptr1=strtok(NULL, ",");
      this_user->system_operator.password = ptr1;
      ptr1=strtok(NULL, ",");
      this_user->system_operator.security_level = atoi(ptr1);

      printf("%d. System Opertor's username is %s\n", numUser, this_user->system_operator.user_name);
      printf("%d. System Opertor's password is %s\n", numUser,this_user->system_operator.password);
      printf("%d. System Opertor's securty level is %d\n", numUser,this_user->system_operator.security_level);
    }
  }

  return user_array;
}

int main(){
  int totalUsers;
  union user* array;
  printf("Enter the number of users: ");
  scanf("%d", &totalUsers);

  array= populateUserArray(totalUsers);

  return 0;
}
