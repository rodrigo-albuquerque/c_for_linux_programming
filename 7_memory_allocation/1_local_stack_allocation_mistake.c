#include <stdio.h>
/*
 * As allocation is local to plus function, the memory address returned where *p points to is deallocated.
 * It can still return the correct value, but there's no guarantee as memory can be overwritten or re-allocated to something else.
            plus(1,2)         return &c            printf("%d\n",*p)

(main)         |  (main)         |  (main)            |  (main)
.---.----.     |  .---.----.     |  .---.----.        |  .---.----.
| p |  .-+-X   |  | p |  .-+-X   |  | p |  .-+---.    |  | p |  .-+---.
'---'----'     |  '---'----'     |  '---'----'   |    |  '---'----'   |
               | -------------   | ------------  |    |               |
               |  (plus)         |  (plus)       |    |               |
               |  .---.---.      |  .---.---.    |    |               |
               |  | a | 1 |      |  | a | 1 |    |    |               |
               |  |---|---|      |  |---|---|    |    |               |
               |  | b | 2 |      |  | b | 2 |    |    |               |
               |  |---|---|      |  |---|---|    |    |               |
               |  | c | 3 |      |  | c | 3 | <--'    |            X--'
               |  '---'---'      |  '-------'

                c exists locally    returning a reference       When p is dereferenced
                in plus()           to c assined to p           it points to unallocated memory
 *
 * All locally declared variables in plus() are deallocated once plus() returns.
 * So by the time printf() is called, p is already dereferenced.
 */

int * plus(int a, int b) {
  int c = a + b;
  return &c; // returns reference to locally declared c
}

int main(int argc, char * argv[]) {
  int * p = plus(1,2);
  printf("%d\n", *p);
}


