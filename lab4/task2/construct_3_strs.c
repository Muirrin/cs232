#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation
    struct node* next;
} node_t;

node_t * construct_3_strs() {
  node_t* x;
  node_t* y;
  node_t* z;

  //Allocate three Node pointees and store references to them in the three pointers.
  x=malloc(sizeof(node_t));
  y=malloc(sizeof(node_t));
  z=malloc(sizeof(node_t));

  //Dereference each pointer to store the appropriate number into the value field in its pointee.
  x->value = "CS232";
  y->value = "is";
  z->value = "awesome!";
  //Dereference each pointer to access the .next field in its pointee,
  //and use pointer assignment to set the .next field to point to the appropriate Node.


  x->next = y;
  y->next = z;
  z->next = x;

  return x;
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
    	printf("failed");
	return -1;
    } else {
        return 0;
    }
}
