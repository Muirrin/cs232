#include "slist.h"
#include "snode.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * Allocates new slist dynamically.
 *
 * @return pointer to the list
 */
struct slist *slist_create(){
  struct slist *ptr;
  ptr  = (struct slist*)malloc(sizeof(struct slist));
  return ptr;
}
/**
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, char *str){

    struct snode * new = NULL;
    new = snode_create(str);

  struct snode * last = l->back;
    l->back = new;
    last->next = new;
    return new;

}
/**
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str){

  struct snode *new = NULL;
  new = snode_create(str);

  if(l->front == NULL){
    l->front = new;
  }

  else{
    struct snode *temp = l->front;
    l->front = new;
    new->next = temp;
  }
  return new;
  /*  temp = l->front;
    l->front = new;
    new->next = temp;
  while(temp->next != NULL)
  {

    temp = last;
    last = last‐>next;

  }
  new = l->back;
  new = new->next;
  strcpy(new->str, str);


  return l->front;
  */
}
/**
 * Returns the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, char *str){
  struct snode *temp = (struct snode*)malloc(sizeof(struct snode));
  temp = l->front;
do{
  if(strcmp(temp->str,str)==0)
  {
      return temp;
  }
}while(temp->next != NULL);
return NULL;
}
/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){
  struct snode *n1 = (struct snode*)malloc(sizeof(struct snode));
  n1 = l->front;
  struct snode *n2 = (struct snode*)malloc(sizeof(struct snode));

  while(n1!=NULL){
    n2 = n1->next;
    free(n1);
    n1=n2;
  }
  l->front = NULL;
}
/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
  struct snode *temp = (struct snode*)malloc(sizeof(struct snode));
  temp = l->front;

while(temp != NULL){

        printf("%s\n", temp->str);
        temp = temp->next;
}
}
/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
  struct snode *temp = (struct snode*)malloc(sizeof(struct snode));
  temp = l->front;
  int len = 0;
  while(temp != NULL){

          len++;
          temp = temp->next;
  }
  return len;
}
/**
 * Deletes the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
void slist_delete(struct slist *l, char *str){

  struct snode *temp = (struct snode*)malloc(sizeof(struct snode));
  temp = l->front;

while(temp != NULL){
    if(strcmp(temp->str,str)==0)
    {
      free(temp);
    }
  }

}
