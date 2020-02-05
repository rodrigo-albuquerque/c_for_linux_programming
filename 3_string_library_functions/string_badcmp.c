#include <stdio.h>
#include <stdlib.h>
/*
 * if (str == "Navy" ) checks if str and Navy  are stored in the same place in memory
 * So typing Navy would always trigger "else" statement
 * To confirm this is the case, please move to string_badequals.c
 */
int main(int argc, char *argv[]) {
  char str[20];

  printf("Enter 'Navy' for a secret message:\n");
  scanf("%s", str);

  if (str == "Navy") {
    printf("Go Navy! Beat Army!\n");
  } else {
    printf("No secret for you.\n");
  }
}
