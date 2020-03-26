#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from task2
    //TODO:copy setup func from task1
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

void teardown(node_t *head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
    free(head->next->next->next);
    free(head->next->next);
    free(head->next);
    free(head);


}

void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2


        //TODO: implement add to add a new node to front, pointed by head
        node_t * insertedNode;
        insertedNode = malloc(sizeof(node_t));
        insertedNode->length = length;
        insertedNode->next = *head;
        *head = insertedNode;
          strcpy(insertedNode->str,str);

        /*insertedNode->next =(head->next);
        head->next = head->next->next;
        head->next->next = NULL;*/

}
void delete_node_at(node_t ** head, int idx) {
  //stores the head node

  node_t * temp = *head;

  //if head node is at the index we want to remove

  if(idx==0){

    *head = temp->next;

    free(temp);

  }

  else{

    // previous node of the node that we want to delete

       for (int i=0; temp!=NULL && i<idx-1; i++)

            temp = temp->next;



       // temp->next is the node to be deleted

       //stores pointer of the next of node that will be deleted

       node_t *next = temp->next->next;

       free(temp->next);

       temp->next = next;

  }

}
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete.
/*
 int bool = 1;
 node_t * temp = *head;
 node_t *prev = NULL;
  if(strcmp(temp->str,key)==0){
    *head = temp->next;
    free(temp);
  }
  else{
    while(bool==1){
      prev = temp;
      temp = temp->next;
    if(strcmp(temp->str,key)==0)
   {
      bool--;
    }
  }
  prev->next = temp->next;
  free(temp);
  }
*/

node_t * temp  = *head;
node_t * prev  = NULL;

if(temp != NULL && strcmp(temp->str,key)==0)
{
    *head = temp->next;
    free(temp);
    return;
}
else{
while (temp != NULL)
{
    if (strcmp(temp->str,key)==0)
    {
        prev->next = temp->next;
        free(temp);
        return;
    }
    prev = temp;
    temp = temp->next;
}
}


}
//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
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
