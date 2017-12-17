#include<stdio>
#include<stdlib>

struct Member{
  char username[30];
  char password[30];
  char groupname[30];
}

struct systemOperator{
  char username[30];
  char password[30];
  int securityLevel;
}

union user{
  struct member;
  struct systemOperator;
}
