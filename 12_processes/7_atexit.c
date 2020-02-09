#include <stdio.h>
#include <stdlib.h>

/*
 *  exit() function perform actions before executing final _exit().
 *  However, what if we want to add an additional cleaning-up step in-between?
 *  We can do that with exit handlers.
 *  Exit handlers are functions that are automatically called when a program calls exit().
 *  We can use 32 exit handlers using atexit() library function.
 *  The other of execution is in reverse order of their registration.
 *  The below program will print the following:
 *  2nd exit handler
 *  1st exit handler
 */

void exit_handler1() {
  printf("1st exit handler\n");
}

void exit_handler2() {
  printf("2nd exit handler\n");
}

int main() {
  // exit handlers execute in reverse order of registration
  atexit(exit_handler1);
  atexit(exit_handler2);
  //exit_handler2 will first
  return(0); // implicitly calls exit()
}




