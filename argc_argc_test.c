
#include <stdio.h>

int main(int argc, char * argv[]) {
  printf("argc (number of arguments) = %d: \n", argc);
  for (int i = 0; i < argc; i++) {
    printf("argv (argument passed to your program): %s\n", argv[i]);
  }
}
