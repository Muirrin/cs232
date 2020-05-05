#include <stdio.h>
#include "snode.h"
// global variables (data segment)

struct snode *n1, *n2, *n3, *p, *temp;

void printer(void* print){
  char * str = (char*)(print);
  int s = strlen(str);
  printf("str: %s - length: %ld\n", str, s);

}
//------------ MY MAIN FUNCTION --------------------

int main(int argc, void *argv[]) {

  // create snodes
  // TODO: modify func calls to snode_create
  // to match with new prototypes.
  n1 = snode_create("hello", strlen("hello"));
  n2 = snode_create("there",strlen("there"));
  n3 = snode_create("prof",strlen("prof"));

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
    printer(p->data); // TODO
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
