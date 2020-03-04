#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    node_t * head;
    node_t * node2;
    node_t * node3;
    //Allocate three node pointees and store references to them in the three pointers
    head =malloc(sizeof(node_t));
    node2=malloc(sizeof(node_t));
    node3=malloc(sizeof(node_t));
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee
    head ->length = 5;
    node2->length = 5;
    node3->length = 4;
    strcpy(head->str, "hello");
    strcpy(node2->str, "there");
    strcpy(node3->str, "prof");

    //Dereference each pointer to access the .next field in its pointee,
    //and use pointer assignment to set the .next field to point to the appropriate Node.

    head->next = node2;
    node2->next = node3;
    node3->next = NULL;

   return head;

}

void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
      //node_t * temp;
      free(head->next->next);
      free(head->next);
      free(head);
    /*
    Scrap Work
    temp = head->next;
     head = head->next;
     free(temp);
     temp = head->next->next;
     head = head->next->next;
     free(temp);
     temp= head->next->next->next;
     head = head->next->next->next;
     free(temp);
    free(temp);
    temp = head->next->next;
    free(temp);
    temp= head->next->next->next;
    free(temp);

    free(head->next->str);
    free(head->next->next->str);
    free(head->next->next->next->str);

    free(node1);
    free(node2);
    free(node3);*/

    //Please complete the prototype of teardown.
    //You are not allowed to use globals
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
