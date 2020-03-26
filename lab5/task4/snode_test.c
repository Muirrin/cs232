#include <stdio.h>
#include "snode.h"
// global variables (data segment)

struct snode *n1, *n2, *n3, *p, *temp;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create snodes
  // TODO: modify func calls to snode_create
  // to match with new prototypes.
  n1 = snode_create("hello");
  n2 = snode_create("there");
  n3 = snode_create("prof");

  printf("snode_test running...\n");

  // manually "link" the nodes together.
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  // p points to node n1 initially
  p = n1;

  while (p != NULL) {
    // Complete this line to print the current node's string and
    // length (you can use strlen!)
    printf("str: %s - length: %ld\n", p->str, strlen(p->str)); // TODO
    // TODO: add code to move p to point to next node
    // until you add this line, this program will have an infinite loop.
    p = p->next;
    }
    p = n1;
  while(p!=NULL){
    temp = p;
    p = p->next;
    snode_destroy(temp);
  }

  return 0;
}
