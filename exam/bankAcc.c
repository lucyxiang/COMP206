#include<stdlib.h>
#include<string.h>

union accountType{
  struct savingsAccount{
    int account_number;
    int balance;
  };
  struct checkingAccount{
    int account_number;
    int balance;
    int withdrawl_fee;
  };
}
