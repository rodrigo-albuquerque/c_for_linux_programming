#include <stdio.h>
#include <stdlib.h>

/*
 *  There are cases where we want to keep track of which pairs hav been set and which have not.
 *  Can we look at the array of pairs and work it out?
 *  No, because calloc() will zero out all pairs and we can't tell the difference between a pair set/not set.
 *  Also, if we want to be more memory efficient by allocating pairs on demand?
 *  We can add a double pointer.
 *  Instead of having an array of pairt's, we'd have an array of pointers to pair_t's.
 *  This way we know if pair_t has been set or not because pointer will be either NULL or reference a pair_t.
 *  We can then allocate new pair_t's as needed.
 *                         POINTER    ARRAY of POINTERS  left right
 *                           .---.         .---.         .---..---.
 *                      p--> | .-+-------> | .-+-------> | 2 | 10 |
 *                           |---|         |---|         |---|----|
 *                                         | .-+-------> |   |    |
 *                                         |---|         |---|----|
 *                                           .
 *                                           .
 *                                           .
 *                                        .---.         .---..---.
 *                                        | .-+-------> |   |    |
 *                                        |---|         |---|----|
 *  Here we created 10 "empty" pair_t pointers.
 *  When needed, a new pair is created in sequence.
 */

typedef struct {
  int left;
  int right;
} pair_t;


int main(int argc, char * argv[]) {
  //     .-- Double Pointer -.          array of pair_t pointers
  //     |                   |                      |
  //     v                   v                      v
  pair_t ** pairs = (pair_t **) calloc(10, sizeof(pair_t *));

  pairs[0] = malloc(sizeof(pair_t)); //allocate memory for a new pair_t

  pairs[0]->left  =  2; //do assignment
  pairs[0]->right = 10;
  printf("pairs[0]->left = %d\npairs[0]->right = %d\n", pairs[0]->left,pairs[0]->right);
}
