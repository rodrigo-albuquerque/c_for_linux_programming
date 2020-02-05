#include <stdio.h>
#include <stdlib.h>
/*
 *  The way to declare a double array with asymetric length is by using this:
 *  char * strings[] ...
 *  strings is a pointer that references a pointer to a char, i.e. an array of strings or a double array.
                                          .---.---.---.---.
                           .---.  _.----> | G | o |   | N |...  <-- strings[0][0], strings[0][1], etc.
  strings ---> .---. _---> | --+-'        '---'---'---'---'
               | --+-'     |---|          .---.---.---.---.
               |---|       | --+--------> | B | e | a | t |...  <-- strings[1][0], strings[1][1], etc.
                           |---|          '---'---'---'---'
                           | --+-._       .---.---.---.---.
                           |---|   '----> | C | r | a | s |...  <-- strings[2][0], strings[2][1], etc.
                           | --+-._       '---'---'---'---'
                           '---'   '._    .---.---.---.---.
                                      '-> | D | e | s | t |...  <-- strings[3][0], strings[3][1], etc.
                                          '---'---'---'---'
 */
int main(int argc, char *argv[]) {
  char * strings[] = { "Go Navy!",
                       "Beat Army!",
                       "Crash Airforce!",
                       "Destroy the Irish!"
                     };
  int i;

  printf("strings: %p\n",strings);
  printf("*strings: %p\n",*strings);
  for (i=0; i<4; i++) {
    printf("strings[%d] is an array of pointers that points to: '%s' %p\n",i,strings[i],strings[i]);
  }
  printf("strings[0][0]: '%c' %p\n",strings[0][0],&strings[0][0]);
  printf("strings[0][1]: '%c' %p\n",strings[0][1],&strings[0][1]);
  printf("strings[0][2]: '%c' %p\n",strings[0][2],&strings[0][2]);
  printf("strings[0][3]: '%c' %p\n",strings[0][3],&strings[0][3]);
  printf("strings[0][4]: '%c' %p\n",strings[0][4],&strings[0][4]);
  printf("strings[0][5]: '%c' %p\n",strings[0][5],&strings[0][5]);
  printf("strings[0][6]: '%c' %p\n",strings[0][6],&strings[0][6]);
  printf("strings[0][7]: '%c' %p\n",strings[0][7],&strings[0][7]);
  printf("strings[0][8]: '%c' %p\n",strings[0][8],&strings[0][8]);
  printf("strings[1][0]: '%c' %p\n",strings[1][0],&strings[1][0]);
}
