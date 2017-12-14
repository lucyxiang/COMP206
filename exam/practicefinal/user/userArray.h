#ifndef USERARRAY_H
#define USERARRAY_H

union user{
  struct member{
    char *user_name;
    char *password;
    char *group_name;
  } member;
  struct system_operator{
    char *user_name;
    char *password;
    int security_level;
  } system_operator;
};

#endif
