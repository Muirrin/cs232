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
  ptr->front =NULL;
  ptr->back=NULL;
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
//creates new node, sets temp to the front node
struct snode * new = snode_create(str);
 struct snode * temp = l->back;
 if(l->front == NULL){
   l->front = new;
   l->back = new;
 }
 else if(l->back == NULL){
   l->front = new;
   l->back = new;
 }
 else{
   temp->next = new;
   l->back = new;
 }

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
    l->back = new;
  }
  else if(l->back == NULL){
    l->front = new;
    l->back = new;
  }
  else{
    struct snode *temp = l->front;
    new->next = temp;
    l->front = new;
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
  struct snode *temp;
  temp = l->front;
do{
  if(strcmp(temp->str,str)==0)
  {
      return temp;
  }
  temp = temp->next;
}while(temp != NULL);
return NULL;
}
/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){
  struct snode * temp = l->front;
  while(l->front!= NULL){
    temp = l->front;
    l->front = temp->next;
    snode_destroy(temp);
  //l->front = NULL;
}
free(l);
}
/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
  struct snode *temp;
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
  struct snode *temp;
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

  struct snode * temp  = l->front;
  struct snode * prev  = NULL;

  if(temp != NULL && strcmp(temp->str,str)==0)
  {
      l->front = temp->next;
      snode_destroy(temp);
      if(l->front == NULL){
        l->back = NULL;
      }
      return;
  }
  else{
  while (temp != NULL)
  {
      if (strcmp(temp->str,str)==0)
      {

              prev->next = temp->next;
              snode_destroy(temp);
              return;
      }
      prev = temp;
      temp = temp->next;

  }
  }
}

struct snode * slist_get_front(struct slist *l){
  struct snode * temp  = l->front;
  return temp;
}
struct snode * slist_get_back(struct slist *l){
  if(l==NULL){
    return NULL;
  }
  struct snode * temp  = l->back;
  return temp;
}

char * snode_get_str(struct snode * a){
  char *s = a->str;
  return s;
}

struct snode * snode_get_next(struct snode * a){
    struct snode * temp  = a->next;
  return temp;
}
